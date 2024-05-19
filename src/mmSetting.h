#ifndef MMSETTING_H
#define MMSETTING_H

//(*Headers(mmSetting)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include <wx/valnum.h>
#include <wx/fileconf.h>



class mmSetting: public wxDialog
{
    public:

        mmSetting(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
        virtual ~mmSetting();

        //(*Declarations(mmSetting)
        wxButton* Button1;
        wxChoice* Choice1;
        wxChoice* Choice2;
        wxChoice* Choice3;
        wxStaticBitmap* StaticBitmap1;
        wxStaticLine* StaticLine1;
        wxStaticLine* StaticLine2;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrl4;
        wxTextCtrl* TextCtrl5;
        //*)

        int16_t ipp1;
        int16_t ipp2;
        int16_t ipp3;
        int16_t ipp4;
        int16_t port;
        int refresh;
        bool comm_enable;

    protected:

        //(*Identifiers(mmSetting)
        static const long ID_STATICLINE1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT2;
        static const long ID_TEXTCTRL5;
        static const long ID_STATICLINE2;
        static const long ID_CHOICE1;
        static const long ID_CHOICE2;
        static const long ID_CHOICE3;
        static const long ID_STATICBITMAP1;
        static const long ID_BUTTON1;
        //*)




    private:
        wxFileConfig* config;

        //(*Handlers(mmSetting)
        void OnTextCtrl2Text(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnInit(wxInitDialogEvent& event);
        void OnPaint(wxPaintEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnTextCtrl1TextEnter(wxCommandEvent& event);
        //*)

        DECLARE_EVENT_TABLE()
};

#endif
