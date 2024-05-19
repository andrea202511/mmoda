#ifndef MMBUILDER_H
#define MMBUILDER_H

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/statbmp.h>
#include <wx/valnum.h>
#include <wx/timer.h>


#include "mmFrame2.h"

/*
class myDinamicIcon
{
    void SetVal();
    void Refresh();
    int value;
};
*/


class mmBuilder : public wxTimer
{
    public:
        mmBuilder(wxDialog* parent);
        virtual ~mmBuilder();

        void InitFrame(void);
        void SetFrame(void);
        void ShowFrame(void);
        void CloseFrame(void);
        void InitButton(void);
        void SetButton(void);
        void InitTextCtrl(void);
        void SetTextCtrl(void);
        void UpdTextCtrl(int id);
        void InitStaticText(void);
        void SetStaticText(void);
        void InitStaticIcon(void);
        void SetStaticIcon(void);
        void InitDinamicIcon(void);
        void SetDinamicIcon(void);

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

        void AddBitmap(wxString bmp);

        void OnPressBtn(int id);
        void OnReleaseBtn(int id);
        void OnEnterTxt(int id);

    protected:
        //ID 001-099 BuTton
        //ID 101-199 TextCtrl
        //ID 201-299 DinamicText
        //ID 301-399 DinamicIcon

        int func_bt[100];
        int func_tc[100];
        int func_dt[100];
        int func_di[100];
        int posx_di[100];
        int posy_di[100];

        int regc_bt[100];
        int regc_tc[100];
        int regc_dt[100];
        int regc_di[100];

        int par1_bt[100];
        int par1_tc[100];
        int par1_dt[100];
        int par1_di[100];

        int par2_bt[100];
        int par2_tc[100];
        int par2_dt[100];
        int par2_di[100];

        int par3_bt[100];
        int par3_tc[100];
        int par3_dt[100];
        int par3_di[100];

        float flo_tc[100];
        int val_di[100];

        void Notify();


    private:
        wxButton* mmButton[100];
        wxTextCtrl* mmTextCtrl[100];
//        wxDinamicText* mmDinamicText[100];
//        wxDinamicIcon* mmDinamicIcon[100];
        wxStaticText* mmStaticText[100];
        wxStaticBitmap* mmStaticIcon[100];
//        myDinamicIcon* mmDinamicIcon[100];

        wxBitmap* Bmps[100];

        wxBitmap btm1;
        wxBitmap btm2;

        int nbu;
        int ntc;
        int ndt;
        int ndi;
        int nst;
        int nsi;
        int nbmp;
        int ntxt;



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
    unsigned short usuu;
    unsigned long uluu;
    signed short ssuu;
    signed long lluu;



};



#endif // MMBUILDER_H
