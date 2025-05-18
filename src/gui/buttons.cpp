#include "gui/window.hpp"

void MyFrame::OnAppend(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    inputField->Clear();
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
    if (a->get_size() == "0") return;
    std::string output = a->to_string();
    displayBox->Append(output);
}