#pragma once
#include <wx/wx.h>

enum {
   ID_Hello = 1
};

class MyFrame : public wxFrame {
private:

   void OnHello(wxCommandEvent& event);
   void OnExit(wxCommandEvent& event);
   void OnAbout(wxCommandEvent& event);

public:

   MyFrame();

};