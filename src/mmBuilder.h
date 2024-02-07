#ifndef MMBUILDER_H
#define MMBUILDER_H

#include <wx/string.h>
#include <wx/textctrl.h>

#include "mmFrame2.h"


class mmBuilder
{
    public:
        mmBuilder(wxDialog* parent);
        virtual ~mmBuilder();

        void InitButton(void);
        void InitFrame(void);
        void SetButton(void);
        void SetFrame(void);
        void ShowFrame(void);

        void SetDimHor(int val) { DimHor = val; }
        void SetDimVer(int val) { DimVer = val; }
        void SetPosHor(int val) { PosHor = val; }
        void SetPosVer(int val) { PosVer = val; }
        void SetText1(wxString val) { Text1=val; }
        void SetText2(wxString val) { Text2=val; }

    protected:

    private:
        wxButton* mmButton[100];
        wxTextCtrl* TextCtrl1[100];
        int nbu;
        int nte;
        int nla;

        int DimHor;
        int DimVer;
        int PosHor;
        int PosVer;
        wxString Text1;
        wxString Text2;

        wxPanel* Panel1;
        mmFrame2* Frame1;
        wxDialog* main;
};

#endif // MMBUILDER_H
