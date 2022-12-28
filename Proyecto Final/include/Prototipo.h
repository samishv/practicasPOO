#ifndef PROTOTIPO_H
#define PROTOTIPO_H
#include "Integrantes.h"
#include <string>

class Prototipo
{
    private:
        string nombrePrototipo;
        int numeroIntegrantes;
        Integrantes *INTEGRANTES;
        string equipo;

    public:
        Prototipo();
        virtual ~Prototipo();
        void setPrototipo();
        string getPrototipo();


    protected:

};

#endif // PROTOTIPO_H
