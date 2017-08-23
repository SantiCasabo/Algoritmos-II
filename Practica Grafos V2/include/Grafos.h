#ifndef GRAFOS_H
#define GRAFOS_H
#include <iostream>
#include <list>

using namespace std;

template <typename C>
class Grafos
{
    class Arco //hacer .cpp
    {
        public:
            Arco();
            Arco(int adyacente, const C & costo);
            int devolver_adyacente() const;
            const C & devolver_costo() const;
        private:
            int vertice;
            C costo;
    }; //class Arco


    public:
        Grafos();
        virtual ~Grafos();

        void agregar_vertice(int vertice);
        void eliminar_vertice(int vertice);
        bool existe_vertice(int vertice) const;

        void agregar_arco(int origen, int destino, const C & costo);
        void eliminar_arco(int origen, int destino);
        bool existe_arco(int origen, int destino) const;
        const C & costo_arco(int origen, int destino) const;

        void devolver_vertices(list<int> & vertices) const;
        void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;
    protected:
    private:
        struct Nodo {
            bool Id_vertice; //cambiar.
            list<Arco> Vecinos;
        };
        Nodo Vertices[100];
        list<Arco<int, C> >::iterator cursor; //?
};

#endif // GRAFOS_H
