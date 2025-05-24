#include "gui/window.hpp"
#include "core/Adapter.h"
#include "core/IntAdapter.h"
#include "core/DoubleAdapter.h"
#include "core/StringAdapter.h"
#include "core/Sequence.h"
#include "core/ArraySequence.h"
#include "core/ListSequence.h"

void MyFrame::RecreateAdapter()
{
    if (seq != nullptr) delete seq;

    if (current_type == INT) {
        if (current_struct == ARRAY)
            seq = new IntAdapter(new ArraySequence<int>());
        else
            seq = new IntAdapter(new ListSequence<int>());
    }
    else if (current_type == DOUBLE) {
        if (current_struct == ARRAY)
            seq = new DoubleAdapter(new ArraySequence<double>());
        else
            seq = new DoubleAdapter(new ListSequence<double>());
    }
    else if (current_type == STRING) {
        if (current_struct == ARRAY)
            seq = new StringAdapter(new ArraySequence<std::string>());
        else
            seq = new StringAdapter(new ListSequence<std::string>());
    }

    UpdateDisplay();
}

void MyFrame::OnSelectStructArray(wxCommandEvent& event)
{
    current_struct = ARRAY;
    RecreateAdapter();
    structInfo->SetLabel("Current struct: Array");
    UpdateLayout();
}

void MyFrame::OnSelectStructList(wxCommandEvent& event)
{
    current_struct = LIST;
    RecreateAdapter();
    structInfo->SetLabel("Current struct: List");
    UpdateLayout();
}

void MyFrame::OnSelectTypeInt(wxCommandEvent& event)
{
    current_type = INT;
    RecreateAdapter();
    typeInfo->SetLabel("Current type: Int");
    UpdateLayout();
}

void MyFrame::OnSelectTypeDouble(wxCommandEvent& event)
{
    current_type = DOUBLE;
    RecreateAdapter();
    typeInfo->SetLabel("Current type: Double");
    UpdateLayout();
}

void MyFrame::OnSelectTypeString(wxCommandEvent& event)
{
    current_type = STRING;
    RecreateAdapter();
    typeInfo->SetLabel("Current type: String");
    UpdateLayout();
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    delete seq;
    Close(true);
}

void MyFrame::UpdateLayout() 
{
    panel->Layout();
    panel->Refresh(); 
}

