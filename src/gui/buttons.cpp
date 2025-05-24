#include "gui/window.hpp"

void MyFrame::OnAppend(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    seq->append(value);
    inputField->Clear();
    inputField->SetFocus();
    UpdateDisplay();
}

void MyFrame::OnPrepend(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    seq->prepend(value);
    inputField->Clear();
    inputField->SetFocus();
    UpdateDisplay();
}

void MyFrame::OnSet(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());

    wxString index_str = wxGetTextFromUser("Enter index", "", "", this);
    long index;
    if (!index_str.ToLong(&index)) {
        wxMessageBox("Error: index must be a number", "Error", wxICON_ERROR);
        return;
    }
    
    seq->set(index, value);
    inputField->Clear();
    inputField->SetFocus();
    UpdateDisplay();
}

void MyFrame::OnGet(wxCommandEvent& event)
{
    wxString index_str = wxGetTextFromUser("Enter index", "", "", this);
    long index;
    if (!index_str.ToLong(&index)) {
        wxMessageBox("Error: index must be a number", "Error", wxICON_ERROR);
        return;
    }

    wxMessageBox(seq->get(index), "Selected member", wxOK | wxICON_NONE, this);
    inputField->SetFocus();
    UpdateDisplay();
}


void MyFrame::OnGetFirst(wxCommandEvent& event)
{
    std::string value = seq->get_first();
    wxMessageBox(value, "First Member", wxOK | wxICON_NONE, this);
    inputField->SetFocus();
}

void MyFrame::OnGetLast(wxCommandEvent& event)
{
    std::string value = seq->get_last();
    wxMessageBox(value, "Last Member", wxOK | wxICON_NONE, this);
    inputField->SetFocus();
}

void MyFrame::OnGetSize(wxCommandEvent& event)
{
    std::string value = seq->get_size();
    wxMessageBox(value, "Size Of Struct", wxOK | wxICON_NONE, this);
    inputField->SetFocus();
}

void MyFrame::OnGetSub(wxCommandEvent& event)
{
    std::string value = std::string(inputField->GetValue());
    seq->prepend(value);
}

void MyFrame::UpdateDisplay()
{
    displayBox->Clear();
    if (seq->get_size() == "0") return;
    std::string output = seq->to_string();
    displayBox->SetValue(output);
}