#include "mmDriver.h"
#include "mmSetting.h"

#include <string>

#include "mmodaMain.h"
extern mmodaDialog* mainDlg;

extern mmSetting* setting;


mmDriver::mmDriver()
{
    //ctor
}

mmDriver::~mmDriver()
{
    //dtor
}


void mmDriver::Connect()
{
    bool b;
    wxString ip;
    ip=wxString::Format(wxT("%d.%d.%d.%d"), (int)setting->ipp1, (int)setting->ipp2, (int)setting->ipp3, (int)setting->ipp4);

    wxString st;
    st.Printf("Connecting to %s:%i\n",ip,setting->port);
    mainDlg->AddLog(st);

    comm = new modbus((std::string)ip,(uint16_t)setting->port,500);
    b=comm->modbus_connect();
    if (b==true)
      mainDlg->AddLog("...Done\n");
    else
      mainDlg->AddLog("...FAIL\n");



}

void mmDriver::WriteCoilImm(uint16_t co,bool val)
{
    if (comm->is_connected())
    {
        err=comm->modbus_write_coil(co,val);

        if (err!=0)
        {
        wxString st;
        st.Printf("Comm error: write coil %i [%i]\n",co,err);
        mainDlg->AddLog(st);
        }

    }
}

void mmDriver::WriteRegisterImm(uint16_t reg,uint16_t val)
{
    if (comm->is_connected())
    {
        err=comm->modbus_write_register(reg,val);

        if (err!=0)
        {
            wxString st;
            st.Printf("Comm error: write register %i [%i]\n",reg,err);
            mainDlg->AddLog(st);
        }
    }
 }
void mmDriver::WriteRegistersImm(uint16_t reg,uint16_t num, uint16_t *val)
{
 //   if (comm->is_connected())
   //   comm->modbus_write
}

void mmDriver::ReadCoilImm(uint16_t co,bool* val)
{
    if (comm->is_connected())
    {
        err=comm->modbus_read_coils(co,1,val);

        if (err!=0)
        {
            wxString st;
            st.Printf("Comm error: read coil %i [%i]\n",co,err);
            mainDlg->AddLog(st);
        }
    }
}

void mmDriver::ReadRegisterImm(uint16_t reg,uint16_t* val)
{
    if (comm->is_connected())
    {
        err=comm->modbus_read_holding_registers(reg,1,val);

        if (err!=0)
        {
            wxString st;
            st.Printf("Comm error: read register %i [%i]\n",reg,err);
            mainDlg->AddLog(st);
        }
    }
}
void mmDriver::ReadRegistersImm(uint16_t reg,uint16_t num, uint16_t* val)
{
 //   if (comm->is_connected())
   //   comm->modbus_write
}


