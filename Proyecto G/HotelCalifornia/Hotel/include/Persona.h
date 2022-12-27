#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

//Clase para definir una persona
class Persona{
    private:
        //Atributos de la persona
        string nombre{};
        int edad{};
        bool mayoriaEdad{false};

    public:
        Persona(string = "", int = 0, bool = false);
        virtual ~Persona();

        void setPersona();
        string getPersona();
        void mayorEdad();
        inline bool getMayoria(){return mayoriaEdad;}

};

#endif // PERSONA_H
