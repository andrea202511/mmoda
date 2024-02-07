#include "mmBuilder.h"

extern void OnPressButton(wxMouseEvent& event);
extern void OnReleaseButton(wxMouseEvent& event);
extern void TextEnter(wxCommandEvent& event);



mmBuilder::mmBuilder(wxDialog* parent)
{
    //ctor
    main=parent;
    nbu=0;
    nte=0;
    nla=0;

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
}


void mmBuilder::SetButton(void)
{
    int aa=nbu+100;
    mmButton[nbu] =  new wxButton(Panel1, aa, Text1, wxPoint(PosHor,PosVer), wxSize(DimHor,DimVer), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    mmButton[nbu]->Bind(wxEVT_LEFT_UP, &OnPressButton);
    mmButton[nbu]->Bind(wxEVT_LEFT_DOWN, &OnReleaseButton);
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



