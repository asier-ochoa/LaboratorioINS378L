#include <memory>
#include "wx/wx.h"

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

void Canvas::Draw(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    dc.SetBackground(wxBrush(wxColour(0xff, 0xff, 0xff, 0xff)));
    dc.Clear();
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

    auto resetButton = new wxButton(this, wxID_ANY, "Reset");
    topLayout->Add(resetButton, 0, wxRIGHT, 10);

    auto nextButton = new wxButton(this, wxID_ANY, "Next step");
    topLayout->Add(nextButton);

    auto canvas = new Canvas(this, canvasID);
    layout->Add(canvas, 100, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);
    resetButton->Bind(wxEVT_BUTTON, [=](auto evt){
        canvas->triangles.clear();
        canvas->step = 0;
    }, resetID);
    nextButton->Bind(wxEVT_BUTTON, [=](auto evt){
        if (canvas->triangles.empty()){
            canvas->triangles.push_back({std::make_pair(0.5, 0), std::make_pair(1,1), std::make_pair(0,1)});
            canvas->step++;
        } else if(canvas->triangles.size() == 1) {

        } else {
            std::vector<std::array<std::pair<float, float>, 3>> currTriangle(canvas->triangles);
            for (auto& t: currTriangle){
                for (auto& p: t){
                    p.first *= 20;
                }
            }
        }
    }, nextID);
}