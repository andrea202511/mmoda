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
        void SetFunc(int val) { Func=val; }
        void SetRegc(int val) { Regc=val; }
        void SetPar1(int val) { Par1=val; }
        void SetPar2(int val) { Par2=val; }
        void SetPar3(int val) { Par3=val; }

        void OnPressBtn(int id);
        void OnReleaseBtn(int id);
        void OnEnterTxt(int id);

    protected:

        int func[200];
        int regc[200];
        int par1[200];
        int par2[200];
        int par3[200];

    private:
        wxButton* mmButton[200];
        wxTextCtrl* TextCtrl1[200];
        int nbu;
        int nte;
        int nla;



        int DimHor;
        int DimVer;
        int PosHor;
        int PosVer;
        wxString Text1;
        wxString Text2;
        int Func;
        int Regc;
        int Par1;
        int Par2;
        int Par3;

        wxPanel* Panel1;
        mmFrame2* Frame1;
        wxDialog* main;
};

#endif // MMBUILDER_H
