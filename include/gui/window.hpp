#pragma once
#include <wx/wx.h>

enum {
   ID_Hello,
   ID_Array
};

class MyFrame : public wxFrame {
private:

   void OnHello(wxCommandEvent& event);
   void OnExit(wxCommandEvent& event);
   void OnAbout(wxCommandEvent& event);
   void OnCreateArray(wxCommandEvent& event);

public:

   MyFrame();

};