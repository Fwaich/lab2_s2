#include "gui/window.hpp"
#include "core/ArraySequence.h"
#include "core/ListSequence.h"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "WX"){

    wxSize screenSize = wxGetDisplaySize();
    int frameWidth = screenSize.GetWidth() / 2;
    int frameHeight = screenSize.GetHeight() / 2;
    wxPoint framePosition(screenSize.GetWidth() / 2, 0);
    SetSize(framePosition.x, framePosition.y, frameWidth, frameHeight);


    wxMenu* menuFile = new wxMenu; 
    menuFile->Append(ID_Hello, "dsald", "help in statusbar");
    menuFile->Append(ID_Array, "Create an array", "ligmabows");
 
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
 
    Bind(wxEVT_MENU, &MyFrame::OnHello, this, ID_Hello);
    Bind(wxEVT_MENU, &MyFrame::OnCreateArray, this, ID_Array);
    Bind(wxEVT_MENU, &MyFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
 }
 
 void MyFrame::OnExit(wxCommandEvent& event)
 {
     Close(true);
 }
  
 void MyFrame::OnAbout(wxCommandEvent& event)
 {
     wxMessageBox("This is a wxWidgets Hello World example",
                  "About Hello World", wxOK | wxICON_INFORMATION);
 }
  
 void MyFrame::OnHello(wxCommandEvent& event)
 {
     wxLogMessage("Hello world from wxWidgets!");
 }

void MyFrame::OnCreateArray(wxCommandEvent& event)
{
    int arr[] {1, 2, 3, 4};
    Sequence<int>* seq = new ListSequence<int>(arr, 4);
    wxPuts(seq->to_string());

    delete seq;
}