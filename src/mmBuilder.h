#ifndef MMBUILDER_H
#define MMBUILDER_H

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>

#include "mmFrame2.h"


class mmBuilder
{
    public:
        mmBuilder(wxDialog* parent);
        virtual ~mmBuilder();

        void InitFrame(void);
        void SetFrame(void);
        void ShowFrame(void);
        void InitButton(void);
        void SetButton(void);
        void InitTextCtrl(void);
        void SetTextCtrl(void);
        void InitStaticText(void);
        void SetStaticText(void);
        void InitStaticBitmap(void);
        void SetStaticBitmap(void);

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
        //ID 1-99 Button
        //ID 101-199 TextCtrl
        //ID 201-299 DinamicText
        //ID 301-399 DinamicIcon
        int func[400];
        int regc[400];
        int par1[400];
        int par2[400];
        int par3[400];

    private:
        wxButton* mmButton[100];
        wxTextCtrl* mmTextCtrl[100];
//        wxDinamicText* mmDinamicText[100];
//        wxDinamicIcon* mmDinamicIcon[100];
        wxStaticText* mmStaticText[100];
        wxStaticBitmap* mmStaticBitmap[100];
        int nbu;
        int ntc;
        int nst;
        int nsb;



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
