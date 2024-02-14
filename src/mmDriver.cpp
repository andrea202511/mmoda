#include "mmDriver.h"

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
    comm = new modbus("127.000.000.001",1502,500);
    comm->modbus_connect();
}

void mmDriver::WriteCoilImm(uint16_t co,bool val)

{
    if (comm->is_connected())
      comm->modbus_write_coil(co,val);
}
