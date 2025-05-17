#pragma once
#include <wx/wx.h>
#include "core/Adapter.h"

enum {
   ID_Append,
   ID_Prepend,
   ID_Set,
   ID_Get,
   ID_GetFirst,
   ID_GetLast,
   ID_GetSize,
   ID_GetSub,
};

enum DataType {ARRAY, LIST};
enum SequenceType {INT, DOUBLE, STRING};

class MyFrame : public wxFrame {
private:

   Adapter* a = nullptr;

   wxTextCtrl* inputField;
   wxListBox* displayBox;

   void OnExit(wxCommandEvent& event);

   void OnAppend(wxCommandEvent& event);
   void OnPrepend(wxCommandEvent& event);
   void OnSet(wxCommandEvent& event);
   void OnGet(wxCommandEvent& event);
   void OnGetFirst(wxCommandEvent& event);
   void OnGetLast(wxCommandEvent& event);
   void OnGetSize(wxCommandEvent& event);
   void OnGetSub(wxCommandEvent& event);

   void UpdateDisplay();

public:

   MyFrame();

};