#include "wx/wx.h"
#include "wx/generic/grid.h"

class MyApp: public wxApp{
    public:
        virtual bool OnInit();
};

class PlayerDialog: public wxDialog{
    public:
        PlayerDialog(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                     long style, const wxString &name);
};


class MyFrame: public wxFrame{
    public:
        MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    private:
        wxButton* gameGrid[9];
};

enum {
    ConfirmButtonID = 10,
    NewGameButtonID = 11
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    auto playerDialog = new PlayerDialog(nullptr, wxID_ANY, "Tic Tac Toe", wxDefaultPosition, wxDefaultSize, 0, "m");
    playerDialog->Show(true);
    return true;
}

PlayerDialog::PlayerDialog(wxWindow* parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size, long style, const wxString &name)
        : wxDialog(parent, id, title, pos, size, style, name){
    auto mainLayout = new wxBoxSizer(wxHORIZONTAL);
    this->SetSizer(mainLayout);

    auto p1Layout = new wxBoxSizer(wxVERTICAL);
    mainLayout->Add(p1Layout, 0, 0, 50);
    auto p1Text = new wxStaticText(this, wxID_ANY, "Player 1 Name (X)");
    auto p1Input = new wxTextCtrl(this, wxID_ANY, "P1");
    p1Layout->Add(p1Text, 0, wxALL, 5);
    p1Layout->Add(p1Input, 0, wxALL, 5);

    auto p2Layout = new wxBoxSizer(wxVERTICAL);
    mainLayout->Add(p2Layout, 0, wxLEFT, 5);
    auto p2Text = new wxStaticText(this, wxID_ANY, "Player 2 Name (O)");
    auto p2Input = new wxTextCtrl(this, wxID_ANY, "P2");
    p2Layout->Add(p2Text, 0, wxALL, 5);
    p2Layout->Add(p2Input, 0, wxALL, 5);

    auto confirmButton = new wxButton(this, ConfirmButtonID, "Confirm");
    p1Layout->Add(confirmButton, 0, wxALL, 5);

    this->SetSize(this->GetEffectiveMinSize());

    Bind(wxEVT_BUTTON, [this](wxCommandEvent& event){
        this->Close();
        auto frame = new MyFrame( "Tic Tac Toe", wxDefaultPosition, wxSize(500, 500) );
        frame->Show(true);
    }, ConfirmButtonID);
}

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(nullptr, wxID_ANY, title, pos, size){
    auto mainLayout = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(mainLayout);

    auto topBarLayout = new wxBoxSizer(wxHORIZONTAL);
    mainLayout->Add(topBarLayout, 0, wxALL | wxALIGN_CENTER, 10);

    auto layout = new wxGridSizer(3, 3, wxSize(0, 0));
    mainLayout->Add(layout, 1, wxEXPAND | wxTOP, 0);

    for (int i = 0; i < 9; i++){
        gameGrid[i] = new wxButton(this, i, "O");
        gameGrid[i]->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        layout->Add(gameGrid[i], wxSizerFlags().Expand());
        Bind(wxEVT_BUTTON, [=](wxCommandEvent& event){
            std::cout << "X:" << i % 3 << " Y:" << i / 3 << '\n';
        }, i);
    }

    auto newGameButton = new wxButton(this, NewGameButtonID, "New Game");
    newGameButton->Disable();
    topBarLayout->Add(newGameButton, wxALIGN_CENTER);
    auto statusText = new wxStaticText(this, wxID_ANY, "STATUS MY G");
    topBarLayout->Add(statusText, 0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5);
}