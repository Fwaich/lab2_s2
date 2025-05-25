#include "gui/subinput.hpp"

SubInput::SubInput(wxWindow* parent, const wxString& title)
    : wxDialog(parent, wxID_ANY, title, wxDefaultPosition, wxSize(300, 200))
{
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Start index:"), 0, wxALL, 5);
    startInput = new wxTextCtrl(this, wxID_ANY);
    mainSizer->Add(startInput, 0, wxEXPAND | wxALL, 5);

    mainSizer->Add(new wxStaticText(this, wxID_ANY, "End index:"), 0, wxALL, 5);
    endInput = new wxTextCtrl(this, wxID_ANY);
    mainSizer->Add(endInput, 0, wxEXPAND | wxALL, 5);

    wxSizer* buttonSizer = CreateSeparatedButtonSizer(wxOK | wxCANCEL);
    mainSizer->Add(buttonSizer, 0, wxEXPAND | wxALL, 10);

    startInput->SetFocus();

    SetSizerAndFit(mainSizer);
}

wxString SubInput::GetStartIndex() const {
    return startInput->GetValue();
}

wxString SubInput::GetEndIndex() const {
    return endInput->GetValue();
}
