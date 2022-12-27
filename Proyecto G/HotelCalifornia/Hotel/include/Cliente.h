#ifndef CLIENTE_H
#define CLIENTE_H

#include <Persona.h>

//Clase derivada de persona
class Cliente: public Persona{
    private:
        //Atributos del cliente
        string nacionalidad{};
        string numCuenta{};

    public:
        Cliente(string = "", string = "");
        virtual ~Cliente();

        void setCliente();
        string getCliente();

};

#endif // CLIENTE_H
