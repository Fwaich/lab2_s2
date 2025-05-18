#include "gui/window.hpp"
#include "core/Adapter.h"
#include "core/IntAdapter.h"
#include "core/DoubleAdapter.h"
#include "core/StringAdapter.h"
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
    menuStruct->Append(ID_Struct_Array, "Dynamic Array");
    menuStruct->Append(ID_Struct_List, "Linked List");
    menuStruct->Append(wxID_ANY, "Const Dynamic Array");
    menuStruct->Append(wxID_ANY, "Const Linked List");

    wxMenu* menuType = new wxMenu; 
    menuType->Append(ID_Type_Int, "Int");
    menuType->Append(ID_Type_Double, "Double");
    menuType->Append(ID_Type_String, "String");
 
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuStruct, "&Struct");
    menuBar->Append(menuType, "&Type");
 
    SetMenuBar( menuBar );
 
    a = new DoubleAdapter(new ArraySequence<double>());

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

    Bind(wxEVT_MENU, &MyFrame::OnSelectStructArray, this, ID_Struct_Array);
    Bind(wxEVT_MENU, &MyFrame::OnSelectStructList, this, ID_Struct_List);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeInt, this, ID_Type_Int);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeDouble, this, ID_Type_Double);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeString, this, ID_Type_String);

 }
 


