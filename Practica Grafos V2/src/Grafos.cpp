#include "Grafos.h"
#include <iostream>

#include <list>

using namespace std;

//template <typename C> Grafos<C>::Grafos()
Grafos::Grafos()
{
    cargar = 0;
    for (int i=0; i<100; i++)
        Vertices[i].Id_vertice = -1;
}

//template <typename C> Grafos<C>::~Grafos()
Grafos::~Grafos()
{
    //dtor
}

//template <typename C> void Grafos<C>::agregar_vertice(int vertice) {
void Grafos::agregar_vertice(int vertice) {
    int cursor = 0;
    while (cursor < cargar && Vertices[cursor].Id_vertice != vertice)
        cursor++;
    if (cursor == cargar){
        Vertices[cargar].Id_vertice = vertice;
        cargar++;
    }
    //else vertice ya cargado!
}

//template <typename C> void Grafos<C>::eliminar_vertice(int vertice){
void Grafos::eliminar_vertice(int vertice){
    int cursor = 0;
    while (cursor < 100 && Vertices[cursor].Id_vertice != vertice)
        cursor++;
    if (cursor < 100)
        Vertices[cursor].Id_vertice = -1;//Eliminar arcos de posicion y acomodar el arreglo.


}

//template <typename C> bool Grafos<C>::existe_vertice(int vertice) const {
bool Grafos::existe_vertice(int vertice) const {
    int cursor = 0;
    while (cursor < 100 && Vertices[cursor].Id_vertice != vertice)
        cursor++;
    if (cursor < 100)
        return true;
    else
        return false;
}

//template <typename C> void Grafos<C>::agregar_arco(int origen, int destino, const C & costo) {
void Grafos::agregar_arco(int origen, int destino, int costo) {
    Arco aux(destino, costo);
    int cursor = 0;
    while (cursor < 100 && Vertices[cursor].Id_vertice != origen)
        cursor++;
    if (cursor < 100)
        Vertices[cursor].Vecinos.push_front(aux); //FALTA COSTO (make_pair?)
    //else vertice no existe!

}

//template <typename C> void Grafos<C>::eliminar_arco(int origen, int destino) {
void Grafos::eliminar_arco(int origen, int destino) {
    int indice = 0;
    while (indice < 100 && Vertices[indice].Id_vertice != origen)
        indice++;
    if (indice < 100) {
        typename list<Arco>::iterator cursor = Vertices[indice].Vecinos.begin();
        while (cursor != Vertices[indice].Vecinos.end() && cursor->devolver_adyacente() != destino)
            cursor++;
        if (cursor->devolver_adyacente() == destino)
            Vertices[indice].Vecinos.erase(cursor);
    }
}

//template <typename C> bool Grafos<C>::existe_arco(int origen, int destino) const {
bool Grafos::existe_arco(int origen, int destino) const {
    int indice = 0;
    while (indice < 100 && Vertices[indice].Id_vertice != origen)
        indice++;
    if (indice < 100){
        typename list<Arco>::const_iterator cursor = Vertices[indice].Vecinos.begin();
        while (cursor != Vertices[indice].Vecinos.end() && cursor->devolver_adyacente() != destino)
            cursor++;
        if (cursor->devolver_adyacente() == destino)
            return true;}
    return false;
}

//template <typename C> const C & Grafos<C>::costo_arco(int origen, int destino) const {
int Grafos::costo_arco(int origen, int destino) const {
    int indice = 0;
    while (indice < 100 && Vertices[indice].Id_vertice != origen)
        indice++;
    if (indice < 100){
        typename list<Arco>::const_iterator cursor = Vertices[indice].Vecinos.begin();
        while (cursor != Vertices[indice].Vecinos.end() && cursor->devolver_adyacente() != destino)
            cursor++;
        if (cursor->devolver_adyacente() == destino)
            return cursor->devolver_costo();
    }
    else return -1;
}

//template <typename C> void Grafos<C>::devolver_vertices(list<int> & vertices) const {
void Grafos::devolver_vertices(list<int> & vertices) const {
    for (int i =0; i<100; i++)
        if (Vertices[i].Id_vertice != -1)
            vertices.push_back(Vertices[i].Id_vertice);
}

//template <typename C> void Grafos<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const {
void Grafos::devolver_adyacentes(int origen, list<Arco> & adyacentes) const {
    int indice = 0;
    while (indice < 100 && Vertices[indice].Id_vertice != origen)
        indice++;
    if (indice < 100){
        typename list<Arco>::const_iterator cursor = Vertices[indice].Vecinos.begin();
        while (cursor != Vertices[indice].Vecinos.end())
        {
            Arco aux(cursor->devolver_adyacente(), cursor->devolver_costo());
            adyacentes.push_front(aux);
            cursor++;
        }
    }
}
