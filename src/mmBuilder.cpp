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
    ntc=0;
    nst=0;
    nsb=0;


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

/*=========================
  BUTTON
==========================*/
void mmBuilder::InitButton(void)
{
    DimHor=60;
    DimVer=80;
    PosHor=1;
    PosVer=1;      wxValidator* val;
     wxValidator* valf;

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

void mmBuilder::InitTextCtrl(void)
{

}

void mmBuilder::SetTextCtrl(void)
{
//wxFloatingPointValidator<double> _val(2,&_myValue,wxNUM_VAL_ZERO_AS_BLANK);
//    _val.SetRange(0.,1000.);     // set allowable range

//if (Func==1)
  //  wxIntegerValidator<signed short> val(&ssuu, wxNUM_VAL_THOUSANDS_SEPARATOR);
//if (Func==7)
    wxFloatingPointValidator<float> val(2,&fluu[ntc], wxNUM_VAL_THOUSANDS_SEPARATOR);

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
       val.SetMin(-2147483648);
       val.SetMax(2147483648);
       val.SetPrecision(0);
    }
    else if (Func==4)
    {
       val.SetMin(-2147483648);
       val.SetMax(2147483648);
       val.SetPrecision(0);
    }
    else if (Func==5)
    {
       val.SetMin(-2147483648);
       val.SetMax(2147483648);
       val.SetPrecision(3);
    }
    else if (Func==6)
    {
       val.SetMin(-2147483648);
       val.SetMax(2147483648);
      // unsigned int ui= par1;
       val.SetPrecision(2);
    }

    int aa=ntc+1+100;
        mmTextCtrl[ntc] = new wxTextCtrl(Panel1, aa, _(""), wxPoint(PosHor,PosVer), wxDefaultSize, wxTE_PROCESS_ENTER, val, _T("ID_TEXTCTRL1"));
     mmTextCtrl[ntc]->Bind(wxEVT_TEXT_ENTER, &OnTextEnter);
    func[ntc+100]=Func;
    regc[ntc+100]=Regc;
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
void mmBuilder::InitStaticBitmap(void)
{
    PosHor=1;
    PosVer=1;
    Text1="null";
}


void mmBuilder::SetStaticBitmap(void)
{
    int aa=nsb+1;
     mmStaticBitmap[nsb] = new wxStaticBitmap(Panel1, aa, wxBitmap(wxImage(Text1)), wxPoint(PosHor,PosVer), wxDefaultSize, 0, _T("ID_STATICBITMAP1"));
   nsb++;
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
   // mmTextCtrl->GetValidator();
   mmTextCtrl[u]->GetValidator()->TransferFromWindow();
   mmTextCtrl[u]->Enable(false);
   mmTextCtrl[u]->Enable(true);

    co=(uint16_t) regc[u+100];
    if (func[u+100]==1)
    {
        i16=(int16_t)fluu[u];
        driver->WriteRegisterImm(co,i16);
    }
    else if (func[u+100]==2)
    {
        i32=(int32_t)fluu[u];
        ui16=(uint16_t)i32;
        driver->WriteRegisterImm(co,ui16);
        ui16=(uint16_t)(i32/65536);
        co++;
        driver->WriteRegisterImm(co,ui16);

    }
    else if (func[u+100]==3)
    {
        ui16=(uint16_t)fluu[u];
        driver->WriteRegisterImm(co,ui16);
    }
    else if (func[u+100]==4)
    {
        ui32=(int32_t)fluu[u];
        ui16=(uint16_t)ui32;
        driver->WriteRegisterImm(co,ui16);
        ui16=(uint16_t)(ui32/65536);
        co++;
        driver->WriteRegisterImm(co,ui16);

    }
    else if (func[u+100]==5)
    {
        ui16=(uint16_t)(fluu[u]*1000);
        driver->WriteRegisterImm(co,ui16);
    }
    else if (func[u+100]==6)
    {
        ui32=(int32_t)(fluu[u]*100);
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

    co=(uint16_t) regc[u+100];

    if ((func[u+100]==1)||(func[u+100]==3)||(func[u+100]==5))
    {
        //16 bits
        driver->ReadRegisterImm(co,&ui16);
    }
    else if (func[id+100]==8)
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

    if (func[u+100]==1)
    {
        fluu[u]=(float)(int16_t)ui16;
    }
    else if (func[u+100]==2)
    {
        fluu[u]=(float)(int32_t)ui32;
    }
    else if (func[u+100]==3)
    {
        fluu[u]=(float)ui16;
    }
    else if (func[u+100]==4)
    {
        fluu[u]=(float)ui32;
    }
        else if (func[u+100]==5)
    {
        fluu[u]=((float)ui16)/100;
    }
    else if (func[u+100]==6)
    {
        fluu[u]=((float)ui32)/100;
    }

    mmTextCtrl[u]->GetValidator()->TransferToWindow();
    mmTextCtrl[u]->SetFocus();


}



