#include "mmBuilder.h"
#include "mmDriver.h"

extern void OnPressButton(wxMouseEvent& event);
extern void OnReleaseButton(wxMouseEvent& event);
extern void OnTextEnter(wxCommandEvent& event);
extern mmDriver* driver;



mmBuilder::mmBuilder(wxDialog* parent)
{
    //ctor
    main=parent;
    nbu=0;
    nte=0;
    nla=0;

    for(int i=0;i<200;i++)
    {
        func[i]=0;
        regc[i]=0;
        par1[i]=0;
        par2[i]=0;
        par3[i]=0;
    }

}

mmBuilder::~mmBuilder()
{
    //dtor
}


void mmBuilder::InitButton(void)
{
    DimHor=60;
    DimVer=80;
    PosHor=1;
    PosVer=1;
    Text1="Label";
    func[nbu]=0;
    regc[nbu]=0;
}


void mmBuilder::SetButton(void)
{
    int aa=nbu+1;
    mmButton[nbu] =  new wxButton(Panel1, aa, Text1, wxPoint(PosHor,PosVer), wxSize(DimHor,DimVer), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    mmButton[nbu]->Bind(wxEVT_LEFT_UP, &OnReleaseButton);
    mmButton[nbu]->Bind(wxEVT_LEFT_DOWN, &OnPressButton);
    func[nbu]=Func;
    regc[nbu]=Regc;
    nbu++;
}


void mmBuilder::InitFrame(void)
{
    DimHor=600;
    DimVer=400;
    Text1="Title";
}


void mmBuilder::SetFrame(void)
{
    Frame1=new mmFrame2(main);
    Frame1->SetClientSize(wxSize(DimHor,DimVer));
    Panel1 = Frame1->Panel1;
}


void mmBuilder::ShowFrame(void)
{
    Frame1->ShowModal();
}

void mmBuilder::OnPressBtn(int id)
{
    uint16_t co;
    int u=id-1;
    if (u<0||u>99)
        return;
    co=(uint16_t) regc[u];
    if (func[u]==1||func[u]==3)
        driver->WriteCoilImm(co,true);
    else if (func[u]==2)
        driver->WriteCoilImm(co,false);

}

void mmBuilder::OnReleaseBtn(int id)
{
    uint16_t co;
    int u=id-1;
    if (u<0||u>99)
        return;
    co=(uint16_t) regc[u];
    if (func[u]==3)
        driver->WriteCoilImm(co,false);
}

void mmBuilder::OnEnterTxt(int id)
{

}
