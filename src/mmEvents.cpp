#include <wx/button.h>
#include <wx/panel.h>
#include <wx/textctrl.h>

#include "mmodaMain.h"


extern mmodaDialog* mainDlg;

void OnPressButton(wxMouseEvent& event)
{
    int id;
     event.Skip(true);
     id=event.GetId();

     wxString st;
     st.Printf("Pressed %i\n",id);
    mainDlg->AddLog(st);
//    mmoda_01Dialog::Logga(st);
}

void OnReleaseButton(wxMouseEvent& event)
{
    int id;
     event.Skip(true);
     id=event.GetId();

     wxString st;
     st.Printf("Released %i\n",id);
    mainDlg->AddLog(st);

}

void TextEnter(wxCommandEvent& event)
{
    int id;
     event.Skip(true);
     id=event.GetId();

     wxString st;
     st.Printf("text_entered %i\n",id);
    mainDlg->AddLog(st);

}
