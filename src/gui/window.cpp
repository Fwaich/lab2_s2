#include "gui/window.hpp"
#include "core/Adapter.h"
#include "core/IntAdapter.h"
#include "core/Sequence.h"
#include "core/ArraySequence.h"
#include "core/ListSequence.h"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "WX"){

    wxSize screenSize = wxGetDisplaySize();
    int frameWidth = screenSize.GetWidth() / 2;
    int frameHeight = screenSize.GetHeight() / 2;
    wxPoint framePosition(screenSize.GetWidth() / 2, 0);
    SetSize(framePosition.x, framePosition.y, frameWidth, frameHeight);


    wxMenu* menuStruct = new wxMenu; 
    menuStruct->Append(wxID_ANY, "Dynamic Array");
    menuStruct->Append(wxID_ANY, "Linked List");
    menuStruct->Append(wxID_ANY, "Const Dynamic Array");
    menuStruct->Append(wxID_ANY, "Const Linked List");

    wxMenu* menuType = new wxMenu; 
    menuType->Append(wxID_ANY, "Int");
    menuType->Append(wxID_ANY, "Double");
    menuType->Append(wxID_ANY, "String");
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuStruct, "&Struct");
    menuBar->Append(menuType, "&Type");
 
    SetMenuBar( menuBar );
 
    // int_seq = new ArraySequence<int>();
    a = new IntAdapter(new ArraySequence<int>());

    wxPanel* panel = new wxPanel(this);

    inputField = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(10, 10));
    displayBox = new wxListBox(panel, wxID_ANY, wxPoint(10, 50), wxSize(945, 200));

    new wxButton(panel, ID_Append, "Append", wxPoint(170, 10));
    new wxButton(panel, ID_Prepend, "Prepend", wxPoint(270, 10));
    new wxButton(panel, ID_Set, "Set", wxPoint(370, 10));
    new wxButton(panel, ID_Get, "Get", wxPoint(470, 10));
    new wxButton(panel, ID_GetFirst, "Get First", wxPoint(570, 10));
    new wxButton(panel, ID_GetLast, "Get Last", wxPoint(670, 10));
    new wxButton(panel, ID_GetSize, "Get Size", wxPoint(770, 10));
    new wxButton(panel, ID_GetSub, "Get Sub", wxPoint(870, 10));

    Bind(wxEVT_BUTTON, &MyFrame::OnAppend, this, ID_Append);
    Bind(wxEVT_BUTTON, &MyFrame::OnPrepend, this, ID_Prepend);
    Bind(wxEVT_BUTTON, &MyFrame::OnSet, this, ID_Set);

    Bind(wxEVT_BUTTON, &MyFrame::OnGet, this, ID_Get);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetFirst, this, ID_GetFirst);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetLast, this, ID_GetLast);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetSize, this, ID_GetSize);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetSub, this, ID_GetSub);
    
    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
 }
 
void MyFrame::OnAppend(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    a->append(value);
    UpdateDisplay();
}

void MyFrame::OnPrepend(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    a->prepend(value);
    UpdateDisplay();
}

void MyFrame::OnSet(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    a->prepend(value);
    UpdateDisplay();
}

void MyFrame::OnGet(wxCommandEvent& event)
{
    // std::string value = a->prepend(value);
    UpdateDisplay();
}


void MyFrame::OnGetFirst(wxCommandEvent& event)
{
    std::string value = a->get_first();
    wxMessageBox(value, "First Member", wxOK | wxICON_NONE, this);
}

void MyFrame::OnGetLast(wxCommandEvent& event)
{
    std::string value = a->get_last();
    wxMessageBox(value, "Last Member", wxOK | wxICON_NONE, this);
}

void MyFrame::OnGetSize(wxCommandEvent& event)
{
    std::string value = a->get_size();
    wxMessageBox(value, "Size Of Struct", wxOK | wxICON_NONE, this);
}

void MyFrame::OnGetSub(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    a->prepend(value);
}

void MyFrame::UpdateDisplay()
{
    displayBox->Clear();
    // for (int i = 0; i < int_seq->get_size(); i++){
    //     int element = int_seq->get(i);
    //     displayBox->Append(std::to_string(element));
    // }
    std::string output = a->to_string();
    displayBox->Append(output);
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    delete a;
    Close(true);
}

