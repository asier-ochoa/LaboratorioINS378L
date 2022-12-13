#include <memory>
#include "wx/wx.h"

#define INTERPX(X) interpRange(minX, maxX, 0, dc.GetSize().x, X)
#define INTERPY(X) interpRange(0, maxY, 0, dc.GetSize().y, X)

class App: public wxApp{
    public:
    private:
        bool OnInit() override;
};

class Frame: public wxFrame{
    public:
        Frame(const wxPoint &pos, const wxSize &size, long style, const wxString &name);
};

class Canvas: public wxPanel{
    public:
        Canvas(wxWindow* parent, wxWindowID id);
        std::vector<std::array<std::pair<float, float>, 3>> triangles;
        int step = 0;

        void Draw(wxPaintEvent& evt);
};

Canvas::Canvas(wxWindow *parent, wxWindowID id)
        :wxPanel(parent, id) {}

//Interpolate from one range to another
float interpRange(float minA, float maxA, float minB, float maxB, float x){
    return minB + ((x - minA) / (maxA - minA)) * maxB;
}

void Canvas::Draw(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    dc.SetBackground(wxBrush(wxColour(0xff, 0xff, 0xff, 0xff)));
    dc.Clear();

    float minX = -pow(2, step) / 4, maxX = abs(minX), maxY = pow(2, step) / 2;

    std::cout << "MinX: " << minX << "MaxY: " << maxY << '\n';

    for (auto& t: triangles){
        wxPoint triangle[] = {
            wxPoint(INTERPX(t[0].first), INTERPY(t[0].second)),
            wxPoint(INTERPX(t[1].first), INTERPY(t[1].second)),
            wxPoint(INTERPX(t[2].first), INTERPY(t[2].second))
        };
        dc.DrawPolygon(3, triangle);
    }
}

enum {
    canvasID = 1,
    resetID = 2,
    nextID = 3
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto mainFrame = new Frame(wxDefaultPosition, wxSize(500, 500), wxDEFAULT_FRAME_STYLE, "Circle Drawing");
    mainFrame->Show();
    return true;
}

Frame::Frame(const wxPoint &pos, const wxSize &size, long style, const wxString &name)
        : wxFrame(nullptr, wxID_ANY, "Circle Drawing", pos, size, style, name) {
    auto layout = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(layout);

    auto topLayout = new wxBoxSizer(wxHORIZONTAL);
    layout->Add(topLayout, 0, wxCENTER | wxALL, 10);

    auto resetButton = new wxButton(this, resetID, "Reset");
    topLayout->Add(resetButton, 0, wxRIGHT, 10);

    auto nextButton = new wxButton(this, nextID, "Next step");
    topLayout->Add(nextButton);

    auto canvas = new Canvas(this, canvasID);
    layout->Add(canvas, 100, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);
    resetButton->Bind(wxEVT_BUTTON, [=](auto evt){
        canvas->triangles.clear();
        canvas->step = 0;
        canvas->Refresh();
    }, resetID);
    nextButton->Bind(wxEVT_BUTTON, [=](auto evt){
        if (canvas->triangles.empty()){
            canvas->triangles.push_back({std::make_pair(0, 0), std::make_pair(-0.5,1), std::make_pair(0.5,1)});
            canvas->step++;
        } else {
            std::vector<std::array<std::pair<float, float>, 3>> currTriangleLeft(canvas->triangles);
            std::vector<std::array<std::pair<float, float>, 3>> currTriangleRight(canvas->triangles);
            for (auto& t: currTriangleLeft){
                for (auto& p: t){
                    p.first -= pow(2, canvas->step) / 4;
                    p.second += pow(2, canvas->step) / 2;
                }
            }
            for (auto& t: currTriangleRight){
                for (auto& p: t){
                    p.first += pow(2, canvas->step) / 4;
                    p.second += pow(2, canvas->step) / 2;
                }
            }
            // Insert new triangles
            canvas->triangles.insert(canvas->triangles.end(), currTriangleLeft.begin(), currTriangleLeft.end());
            canvas->triangles.insert(canvas->triangles.end(), currTriangleRight.begin(), currTriangleRight.end());

            canvas->step++;
        }
        canvas->Refresh();
    }, nextID);
}