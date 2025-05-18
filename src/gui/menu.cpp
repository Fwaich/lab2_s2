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
    if (a != nullptr) delete a;

    if (current_type == INT) {
        if (current_struct == ARRAY)
            a = new IntAdapter(new ArraySequence<int>());
        else
            a = new IntAdapter(new ListSequence<int>());
    }
    else if (current_type == DOUBLE) {
        if (current_struct == ARRAY)
            a = new DoubleAdapter(new ArraySequence<double>());
        else
            a = new DoubleAdapter(new ListSequence<double>());
    }
    else if (current_type == STRING) {
        if (current_struct == ARRAY)
            a = new StringAdapter(new ArraySequence<std::string>());
        else
            a = new StringAdapter(new ListSequence<std::string>());
    }

    UpdateDisplay();
}

void MyFrame::OnSelectStructArray(wxCommandEvent& event)
{
    current_struct = ARRAY;
    std::cout << "aa" << std::endl;
    RecreateAdapter();
}

void MyFrame::OnSelectStructList(wxCommandEvent& event)
{
    current_struct = LIST;
    RecreateAdapter();
}

void MyFrame::OnSelectTypeInt(wxCommandEvent& event)
{
    current_type = INT;
    RecreateAdapter();
}

void MyFrame::OnSelectTypeDouble(wxCommandEvent& event)
{
    current_type = DOUBLE;
    RecreateAdapter();
}

void MyFrame::OnSelectTypeString(wxCommandEvent& event)
{
    current_type = STRING;
    RecreateAdapter();
}


void MyFrame::OnExit(wxCommandEvent& event)
{
    delete a;
    Close(true);
}

