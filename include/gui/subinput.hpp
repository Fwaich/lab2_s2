#pragma once

#include <wx/wx.h>

class SubInput : public wxDialog {
public:
    SubInput(wxWindow* parent, const wxString& title);

    wxString GetStartIndex() const;
    wxString GetEndIndex() const;

private:
    wxTextCtrl* startInput;
    wxTextCtrl* endInput;
};
