/***************************************************************
 * Name:      mmodaApp.cpp
 * Purpose:   Code for Application Class
 * Author:    AF (andrea202511@gmail.com)
 * Created:   2024-01-26
 * Copyright: AF ()
 * License:
 **************************************************************/

#include "mmodaApp.h"

//(*AppHeaders
#include "mmodaMain.h"
#include <wx/image.h>
//*)

extern mmodaDialog* mainDlg;

IMPLEMENT_APP(mmodaApp);

bool mmodaApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        mmodaDialog Dlg(0);
        mainDlg=&Dlg;
        SetTopWindow(&Dlg);
        Dlg.ShowModal();
        wxsOK = false;
    }
    //*)
    return wxsOK;

}
