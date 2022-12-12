#include <optional>
#include "wx/wx.h"
#include "wx/valnum.h"

struct VirtualCanvas{
    // Coordinates are +X left and +Y down
    bool buff[2000][2000];

    void clear(){
        for (auto& p: buff) {
            for (auto& pp: p) {
                pp = false;
            }
        }
    }

    VirtualCanvas() {
        clear();
    }

    void DrawPixel(int x, int y){
        if (x < 2000 && y < 2000 && x > 0 && y > 0){
            buff[x][y] = true;
        }
    }

    void DrawLine(int x1, int y1, int x2, int y2){
        float x;
        float y;
        float dx, dy, step;

        dx = (x2 - x1);
        dy = (y2 - y1);
        if (abs(dx) >= abs(dy))
            step = abs(dx);
        else
            step = abs(dy);
        dx = dx / step;
        dy = dy / step;
        x = x1;
        y = y1;
        int i = 1;
        for (int i = 1; i <= step; i++) {
            DrawPixel(x, y);
            x += dx;
            y += dy;
        }
    }

    void DrawCircle(int x, int y, int r, bool filled = false){
        static float step = 0.1;
        if (filled){
            for (float i = 0; i < 180; i += 0.1){
                DrawLine(x + cos(-i * M_PI / 180) * r, y + sin(-i * M_PI / 180) * r, x + (cos(i * M_PI / 180) * r), y + (sin(i * M_PI / 180) * r));
            }
        } else {
            for (float i = 0; i < 360; i += 0.1){
                DrawPixel(x + (cos(i * M_PI / 180) * r), y + (sin(i * M_PI / 180) * r));
            }
        }
    }

};

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
        VirtualCanvas vc;

        void Draw(wxPaintEvent& evt);
};

Canvas::Canvas(wxWindow *parent, wxWindowID id)
    :wxPanel(parent, id) {}

void Canvas::Draw(wxPaintEvent &evt) {
    wxPaintDC dc(this);
    std::cout << "X: " << dc.GetSize().x << " Y: " << dc.GetSize().y << '\n';

    for (int x = 0; x < dc.GetSize().x; x++){
        for (int y = 0; y < dc.GetSize().y; y++){
            dc.SetPen(wxPen(vc.buff[x][y] ? wxColour(0, 0, 0, 255) : wxColour(255, 255, 255, 255)));
            dc.DrawPoint(x, y);
        }
    }
}

enum {
    canvasID = 1
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

    auto button = new wxButton(this, wxID_ANY, "Reset");
    topLayout->Add(button, 0, wxALL, 10);

    auto checkBox = new wxCheckBox(this, wxID_ANY, "Filled");
    topLayout->Add(checkBox, 0, wxALL, 10);

    wxIntegerValidator<int> validator;
    validator.SetMin(0);
    validator.SetMax(1000);
    auto radiusCtrl = new wxTextCtrl(this, wxID_ANY, "100", wxDefaultPosition, wxDefaultSize, 0, validator);
    topLayout->Add(radiusCtrl, 0, wxALL, 10);

    auto canvas = new Canvas(this, canvasID);
    layout->Add(canvas, 100, wxEXPAND);

    button->Bind(wxEVT_BUTTON, [=](auto& evt){
            canvas->vc.clear();
            canvas->Refresh();
    }, wxID_ANY);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);
    canvas->Bind(wxEVT_LEFT_UP, [=](wxMouseEvent& evt){
        canvas->vc.DrawCircle(evt.GetPosition().x, evt.GetPosition().y, atoi(radiusCtrl->GetValue()), checkBox->GetValue());
        canvas->Refresh();
    }, canvasID);

    button->SetLabel("Reset");
}
