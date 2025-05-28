#include "gui/window.hpp"
#include "core/Adapter.h"
#include "core/IntAdapter.h"
#include "core/DoubleAdapter.h"
#include "core/StringAdapter.h"
#include "core/Sequence.h"
#include "core/ArraySequence.h"
#include "core/ListSequence.h"

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "WX") {

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

    wxMenuBar* menuBar = new wxMenuBar;
    menuBar->Append(menuStruct, "&Struct");
    menuBar->Append(menuType, "&Type");
    SetMenuBar(menuBar);

    current_struct = ARRAY;
    current_type = INT;
    seq = new IntAdapter(new ArraySequence<int>);
    
    panel = new wxPanel(this);

    structInfo = new wxStaticText(panel, wxID_ANY, "Current struct: Array");
    typeInfo = new wxStaticText(panel, wxID_ANY, "Current type: Int");

    wxBoxSizer* infoBox = new wxBoxSizer(wxHORIZONTAL);
    infoBox->Add(structInfo, 0, wxLEFT, 5);
    infoBox->Add(typeInfo, 0, wxLEFT, 10);

    inputField = new wxTextCtrl(panel, wxID_ANY, "");
    displayBox = new wxTextCtrl(
        panel, wxID_ANY, "",
        wxDefaultPosition, wxDefaultSize,
        wxTE_MULTILINE | wxTE_READONLY | wxTE_RICH | wxTE_WORDWRAP
    );

    wxPanel* buttonPanel = new wxPanel(panel);
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);

    wxBoxSizer* getsBox = new wxBoxSizer(wxVERTICAL);
    getsBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Gets"), 0, wxALL, 5);
    getsBox->Add(new wxButton(buttonPanel, ID_Get, "Get"), 0, wxALL, 5);
    getsBox->Add(new wxButton(buttonPanel, ID_GetFirst, "Get First"), 0, wxALL, 5);
    getsBox->Add(new wxButton(buttonPanel, ID_GetLast, "Get Last"), 0, wxALL, 5);
    getsBox->Add(new wxButton(buttonPanel, ID_GetSize, "Get Size"), 0, wxALL, 5);

    wxBoxSizer* setsBox = new wxBoxSizer(wxVERTICAL);
    setsBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Sets"), 0, wxALL, 5);
    setsBox->Add(new wxButton(buttonPanel, ID_Set, "Set"), 0, wxALL, 5);
    setsBox->Add(new wxButton(buttonPanel, ID_Append, "Append"), 0, wxALL, 5);
    setsBox->Add(new wxButton(buttonPanel, ID_Prepend, "Prepend"), 0, wxALL, 5);

    wxBoxSizer* subsBox = new wxBoxSizer(wxVERTICAL);
    subsBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Subs"), 0, wxALL, 5);
    subsBox->Add(new wxButton(buttonPanel, ID_GetSub, "Get Subsequence"), 0, wxALL, 5);
    subsBox->Add(new wxButton(buttonPanel, ID_ShowSub, "Show Subsequence"), 0, wxALL, 5);

    wxBoxSizer* funcsBox = new wxBoxSizer(wxVERTICAL);
    funcsBox->Add(new wxStaticText(buttonPanel, wxID_ANY, "Funcs"), 0, wxALL, 5);
    funcsBox->Add(new wxButton(buttonPanel, ID_Map, "Map"), 0, wxALL, 5);

    hbox->Add(getsBox, 1, wxEXPAND | wxALL, 10);
    hbox->Add(setsBox, 1, wxEXPAND | wxALL, 10);
    hbox->Add(subsBox, 1, wxEXPAND | wxALL, 10);
    hbox->Add(funcsBox, 1, wxEXPAND | wxALL, 10);

    buttonPanel->SetSizer(hbox);

    //expand - перпердекулярно, proportion - вдоль оси сайзера
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    mainSizer->Add(infoBox, 0, wxALL, 10);
    mainSizer->Add(new wxStaticText(panel, wxID_ANY, "Target Value:"), 0, wxTOP | wxLEFT, 10);
    mainSizer->Add(inputField, 0, wxEXPAND | wxALL, 10);
    mainSizer->Add(displayBox, 1, wxEXPAND | wxALL, 10); 
    mainSizer->Add(buttonPanel, 0, wxEXPAND | wxALL, 10);

    panel->SetSizer(mainSizer);
    panel->Layout();

    Bind(wxEVT_BUTTON, &MyFrame::OnAppend, this, ID_Append);
    Bind(wxEVT_BUTTON, &MyFrame::OnPrepend, this, ID_Prepend);
    Bind(wxEVT_BUTTON, &MyFrame::OnSet, this, ID_Set);

    Bind(wxEVT_BUTTON, &MyFrame::OnGet, this, ID_Get);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetFirst, this, ID_GetFirst);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetLast, this, ID_GetLast);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetSize, this, ID_GetSize);
    Bind(wxEVT_BUTTON, &MyFrame::OnGetSub, this, ID_GetSub);
    Bind(wxEVT_BUTTON, &MyFrame::OnShowSub, this, ID_ShowSub);
    Bind(wxEVT_BUTTON, &MyFrame::OnMap, this, ID_Map);

    Bind(wxEVT_MENU, &MyFrame::OnExit, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MyFrame::OnSelectStructArray, this, ID_Struct_Array);
    Bind(wxEVT_MENU, &MyFrame::OnSelectStructList, this, ID_Struct_List);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeInt, this, ID_Type_Int);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeDouble, this, ID_Type_Double);
    Bind(wxEVT_MENU, &MyFrame::OnSelectTypeString, this, ID_Type_String);
}
