#pragma once
#include <wx/wx.h>
#include "core/Adapter.h"

enum MenuIDs {
   ID_Struct_Array = 101,
   ID_Struct_List,
   ID_Type_Int,
   ID_Type_Double,
   ID_Type_String
};


enum ButtonIDs {
   ID_Append = 201,
   ID_Prepend,
   ID_Set,
   ID_Get,
   ID_GetFirst,
   ID_GetLast,
   ID_GetSize,
   ID_GetSub,
};

enum StructType {ARRAY, LIST};
enum DataType {INT, DOUBLE, STRING};

class MyFrame : public wxFrame {
private:

   StructType current_struct = ARRAY;
   DataType current_type = INT;
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

   void OnSelectStructArray(wxCommandEvent& event);
   void OnSelectStructList(wxCommandEvent& event);
   void OnSelectTypeInt(wxCommandEvent& event);
   void OnSelectTypeDouble(wxCommandEvent& event);
   void OnSelectTypeString(wxCommandEvent& event);

   void UpdateDisplay();
   void RecreateAdapter();

public:

   MyFrame();

};