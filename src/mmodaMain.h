/***************************************************************
 * Name:      mmodaMain.h
 * Purpose:   Defines Application Frame
 * Author:    AF (andrea202511@gmail.com)
 * Created:   2024-01-26
 * Copyright: AF ()
 * License:
 **************************************************************/

#ifndef MMODAMAIN_H
#define MMODAMAIN_H

//(*Headers(mmodaDialog)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/filedlg.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
//*)

#include "mmBuilder.h"
#include "mmAbout.h"

class mmodaDialog: public wxDialog
{
    public:

        mmodaDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~mmodaDialog();

		wxString XmlFileName;
		void LoadFileXml(void);

		void AddLog(wxString msg);


    private:

        mmBuilder* Builder;
        mmAbout* AboutDialog;


        //(*Handlers(mmodaDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void SelectXmlFile(wxCommandEvent& event);
        //*)

        //(*Identifiers(mmodaDialog)
        static const long ID_BUTTON3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL1;
        //*)

        //(*Declarations(mmodaDialog)
        wxBoxSizer* BoxSizer1;
        wxBoxSizer* BoxSizer2;
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxFileDialog* FileDialogXml;
        wxTextCtrl* TextCtrl1;
        //*)


        DECLARE_EVENT_TABLE()
};


#endif // MMODAMAIN_H
