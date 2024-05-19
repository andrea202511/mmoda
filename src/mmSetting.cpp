#include "mmSetting.h"

//(*InternalHeaders(mmSetting)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include <wx/stdpaths.h>

//(*IdInit(mmSetting)
const long mmSetting::ID_STATICLINE1 = wxNewId();
const long mmSetting::ID_STATICTEXT1 = wxNewId();
const long mmSetting::ID_TEXTCTRL1 = wxNewId();
const long mmSetting::ID_TEXTCTRL2 = wxNewId();
const long mmSetting::ID_TEXTCTRL3 = wxNewId();
const long mmSetting::ID_TEXTCTRL4 = wxNewId();
const long mmSetting::ID_STATICTEXT2 = wxNewId();
const long mmSetting::ID_TEXTCTRL5 = wxNewId();
const long mmSetting::ID_STATICLINE2 = wxNewId();
const long mmSetting::ID_CHOICE1 = wxNewId();
const long mmSetting::ID_CHOICE2 = wxNewId();
const long mmSetting::ID_CHOICE3 = wxNewId();
const long mmSetting::ID_STATICBITMAP1 = wxNewId();
const long mmSetting::ID_BUTTON1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(mmSetting,wxDialog)
    //(*EventTable(mmSetting)
    //*)
END_EVENT_TABLE()

mmSetting::mmSetting(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{

    wxIntegerValidator<int16_t> vip1(&ipp1, wxNUM_VAL_THOUSANDS_SEPARATOR);
    vip1.SetMin(1);
    vip1.SetMax(255);
    wxIntegerValidator<int16_t> vip2(&ipp2, wxNUM_VAL_THOUSANDS_SEPARATOR);
    vip2.SetMin(0);
    vip2.SetMax(255);
    wxIntegerValidator<int16_t> vip3(&ipp3, wxNUM_VAL_THOUSANDS_SEPARATOR);
    vip3.SetMin(0);
    vip3.SetMax(255);
    wxIntegerValidator<int16_t> vip4(&ipp4, wxNUM_VAL_THOUSANDS_SEPARATOR);
    vip4.SetMin(0);
    vip4.SetMax(255);
    wxIntegerValidator<int16_t> vpo(&port, wxNUM_VAL_THOUSANDS_SEPARATOR);
    vpo.SetMin(1);
    vpo.SetMax(16000);

    //(*Initialize(mmSetting)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxBoxSizer* BoxSizer3;
    wxBoxSizer* BoxSizer4;
    wxBoxSizer* BoxSizer5;
    wxBoxSizer* BoxSizer6;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxSize(400,400));
    Move(wxDefaultPosition);
    SetMinSize(wxSize(400,400));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    StaticLine1->SetMinSize(wxSize(0,0));
    StaticLine1->SetMaxSize(wxSize(0,0));
    BoxSizer1->Add(StaticLine1, 0, wxALL|wxEXPAND, 2);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("IP:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(40,33), 0, vip1, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMaxLength(3);
    BoxSizer2->Add(TextCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(40,33), 0, vip2, _T("ID_TEXTCTRL2"));
    BoxSizer2->Add(TextCtrl2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(40,33), 0, vip3, _T("ID_TEXTCTRL3"));
    BoxSizer2->Add(TextCtrl3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(40,33), 0, vip4, _T("ID_TEXTCTRL4"));
    BoxSizer2->Add(TextCtrl4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
    BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Port:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    BoxSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(69,33), 0, vpo, _T("ID_TEXTCTRL5"));
    TextCtrl5->SetMaxLength(5);
    BoxSizer3->Add(TextCtrl5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
    StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
    BoxSizer1->Add(StaticLine2, 0, wxALL|wxEXPAND, 5);
    BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    BoxSizer4->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    BoxSizer4->Add(Choice2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Choice3 = new wxChoice(this, ID_CHOICE3, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    BoxSizer4->Add(Choice3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
    BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
    StaticBitmap1 = new wxStaticBitmap(this, ID_STATICBITMAP1, wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_FULL_SCREEN")),wxART_OTHER), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    BoxSizer5->Add(StaticBitmap1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
    BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
    BoxSizer1->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer1->Add(Button1, 0, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&mmSetting::OnButton1Click);
    //*)

    //default setting
    refresh=250;
    comm_enable=true;

    wxString ini_filename = wxStandardPaths::Get().GetUserConfigDir() + wxFileName::GetPathSeparator() + ".mmoda";

    config=new wxFileConfig(wxEmptyString,wxEmptyString,ini_filename);

    long i;
    config->Read("IP_part1",&i,192);
    ipp1=(int16_t)i;
    config->Read("IP_part2",&i,168);
    ipp2=(int16_t)i;
    config->Read("IP_part3",&i,0);
    ipp3=(int16_t)i;
    config->Read("IP_part4",&i,200);
    ipp4=(int16_t)i;
    config->Read("Port",&i,502);
    port=(int16_t)i;

}

mmSetting::~mmSetting()
{
    //(*Destroy(mmSetting)
    //*)
}


void mmSetting::OnButton1Click(wxCommandEvent& event)
{
     long i;
     TransferDataFromWindow();
    i=(long)ipp1;
    config->Write("IP_part1",i);
    i=(long)ipp2;
    config->Write("IP_part2",i);
    i=(long)ipp3;
    config->Write("IP_part3",i);
    i=(long)ipp4;
    config->Write("IP_part4",i);
    i=(long)port;
    config->Write("Port",i);
    config->Flush();

    EndModal(wxID_OK);

}


