#include "mmBuilder.h"
#include "mmDriver.h"

#include <wx/dcclient.h>


extern void OnPressButton(wxMouseEvent& event);
extern void OnReleaseButton(wxMouseEvent& event);
extern void OnTextEnter(wxCommandEvent& event);
extern mmDriver* driver;



mmBuilder::mmBuilder(wxDialog* parent)
{
    //ctor
    main=parent;
    nbu=0;
    ntc=0;
    ndt=0;
    ndi=0;
    nst=0;
    nsi=0;
    nbmp=0;
    ntxt=0;



}

mmBuilder::~mmBuilder()
{
    //dtor
}

void mmBuilder::Notify()
{
    uint16_t co;
    bool b;
    int ii;
    int ic;

    for (int i=0; i<ntc; i++)
    {
        if(par3_tc[i]>1)
            UpdTextCtrl(i+101);
    }


    for (int i=0;i<ndi; i++)
    {
        ic=0;
        co=(uint16_t) regc_di[i];
        driver->ReadCoilImm(co,&b);
        ii=(int)b;
        if ((ii==0)&&(val_di[i]!=0))
            ic=par1_di[i];
        if ((ii==1)&&(val_di[i]!=1))
            ic=par2_di[i];
        val_di[i]=ii;
        if (ic>0)
        {
            wxClientDC dc(Panel1);
            dc.DrawBitmap(*Bmps[ic],posx_di[i],posy_di[i],false);
        }

    }

}

void mmBuilder::CloseFrame()
{
    Stop();
    for (int u=0; u<nbu; u++)
        delete mmButton[u];
    for (int u=0; u<ntc; u++)
        delete mmTextCtrl[u];
    for (int u=0; u<nst; u++)
        delete mmStaticText[u];
    for (int u=0; u<nsi; u++)
        delete mmStaticIcon[u];
    nbu=0;
    ntc=0;
    ndt=0;
    ndi=0;
    nst=0;
    nsi=0;

}


/*=========================
  BUTTON
==========================*/
void mmBuilder::InitButton(void)
{
    DimHor=60;
    DimVer=80;
    PosHor=1;
    PosVer=1;
    Par1=0;
    Par2=0;
    Par3=0;
//    wxValidator* val;
//    wxValidator* valf;

    Text1="Label";
    func_bt[nbu]=0;
    regc_bt[nbu]=0;
    par1_bt[nbu]=0;
    par2_bt[nbu]=0;
    par3_bt[nbu]=0;
}


