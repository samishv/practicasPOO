#ifndef HSUITE_H
#define HSUITE_H

#include <Habitacion.h>

//Habitacion suite derivada de la abstraccion
class Hsuite: public Habitacion{
    private:
        string extra1{"Sin extras"};
        string extra2{""};
        string extra3{""};
        int costoPersona{1900};
        int costoExtra{};

    public:
        Hsuite(int = 0, int = 0, string = "", string = "", string = "");
        virtual ~Hsuite();

        void setHabitacion() override;
        string getHabitacion() override;
};

#endif // HSUITE_H
