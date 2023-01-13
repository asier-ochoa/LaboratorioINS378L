//ENUNCIADO:
//Hacer un programa que muestre un triangulo de sierpinski usando el chaos game
//PARTICIPANTES: 1101331 Ochoa Asier; 1072515 Rodoflo Peña; Carlos Ismael Garcia 1101629; 1100685 Miguelangel; Yeuris Terrero 1099399
//FECHA: 28/12/22

#include <memory>
#include "wx/wx.h"
#include "wx/valnum.h"

std::vector<std::pair<float, float>> points;
std::pair<float, float> lastVertex;
std::array<std::pair<float, float>, 3> triangle = {{{0,0},{-0.5,1},{0.5,1}}};

int step = 0;

void nextStep() {
    if (points.empty()){
        //Pick initial random vertex
        lastVertex = {-0.5 + (float)(rand()) / ((float)(RAND_MAX / (0.5 - (-0.5)))), (float)(rand()) / (float)(RAND_MAX)};
    }
    //Roll dice on index
    int index = rand() % (2 + 1);
    points.emplace_back(triangle[index].first + lastVertex.first / 2, triangle[index].second + lastVertex.second / 2);
    lastVertex = points.back();

    step++;
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
    dc.SetPen(wxPen(wxColour(0, 0, 0, 255)));
    dc.SetBackground(wxBrush(wxColour(0xff, 0xff, 0xff, 0xff)));
    dc.Clear();
    static const float minX = -0.5, maxX = 0.5, maxY = 1;

    if (filled) {
        dc.SetBrush(*wxBLACK_BRUSH);
    }
    for (auto [x, y]: points) {
        dc.DrawPoint(INTERPX(x), INTERPY(y));
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
    srand(time(nullptr));
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

    auto iterationsText = new wxStaticText(this, wxID_ANY, "Iterations: ");
    topLayout->Add(iterationsText, 0, wxRIGHT | wxCENTER, 5);

    wxIntegerValidator<int> validator;
    validator.SetMin(0);
    validator.SetMax(50000);
    auto iterationsCtrl = new wxTextCtrl(this, wxID_ANY, "1000", wxDefaultPosition, wxDefaultSize, 0, validator);
    topLayout->Add(iterationsCtrl, 0, wxRIGHT, 10);

    auto canvas = new Canvas(this, canvasID);
    layout->Add(canvas, 100, wxEXPAND | wxBOTTOM | wxLEFT | wxRIGHT, 10);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);
    resetButton->Bind(wxEVT_BUTTON, [=](auto evt){
        points.clear();
        step = 0;
        canvas->Refresh();
    }, resetID);
    nextButton->Bind(wxEVT_BUTTON, [=](auto evt){
        int iters = atoi(iterationsCtrl->GetValue());
        for (int i = 0; i < iters; i++){
            nextStep();
        }
        canvas->Refresh();
    }, nextID);
}