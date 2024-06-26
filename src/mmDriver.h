#ifndef MMDRIVER_H
#define MMDRIVER_H

#include <wx/string.h>

#include "modbus.h"


class mmDriver
{
    public:
        mmDriver();
        virtual ~mmDriver();

        void Connect(void);
        void WriteCoilImm(uint16_t co,bool val);
        void WriteRegisterImm(uint16_t reg,uint16_t val);
        void WriteRegistersImm(uint16_t reg,uint16_t num, uint16_t* val);

        void ReadCoilImm(uint16_t co,bool* val);
        void ReadRegisterImm(uint16_t reg, uint16_t* val);
        void ReadRegistersImm(uint16_t reg, uint16_t num, uint16_t* val);

        int err;

    protected:

    private:
        modbus* comm;

    /*
    buffer di trasmissione
    coil val
    register val
    */

    /*
    buffer aggiornamenti
    coil
    var
    in caso di variazione cosa faccio?

    forse tutto indicizzato[xx] con indice ID
    se variazione evento aggiornamento ID corrispondente

    */

    /* il builder deve avere lista azioni per ogni evento di ogni id
    ad esempio
    fronte_positivo_btn[100];
    front_negativo_btn[100];
    enter_textbox[100];
    variazione[100];

    l'evento deve avere sia indirizzo coil/registro che valore da scrivere

    il gestore degli eventi (fronte pos/fronte neg/enter) sciverà su buffer_trasmissione

    Il gestore eventi "variazione" viene invocato da Driver

    */


};

#endif // MMDRIVER_H
