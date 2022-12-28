#ifndef CATEGORIA_H
#define CATEGORIA_H
#include "Prototipo.h"
#include <string>

class Categoria
{
    private:
        int numPrototipos;
        Prototipo *PROTOTIPOS;

    public:
        Categoria();
        virtual ~Categoria();
        void setCategoria();
        string getCategoria();

    protected:


};

#endif // CATEGORIA_H
