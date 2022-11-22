#include "wx/wx.h"
#include "wx/generic/grid.h"

class MyApp: public wxApp
{
    public:
        virtual bool OnInit();
};
class MyFrame: public wxFrame
{
    public:
        MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    protected:

    private:
        void OnHello(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        wxDECLARE_EVENT_TABLE();
};
enum
{
    ID_Hello = 1,
    ID_fuck = 3
};


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(ID_Hello,   MyFrame::OnHello)
EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(MyApp);

void fuck(wxCommandEvent& event);
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame( "Hello World", wxPoint(50, 50), wxSize(450, 340) );
    frame->Show( true );
    return true;
}
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
    auto* button = new wxButton(this, wxID_ANY, "WOOW");
    button->Connect(wxEVT_BUTTON, fuck);
//    auto* table = new wxGrid(this, wxID_ANY);
//    table->CreateGrid(20,4);
//    table->SetRowSize()
}

void fuck(wxCommandEvent& event){
    std::cout << "FUCK\n";
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}