void mmBuilder::SetButton(void)
{
    int aa=nbu+1;
    mmButton[nbu] =  new wxButton(Panel1, aa, Text1, wxPoint(PosHor,PosVer), wxSize(DimHor,DimVer), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    mmButton[nbu]->Bind(wxEVT_LEFT_UP, &OnReleaseButton);
    mmButton[nbu]->Bind(wxEVT_LEFT_DOWN, &OnPressButton);
    func_bt[nbu]=Func;
    regc_bt[nbu]=Regc;
    nbu++;
}


/*=========================
  TEXTCTRL
;Numericfield Mode
;1 signed integer 16 bit    //ordine byte da setting
;2 signed integer 32 bit
;3 unsigned integer 16 bit
;4 unsigned integer 32 bit
;5 fixed point 16 bit //decimali su par1
;6 fixed point 32 bit
;7 floting point 32 bit
;8 floating poit 64 bits

;Numericfield ReadOnly  //Rreadonly su par3
; 0 writable
; 1 read only update only at startup
; 2 read only update continue
==========================*/

void mmBuilder::InitTextCtrl(void)
{
//    DimHor=60;
//    DimVer=80;
    PosHor=1;
    PosVer=1;
    Par1=0;
    Par2=0;
    Par3=0;
    func_tc[ntc]=0;
    regc_tc[ntc]=0;
    par1_tc[ntc]=0;
    par2_tc[ntc]=0;
    par3_tc[ntc]=0;
    flo_tc[ntc]=-1;

}

void mmBuilder::SetTextCtrl(void)
{
    wxFloatingPointValidator<float> val(2,&flo_tc[ntc], wxNUM_VAL_THOUSANDS_SEPARATOR);

    if (Func==1)
    {
       val.SetMin(-32767);
       val.SetMax(32767);
       val.SetPrecision(0);
    }
    else if (Func==2)
    {
       val.SetMin(-2147483648);
       val.SetMax(2147483648);
       val.SetPrecision(0);
    }
    else if (Func==3)
    {
       val.SetMin(0);
       val.SetMax(65535);
       val.SetPrecision(0);
    }
    else if (Func==4)
    {
       val.SetMin(-0);
       val.SetMax(4294967295);
       val.SetPrecision(0);
    }
    else if (Func==5)
    {
       val.SetMin(-32767);
       val.SetMax(32767);
       val.SetPrecision(Par1);
    }
    else if (Func==6)
    {
       val.SetMin(-2147483648);
       val.SetMax(2147483648);
       val.SetPrecision(Par1);
    }

    int aa=ntc+1+100;
    mmTextCtrl[ntc] = new wxTextCtrl(Panel1, aa, _(""), wxPoint(PosHor,PosVer), wxDefaultSize, wxTE_PROCESS_ENTER, val, _T("ID_TEXTCTRL1"));
    mmTextCtrl[ntc]->Bind(wxEVT_TEXT_ENTER, &OnTextEnter);
    if (Par3>0)
    {
        mmTextCtrl[ntc]->SetEditable(false);
        mmTextCtrl[ntc]->Disable();
    }
    func_tc[ntc]=Func;
    regc_tc[ntc]=Regc;
    par1_tc[ntc]=Par1; //decimals
    par2_tc[ntc]=Par2; //lenght
    par3_tc[ntc]=Par3; //readonly
    ntc++;

    UpdTextCtrl(aa);
}

/*=========================
  STATIC TEXT
==========================*/
void mmBuilder::InitStaticText(void)
{
    PosHor=1;
    PosVer=1;
    Text1="Label";
}


void mmBuilder::SetStaticText(void)
{
    int aa=nst+1;
    mmStaticText[nst] = new wxStaticText(Panel1, aa, Text1, wxPoint(PosHor,PosVer), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    nst++;
}

/*=========================
  STATIC BITMAP
==========================*/
void mmBuilder::InitStaticIcon(void)
{
    PosHor=1;
    PosVer=1;
    Text1="null";
}


void mmBuilder::SetStaticIcon(void)
{
    int aa=nsi+1;
/*    if (nsi=0)
    {
        //btm1=new wxBitmapBundle(wxBitmap(wxImage(Text1)));
        btm1.LoadFile(Text1);

    }
    if (nsi=1)
    {
        //btm2=new wxBitmapBundle(wxBitmap(wxImage(Text1)));
        btm2.LoadFile(Text2);
    }
*/
     mmStaticIcon[nsi] = new wxStaticBitmap(Panel1, aa, wxBitmap(wxImage(Text1)), wxPoint(PosHor,PosVer), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
    nsi++;
}

/*=========================
  DINAMIC ICON
==========================*/
void mmBuilder::InitDinamicIcon(void)
{
    PosHor=1;
    PosVer=1;

}


void mmBuilder::SetDinamicIcon(void)
{
    posx_di[ndi]=PosHor;
    posy_di[ndi]=PosVer;
    par1_di[ndi]=Par1;
    par2_di[ndi]=Par2;
    regc_di[ndi]=Regc;
    ndi++;
}


/*=========================
  FRAME
==========================*/

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
    Start(500);

    Frame1->ShowModal();
}

void mmBuilder::OnPressBtn(int id)
{
    uint16_t co;
    int u=id-1;
    if (u<0||u>99)
        return;

    wxClientDC dc(Panel1);
    if (id<6)
      dc.DrawBitmap(*Bmps[id],350,350,false);

//    mmStaticIcon[0]->SetBitmap(btm1);
  //  mmStaticIcon[1]->SetBitmap(btm2);
 //   mmStaticIcon[1]->Show();
 //   mmStaticIcon[0]->

//    mmStaticIcon[0]->setbi
//    wxBitmapBundle

    co=(uint16_t) regc_bt[u];
    if (func_bt[u]==1||func_bt[u]==3)
        driver->WriteCoilImm(co,true);
    else if (func_bt[u]==2)
        driver->WriteCoilImm(co,false);

}

void mmBuilder::OnReleaseBtn(int id)
{

    mmStaticIcon[0]->SetBitmap(btm2);
     mmStaticIcon[1]->SetBitmap(btm1);
 //   mmStaticIcon[0]->Show();

    uint16_t co;
    int u=id-1;
    if (u<0||u>99)
        return;
    co=(uint16_t) regc_bt[u];
    if (func_bt[u]==3)
        driver->WriteCoilImm(co,false);
}

/*=========================
  TEXTCTRL
;Numericfield Mode
;1 signed integer 16 bit    //ordine byte da setting
;2 signed integer 32 bit
;3 unsigned integer 16 bit
;4 unsigned integer 32 bit
;5 fixed point 16 bit //decimali su par1
;6 fixed point 32 bit
;7 floting point 32 bit
;8 floating poit 64 bits

;Numericfield ReadOnly
; 0 writable
; 1 read only update only at startup
; 2 read only update continue
==========================*/


void mmBuilder::OnEnterTxt(int id)
{
    uint16_t co,ui16;
    uint32_t ui32;
    int16_t i16;
    int32_t i32;

    int u=id-1-100;
    if (u<0||u>99)
        return;

    mmTextCtrl[u]->GetValidator()->TransferFromWindow();
    mmTextCtrl[u]->Enable(false);
    mmTextCtrl[u]->Enable(true);

    co=(uint16_t) regc_tc[u];
    if (func_tc[u]==1)
    {
        i16=(int16_t)flo_tc[u];
        driver->WriteRegisterImm(co,i16);
    }
    else if (func_tc[u]==2)
    {
        i32=(int32_t)flo_tc[u];
        ui16=(uint16_t)i32;
        driver->WriteRegisterImm(co,ui16);
        ui16=(uint16_t)(i32/65536);
        co++;
        driver->WriteRegisterImm(co,ui16);
    }
    else if (func_tc[u]==3)
    {
        ui16=(uint16_t)flo_tc[u];
        driver->WriteRegisterImm(co,ui16);
    }
    else if (func_tc[u]==4)
    {
        ui32=(int32_t)flo_tc[u];
        ui16=(uint16_t)ui32;
        driver->WriteRegisterImm(co,ui16);
        ui16=(uint16_t)(ui32/65536);
        co++;
        driver->WriteRegisterImm(co,ui16);
    }
    else if (func_tc[u]==5)
    {
        ui16=(uint16_t)(flo_tc[u]*pow(10,par1_tc[u]));
        driver->WriteRegisterImm(co,ui16);
    }
    else if (func_tc[u]==6)
    {
        ui32=(int32_t)(flo_tc[u]*pow(10,par1_tc[u]));
        ui16=(uint16_t)ui32;
        driver->WriteRegisterImm(co,ui16);
        ui16=(uint16_t)(ui32/65536);
        co++;
        driver->WriteRegisterImm(co,ui16);
    }

}

void mmBuilder::UpdTextCtrl(int id)
{
    uint16_t co,ui16;
    uint32_t ui32;

    int u=id-1-100;
    if (u<0||u>99)
        return;

    co=(uint16_t) regc_tc[u];

    if ((func_tc[u]==1)||(func_tc[u]==3)||(func_tc[u]==5))
    {
        //16 bits
        driver->ReadRegisterImm(co,&ui16);
    }
    else if (func_tc[u]>=8)
    {
        //64 bits
        //qui quattro
    }
    else
    {
        //32 bits
        driver->ReadRegisterImm(co,&ui16);
        ui32=((uint32_t) ui16)*65536;
        co++;
        driver->ReadRegisterImm(co,&ui16);
        ui32=ui32+(uint32_t) ui16;
    }

    if (func_tc[u]==1)
    {
        flo_tc[u]=(float)(int16_t)ui16;
    }
    else if (func_tc[u]==2)
    {
        flo_tc[u]=(float)(int32_t)ui32;
    }
    else if (func_tc[u]==3)
    {
        flo_tc[u]=(float)ui16;
    }
    else if (func_tc[u]==4)
    {
        flo_tc[u]=(float)ui32;
    }
        else if (func_tc[u]==5)
    {
        flo_tc[u]=((float)ui16)/pow(10,par1_tc[u]);
    }
    else if (func_tc[u]==6)
    {
        flo_tc[u]=((float)ui32)/pow(10,par1_tc[u]);
    }

    mmTextCtrl[u]->GetValidator()->TransferToWindow();
 //   mmTextCtrl[u]->SetFocus();

}

void mmBuilder::AddBitmap(wxString bmp)
{
     Bmps[nbmp] = new wxBitmap(bmp);
     nbmp++;

}




