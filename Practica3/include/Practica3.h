#ifndef PRACTICA3_H
#define PRACTICA3_H

class Practica3{
    private:
        //Atributos del tamaño del mundo
        int columnas{};
        int filas{};
        //Atributo de generaciones a mostrar
        int interacciones{};
        int generacion{};
        //Atributo para alternar entre mundos para actualizarlos consecutivamente
        bool alterno{false};
        //Atributo para saber si esta muerto un mundo
        bool muerto{false};
        //Dobles apuntadores para guardar los mundos
        char **A;
        char **B;

    public:
        //Constructores
        Practica3();
        ~Practica3();

        //Métodos
        void setColumnas();
        void setFilas();
        void mundo0();
        void crearMundoA();
        void crearMundoB();
        void imprimirVida();
        void actualizarVida();
        char vecinosVivos(int, int, char);
        void setInteracciones();
        void generaciones(Practica3);
        bool mundoMuerto();

};

#endif // PRACTICA3_H
