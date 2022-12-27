#ifndef HSENCILLA_H
#define HSENCILLA_H

#include <Habitacion.h>

//Habitacion sencilla derivada de la abstraccion
class Hsencilla: public Habitacion{
    private:
        string extra1{"Sin extras"};
        int costoPersona{700};
        int costoExtra{};

    public:
        Hsencilla(int = 0, int = 0, string = "");
        virtual ~Hsencilla();

        void setHabitacion() override;
        string getHabitacion() override;

};

#endif // HSENCILLA_H
