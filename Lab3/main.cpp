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
        // Coordinates are +X left and +Y down
        bool** screenBuffer;
        uint16_t xSize, ySize;
        Canvas(wxWindow* parent);

        void Draw(wxPaintEvent& evt);
};

Canvas::Canvas(wxWindow *parent)
    :wxPanel(parent) {
    wxPaintDC dc(this);

    xSize = dc.GetSize().x;
    ySize = dc.GetSize().y;

    screenBuffer = new bool*[xSize];
    for (int i = 0; i < xSize; i++){
        screenBuffer[i] = new bool[ySize];
    }
}

void Canvas::Draw(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    std::cout << "X: " << dc.GetSize().x << " Y: " << dc.GetSize().y << '\n';
    dc.SetBrush(*wxBLACK_BRUSH);
    dc.DrawCircle(wxPoint(0,0), 100);
}

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

    auto button = new wxButton(this, wxID_ANY, "Reset");
    layout->Add(button, 0, wxCENTER | wxALL, 10);

    auto canvas = new Canvas(this);
    layout->Add(canvas, 100, wxEXPAND);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);

    button->SetLabel("Reset");
}
