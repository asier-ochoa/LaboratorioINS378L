#include "wx/wx.h"
#include "wx/generic/grid.h"

namespace State {
    char gameBoard[] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    bool player1Turn = true;
    bool previousGameStarter = true;
    std::string p1Name;
    std::string p2Name;
}

bool hasWon() {
    using namespace State;
    for (int i = 0; i < 8; i++){
        char curPiece = gameBoard[i];
        if (curPiece != ' '){
            //Horizontal Check
            if (i % 3 == 0){
                if (gameBoard[i + 1] == curPiece && gameBoard[i + 2] == curPiece){
                    return true;
                }
            }
            //Vertical Check
            if (i / 3 == 0){
                if (gameBoard[i + 3] == curPiece && gameBoard[i + 6] == curPiece){
                    return true;
                }
            }
            if (i == 0){
                if (gameBoard[4] == curPiece && gameBoard[8] == curPiece){
                    return true;
                }
            }
            if (i == 2) {
                if (gameBoard[4] == curPiece && gameBoard[6] == curPiece) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool hasTied() {
    using namespace State;
    for (auto& p : gameBoard){
        if (p == ' ')
            return false;
    }
    return true;
}

bool setPiece(int i){
    using namespace State;
    if (gameBoard[i] != ' ')
        return false;
    gameBoard[i] = (player1Turn ? 'X' : 'O');
    player1Turn = !player1Turn;
    return true;
}

void restartGame(){
    using namespace State;
    previousGameStarter = !previousGameStarter;
    player1Turn = previousGameStarter;
    for (auto& p : gameBoard){
        p = ' ';
    }
}

//UI code below

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

    Bind(wxEVT_BUTTON, [=](wxCommandEvent& event){
        State::p1Name = p1Input->GetValue();
        State::p2Name = p2Input->GetValue();
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

    auto newGameButton = new wxButton(this, NewGameButtonID, "New Game");
    auto statusText = new wxStaticText(this, wxID_ANY, "It's " + (State::player1Turn ? State::p1Name : State::p2Name) + "'s turn");

    for (int i = 0; i < 9; i++){
        gameGrid[i] = new wxButton(this, i, " ");
        gameGrid[i]->SetFont(wxFont(30, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
        layout->Add(gameGrid[i], wxSizerFlags().Expand());
        Bind(wxEVT_BUTTON, [=](wxCommandEvent& event){
            if (setPiece(i)){
                gameGrid[i]->SetLabel(State::gameBoard[i]);
                statusText->SetLabel("It's " + (State::player1Turn ? State::p1Name : State::p2Name) + "'s turn");
            }
            if (hasWon()){
                statusText->SetLabel((!State::player1Turn ? State::p1Name : State::p2Name) + " has won!!");
                newGameButton->Enable();
                for (auto& g: gameGrid){
                    g->Disable();
                }
                return;
            }
            if (hasTied()){
                statusText->SetLabel("Its a Tie!");
                newGameButton->Enable();
                for (auto& g: gameGrid){
                    g->Disable();
                }
            }
        }, i);
    }

    newGameButton->Disable();
    topBarLayout->Add(newGameButton, wxALIGN_CENTER);
    topBarLayout->Add(statusText, 0, wxLEFT | wxALIGN_CENTER_VERTICAL, 5);

    Bind(wxEVT_BUTTON, [=](wxCommandEvent& event){
        restartGame();
        for (auto& g: gameGrid){
            g->SetLabel(' ');
            g->Enable();
        }
        statusText->SetLabel("It's " + (State::player1Turn ? State::p1Name : State::p2Name) + "'s turn");
        newGameButton->Disable();
    }, NewGameButtonID);
}