/***************************************************************
 * Name:      mmodaMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    AF (andrea202511@gmail.com)
 * Created:   2024-01-26
 * Copyright: AF ()
 * License:
 **************************************************************/

#include "mmodaMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(mmodaDialog)
#include <wx/intl.h>
#include <wx/string.h>
//*)

mmodaDialog* mainDlg;

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(mmodaDialog)
const long mmodaDialog::ID_BUTTON3 = wxNewId();
const long mmodaDialog::ID_BUTTON1 = wxNewId();
const long mmodaDialog::ID_BUTTON2 = wxNewId();
const long mmodaDialog::ID_TEXTCTRL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mmodaDialog,wxDialog)
    //(*EventTable(mmodaDialog)
    //*)
END_EVENT_TABLE()

mmodaDialog::mmodaDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(mmodaDialog)
    Create(parent, id, _("MModa"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE|wxVSCROLL|wxALWAYS_SHOW_SB, _T("id"));
    SetClientSize(wxSize(230,284));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Button3 = new wxButton(this, ID_BUTTON3, _("Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer1->Add(Button3, 0, wxALL|wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 1, wxALL|wxEXPAND, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxEXPAND, 4);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(0,200), wxTE_MULTILINE|wxVSCROLL|wxHSCROLL|wxALWAYS_SHOW_SB, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    BoxSizer1->Add(TextCtrl1, 1, wxALL|wxEXPAND, 4);
    SetSizer(BoxSizer1);
    FileDialogXml = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, _("*.*"), wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
    Layout();

    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mmodaDialog::SelectXmlFile);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mmodaDialog::OnAbout);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mmodaDialog::OnQuit);
    //*)

    Builder=new mmBuilder(this);
    AboutDialog = new mmAbout(this);

}

mmodaDialog::~mmodaDialog()
{
    //(*Destroy(mmodaDialog)
    FileDialogXml->Destroy();
    //*)
}

void mmodaDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void mmodaDialog::OnAbout(wxCommandEvent& event)
{
  AboutDialog->ShowModal();
}

void mmodaDialog::SelectXmlFile(wxCommandEvent& event)
{
    if (FileDialogXml->ShowModal() == wxID_OK)
    {
        XmlFileName =FileDialogXml->GetPath();
		LoadFileXml();
    }

}

void mmodaDialog::AddLog(wxString msg)
{
  TextCtrl1->AppendText(msg);
}

