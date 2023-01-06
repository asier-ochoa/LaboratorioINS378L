//ENUNCIADO:
//Hacer un programa que muestre un triangulo de sierpinski
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399
//FECHA: 28/12/22

#include <memory>
#include "wx/wx.h"

std::vector<std::array<std::pair<float, float>, 3>> triangles;
int step = 0;

void nextStep() {
    if (triangles.empty()){
        triangles.push_back({std::make_pair(0, 0), std::make_pair(-0.5,1), std::make_pair(0.5,1)});
        step++;
    } else {
        //Create 2 copies of the current triangle
        std::vector<std::array<std::pair<float, float>, 3>> currTriangleLeft(triangles);
        std::vector<std::array<std::pair<float, float>, 3>> currTriangleRight(triangles);
        //Offset Left
        for (auto& t: currTriangleLeft){
            for (auto& p: t){
                p.first -= pow(2, step) / 4;
                p.second += pow(2, step) / 2;
            }
        }
        //Offset Right
        for (auto& t: currTriangleRight){
            for (auto& p: t){
                p.first += pow(2, step) / 4;
                p.second += pow(2, step) / 2;
            }
        }
        // Insert new triangles
        triangles.insert(triangles.end(), currTriangleLeft.begin(), currTriangleLeft.end());
        triangles.insert(triangles.end(), currTriangleRight.begin(), currTriangleRight.end());

        step++;
    }
}

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
        bool filled = false;

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

    if (filled) {
        dc.SetBrush(*wxBLACK_BRUSH);
    }
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
    nextID = 3,
    filledID = 4
};

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    auto mainFrame = new Frame(wxDefaultPosition, wxSize(800, 800), wxDEFAULT_FRAME_STYLE, "Sierpinski triangle");
    mainFrame->Show();
    return true;
}

Frame::Frame(const wxPoint &pos, const wxSize &size, long style, const wxString &name)
        : wxFrame(nullptr, wxID_ANY, name, pos, size, style, name) {
    auto layout = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(layout);

    auto topLayout = new wxBoxSizer(wxHORIZONTAL);
    layout->Add(topLayout, 0, wxCENTER | wxALL, 10);

    auto resetButton = new wxButton(this, resetID, "Reset");
    topLayout->Add(resetButton, 0, wxRIGHT, 10);

    auto nextButton = new wxButton(this, nextID, "Next step");
    topLayout->Add(nextButton, 0, wxRIGHT, 10);

    auto filledToggle = new wxCheckBox(this, filledID, "Filled");
    topLayout->Add(filledToggle, 0, wxRIGHT | wxALIGN_CENTER_VERTICAL, 10);

    auto canvas = new Canvas(this, canvasID);
    layout->Add(canvas, 100, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);
    resetButton->Bind(wxEVT_BUTTON, [=](auto evt){
        triangles.clear();
        step = 0;
        canvas->Refresh();
    }, resetID);
    nextButton->Bind(wxEVT_BUTTON, [=](auto evt){
        nextStep();
        canvas->Refresh();
    }, nextID);
    filledToggle->Bind(wxEVT_CHECKBOX, [=](auto& evt){
        canvas->filled = filledToggle->GetValue();
        canvas->Refresh();
    }, filledID);
}