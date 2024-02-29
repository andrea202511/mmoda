#include "mmDriver.h"
#include "mmSetting.h"

#include <string>

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
    wxString ip;
    ip=wxString::Format(wxT("%d.%d.%d.%d"), (int)setting->ipp1, (int)setting->ipp2, (int)setting->ipp3, (int)setting->ipp4);

    comm = new modbus((std::string)ip,(uint16_t)setting->port,500);
  //  comm = new modbus("127.0.0.1",1502,500);
    comm->modbus_connect();
}

void mmDriver::WriteCoilImm(uint16_t co,bool val)
{
    if (comm->is_connected())
      comm->modbus_write_coil(co,val);
}

void mmDriver::WriteRegisterImm(uint16_t reg,uint16_t val)
{
    if (comm->is_connected())
      comm->modbus_write_register(reg,val);
}
void mmDriver::WriteRegistersImm(uint16_t reg,uint16_t num, uint16_t *val)
{
 //   if (comm->is_connected())
   //   comm->modbus_write
}

void mmDriver::ReadCoilImm(uint16_t co,bool* val)
{
    if (comm->is_connected())
      comm->modbus_read_coils(co,1,val);
}

void mmDriver::ReadRegisterImm(uint16_t reg,uint16_t* val)
{
    if (comm->is_connected())
      comm->modbus_read_holding_registers(reg,1,val);
}
void mmDriver::ReadRegistersImm(uint16_t reg,uint16_t num, uint16_t* val)
{
 //   if (comm->is_connected())
   //   comm->modbus_write
}


