#ifndef MMSETTING_H
#define MMSETTING_H

//(*Headers(mmSetting)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)



/*
class IpValidator : public wxTextValidator
{
public:
	IpValidator() : wxTextValidator(wxFILTER_INCLUDE_LIST)
	{
		wxString ipchars[11] =
		{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "." };
		wxArrayString as(11, ipchars);
		SetIncludes(as);
	}

	IpValidator(const IpValidator& other) : wxTextValidator(other)
	{
		// copy your internal data from 'other'
	}

	virtual wxObject* Clone() const wxOVERRIDE
	{
		return new IpValidator();
	}

	virtual bool TransferToWindow() wxOVERRIDE
	{
		if ( checkDash(*m_stringValue) )
			return wxTextValidator::TransferToWindow();
		else
			return false;
	}
	virtual bool TransferFromWindow(void) wxOVERRIDE
	{
		wxTextCtrl* control = (wxTextCtrl*)m_validatorWindow;
		const wxString& tempString = control->GetValue();
		if ( checkDash(tempString) )
			return wxTextValidator::TransferFromWindow();
		else return false;
	}

protected:
	bool checkDash(const wxString& str)
	{
		if ( str.Len() >= 3 )
			return false;
		else return true;
	}

private:
	wxDECLARE_DYNAMIC_CLASS_NO_ASSIGN(IpValidator);
};

*/
class mmSetting: public wxDialog
{
    public:

        mmSetting(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~mmSetting();

        //(*Declarations(mmSetting)
        wxCheckBox* CheckBox1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        //*)

        wxString ip_addr;
        int port;
        int refresh;
        bool comm_enable;

    protected:

        //(*Identifiers(mmSetting)
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL2;
        static const long ID_CHECKBOX1;
        //*)

    private:

        //(*Handlers(mmSetting)
        void OnTextCtrl2Text(wxCommandEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
