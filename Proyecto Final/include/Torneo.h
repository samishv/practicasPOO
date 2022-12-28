#ifndef TORNEO_H
#define TORNEO_H

#include "Categoria.h"

class Torneo
{
    private:
        int numCategoria;
        int
        //int numGetCategoria;
        Categoria MiniRC{};
        Categoria MiniAutonomo{};


        //Categoria *CATEGORIAS;

    public:
        Torneo();
        virtual ~Torneo();
        void setTorneo();
        void setEncuentros();
        void mostrarCategoria(int);

    protected:


};

#endif // TORNEO_H
