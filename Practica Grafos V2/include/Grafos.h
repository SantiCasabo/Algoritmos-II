#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <list>

using namespace std;

//template <typename C>
class Grafos
{
   public:
    class Arco //hacer .cpp
    {
        public:
            Arco();
            Arco(int adyacente, int Costo);
            int devolver_adyacente() const;
            int devolver_costo() const;
        private:
            int vertice;
            int costo;
    }; //class Arco


    public:
        Grafos();
        virtual ~Grafos();

        void agregar_vertice(int vertice);
        void eliminar_vertice(int vertice);
        bool existe_vertice(int vertice) const;

        void agregar_arco(int origen, int destino, int costo);
        void eliminar_arco(int origen, int destino);
        bool existe_arco(int origen, int destino) const;
        int costo_arco(int origen, int destino) const;

        void devolver_vertices(list<int> & vertices) const;
        void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;
    protected:
    private:
        struct Nodo {
            int Id_vertice; //cambiar.
            list<Arco> Vecinos;
        };
        int cargar;
        Nodo Vertices[100];

};

#endif // GRAFOS_H
