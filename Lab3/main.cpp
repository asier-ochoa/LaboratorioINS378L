#include <optional>
#include "wx/wx.h"

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

    void DrawPixel(uint16_t x, uint16_t y){
        if (x < 2000 && y < 2000){
            buff[x][y] = true;
        }
    }

    void DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2){
        int slope;
        // swap coords
        if (x2 < x1){
            auto tmp = x1;
            x1 = x2;
            x2 = tmp;

            tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        int dx = x2 - x1;
        int dy = y2 - y1;
        if (dx < dy){
            for (int i = y1; i < y2; i++){
                DrawPixel(x1 + dx * (i - y1) / dy, i);
            }
        } else {
            for (int i = x1; i < x2; i++){
                DrawPixel(i, y1 + dy * (i - x1) / dx);
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
    :wxPanel(parent, id) {
    vc.DrawLine(50, 50, 300, 565);
    vc.DrawLine(50, 50, 300, 51);
}

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

    auto button = new wxButton(this, wxID_ANY, "Reset");
    layout->Add(button, 0, wxCENTER | wxALL, 10);

    auto canvas = new Canvas(this, canvasID);
    layout->Add(canvas, 100, wxEXPAND);

    button->Bind(wxEVT_BUTTON, [=](auto& evt){
            canvas->vc.clear();
            canvas->Refresh();
    }, wxID_ANY);

    canvas->Bind(wxEVT_PAINT, &Canvas::Draw, canvas);
    canvas->Bind(wxEVT_LEFT_UP, [=](wxMouseEvent& evt){
        static std::optional<std::pair<long, long>> state;
        if (state.has_value()) {
            auto pos = evt.GetPosition();
            canvas->vc.DrawLine(state->first, state->second, pos.x, pos.y);
            canvas->Refresh();
            state.reset();
        } else {
            auto pos = evt.GetPosition();
            state = std::make_pair(pos.x, pos.y);
        }
    }, canvasID);

    button->SetLabel("Reset");
}
