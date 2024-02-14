#include <wx/button.h>
#include <wx/panel.h>
#include <wx/textctrl.h>

#include "mmodaMain.h"
#include "mmBuilder.h"


extern mmodaDialog* mainDlg;
extern mmBuilder* build;


void OnPressButton(wxMouseEvent& event)
{
    int id;
     event.Skip(true);
     id=event.GetId();
     build->OnPressBtn(id);

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
     build->OnReleaseBtn(id);

     wxString st;
     st.Printf("Released %i\n",id);
    mainDlg->AddLog(st);

}


void OnTextEnter(wxCommandEvent& event)
{
    int id;
     event.Skip(true);
     id=event.GetId();
     build->OnEnterTxt(id);

     wxString st;
     st.Printf("text_entered %i\n",id);
    mainDlg->AddLog(st);

}
