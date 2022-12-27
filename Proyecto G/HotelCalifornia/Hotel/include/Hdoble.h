#ifndef HDOBLE_H
#define HDOBLE_H

#include <Habitacion.h>

//Habitacion doble derivada de la abstraccion
class Hdoble: public Habitacion{
    private:
        string extra1{"Sin extras"};
        string extra2{""};
        int costoPersona{1200};
        int costoExtra{};

    public:
        Hdoble(int = 0, int = 0, string = "", string = "");
        virtual ~Hdoble();

        void setHabitacion() override;
        string getHabitacion() override;

};

#endif // HDOBLE_H
