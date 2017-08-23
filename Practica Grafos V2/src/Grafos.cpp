#include "Grafos.h"
#include <iostream>

using namespace std;

template <typename C> Grafos<C>::Grafos()
{
    for (int i=0; i<100; i++)
        Vertices[i]->Id_vertice = false;
}

template <typename C> Grafos<C>::~Grafos()
{
    //dtor
}

template <typename C> void Grafos<C>::agregar_vertice(int vertice) {
    Vertices[vertice]->Id_vertice = true;
}

template <typename C> void Grafos<C>::eliminar_vertice(int vertice){
    Vertices[vertice]->Id_vertice = false;
}

template <typename C> bool Grafos<C>::existe_vertice(int vertice) const {
    return Vertices[vertice]->Id_vertice;
}

template <typename C> void Grafos<C>::agregar_arco(int origen, int destino, const C & costo) {
    Vertices[origen]->Vecinos.push_front(destino); //FALTA COSTO (make_pair?)
}

template <typename C> void Grafos<C>::eliminar_arco(int origen, int destino) {
    Vertices[origen]->Vecinos.remove(destino);
}

template <typename C> bool Grafos<C>::existe_arco(int origen, int destino) const {
    cursor = Vertices[origen]->Vecinos.begin();
    while (cursor != Vertices[origen]->Vecinos.end() && *cursor != destino)
        cursor++;
    if (*cursor == destino)
        return true;
    else
        return false;
}

template <typename C> const C & Grafos<C>::costo_arco(int origen, int destino) const {

}

template <typename C> void Grafos<C>::devolver_vertices(list<int> & vertices) const {
    for (int i =0; i<100; i++)
        if (Vertices[i]->Id_vertice == true)
            vertices.push_back(i);
}

template <typename C> void Grafos<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const {
    adyacentes = Vertices[origen].Vecinos; //?
}
