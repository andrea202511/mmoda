#ifndef MMFRAME2_H
#define MMFRAME2_H

//(*Headers(mmFrame2)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
//*)



class mmFrame2: public wxDialog
{
    public:

        mmFrame2(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~mmFrame2();

        //(*Declarations(mmFrame2)
        wxButton* Button1;
        wxButton* Button2;
        wxPanel* Panel1;
        //*)

    protected:

        //(*Identifiers(mmFrame2)
        static const long ID_PANEL1;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        //*)

    private:

        //(*Handlers(mmFrame2)
        void OnClose(wxCloseEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
