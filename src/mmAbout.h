#ifndef MMABOUT_H
#define MMABOUT_H

#include "version.h"

#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>


class mmAbout: public wxDialog
{
	public:

		mmAbout(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~mmAbout();

		//(*Declarations(mmAbout)
		wxButton* Button1;
		wxStaticBitmap* StaticBitmap1;
		wxStaticText* StaticText1;
		wxTextCtrl* TextCtrl1;
		wxTextCtrl* TextCtrl2;
		wxTextCtrl* TextCtrl3;
		//*)

	protected:

		//(*Identifiers(mmAbout)
		static const long ID_STATICBITMAP1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_TEXTCTRL3;
		static const long ID_TEXTCTRL1;
		//*)

	private:

		//(*Handlers(mmAbout)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
