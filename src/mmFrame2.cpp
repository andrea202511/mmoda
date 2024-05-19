#include "mmFrame2.h"

#include "mmodaMain.h"
#include "mmBuilder.h"
extern mmBuilder* build;

//(*InternalHeaders(mmFrame2)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(mmFrame2)
const long mmFrame2::ID_PANEL1 = wxNewId();
const long mmFrame2::ID_BUTTON1 = wxNewId();
const long mmFrame2::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mmFrame2,wxDialog)
    //(*EventTable(mmFrame2)
    //*)
END_EVENT_TABLE()

mmFrame2::mmFrame2(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(mmFrame2)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1->Add(Panel1, 1, wxEXPAND, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(this, ID_BUTTON1, _("Button1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 0, wxALL|wxEXPAND, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Button2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 0, wxALL|wxEXPAND, 5);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(BoxSizer1);
    BoxSizer1->SetSizeHints(this);

    Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&mmFrame2::OnClose);
    //*)
}

mmFrame2::~mmFrame2()
{
    //(*Destroy(mmFrame2)
    //*)
}


void mmFrame2::OnClose(wxCloseEvent& event)
{
    build->CloseFrame();
    Destroy();
}
