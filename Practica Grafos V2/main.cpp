#include <iostream>
#include "Grafos.h"
#include <list>
using namespace std;

void DFS(int vertice, Grafos a, int P[], int Marca[], int indice, int V[]){
    list<Grafos::Arco> adyacentes;
    Marca[indice] = 0;
    a.devolver_adyacentes(vertice, adyacentes);
    list<Grafos::Arco>::iterator it = adyacentes.begin();
    while (it != adyacentes.end()){
        int j=0;
        while (V[j] != it->devolver_adyacente())
            j++;
        int v = V[j];
        if (Marca[j] == -1) { //si la marca es 0, entonces hay un ciclo.
            P[j] = vertice;
            DFS(v, a, P, Marca, j, V);
        }
        it++;
    }
    Marca[indice] = 1;
    cout << "vertice: " << vertice << endl;
}

void DFS_FOREST(Grafos a) {
    list<int> vertices;
    a.devolver_vertices(vertices);
    int n = vertices.size();
    int P[n], Marca[n], V[n];
    list<int>::iterator it = vertices.begin();
    for(int i=0; i<n; i++) {
        V[i] = *it;
        Marca[i] = -1;
        P[i] = -1;
        it++;
    }
    for (int i=0; i<n; i++)
        if (Marca[i] == -1){
            int vertice = V[i];
            DFS(vertice, a, P, Marca, i, V);
        }
}

void imprime_vertices (Grafos a) {
    list<int> vertices;
    a.devolver_vertices(vertices);
    for(list<int>::iterator it = vertices.begin(); it != vertices.end(); it++)
        cout << *it << endl;
    cout << "Tamano: " << vertices.size() << endl;
}

void imprime_menu() {

    cout << "****************************************" << endl;
	cout << endl << "que desea hacer?" << endl << endl;
    cout << "1- Agregar un Arco" << endl;
    cout << "2- Eliminar un Arco" << endl;
    cout << "3- Ver el Costo de un Arco" << endl;
    cout << "4- Existe Arco?" << endl;
    cout << "5- Devolver adyacentes de un vertice" << endl;
    cout << endl;
    cout << "6- Agregar Vertice" << endl;
    cout << "7- Eliminar Vertice" << endl;
    cout << "8- ver Vertices" << endl;
    cout << "9- Existe vertice?" << endl;
    cout << endl;
    cout << "0- Salir" << endl;
	cout << "****************************************" << endl;
}

int main()
{
    int opcion, origen, destino, costo;
    list<Grafos::Arco> adyacentes;

    cout << "Hello world!" << endl;
    Grafos GrafoPrueba;
    GrafoPrueba.agregar_vertice(1);
    GrafoPrueba.agregar_vertice(2);
    GrafoPrueba.agregar_vertice(3);
    GrafoPrueba.agregar_vertice(4);
    GrafoPrueba.agregar_vertice(5);
    GrafoPrueba.agregar_arco(1, 2, 5);
    GrafoPrueba.agregar_arco(1, 4, 10);
    GrafoPrueba.agregar_arco(2, 3, 7);
    GrafoPrueba.agregar_arco(5, 3, 2);
    DFS_FOREST(GrafoPrueba);
    imprime_menu();
    cin >> opcion;
    while (opcion != 0){
    	switch (opcion){
    		case 1:{
				cout << "Ingrese Origen del arco: ";
				cin >> origen;
				cout << "Ingrese Destino del arco: ";
				cin >> destino;
				cout << "Ingrese Costo del arco: ";
				cin >> costo;
				GrafoPrueba.agregar_arco(origen, destino, costo);
				cout << endl << "Se agregó el arco (" << origen << ", " << destino << ", " << costo << ")" << endl;
    		}
	            break;
    		case 2:{
    			cout << "Ingrese Origen del arco: ";
				cin >> origen;
				cout << "Ingrese Destino del arco: ";
				cin >> destino;
				GrafoPrueba.eliminar_arco(origen, destino);
				cout << endl <<  "Se Eliminó el arco (" << origen << ", " << destino << ")" << endl;
    		}
	            break;
    		case 3:{
    			cout << "Ingrese Origen del arco: ";
				cin >> origen;
				cout << "Ingrese Destino del arco: ";
				cin >> destino;
				cout <<  endl << "el costo del arco (" << origen << ", " << destino << ") es " << GrafoPrueba.costo_arco(origen, destino) << endl;
    		}
	            break;
    		case 4:{
    			cout << "Ingrese Origen del arco: ";
				cin >> origen;
				cout << "Ingrese Destino del arco: ";
				cin >> destino;
    			if (GrafoPrueba.existe_arco(origen, destino))
    				cout << endl <<  "(" << origen << ", " << destino << ") Existe";
    			else
    				cout << endl <<  "(" << origen << ", " << destino << ") NO Existe";

    		}
	            break;
    		case 5:{
    			cout << "Ingrese Origen del arco: ";
				cin >> origen;
				GrafoPrueba.devolver_adyacentes(origen, adyacentes);
				list<Grafos::Arco>::iterator it = adyacentes.begin();
				while(it != adyacentes.end()) {
                    cout << "Vertice: " << it->devolver_adyacente() << ", Costo: " << it->devolver_costo() << endl;
                    it++;
				}
    		}
                break;
    		case 6:{
    			cout << "Ingrese el vertice a agregar: " << endl;
    			cin >> origen;
    			GrafoPrueba.agregar_vertice(origen);
    			cout << endl <<  "Vertice Agregado! " << endl;
    			/*cout << "Cantidad de vertices: " << pelele.Cantidad_vertices() << endl;*/
    		}
	            break;
    		case 7:{
    			cout << "Ingrese el N° de Vertice a Eliminar: ";
    			cin >> origen;
    			GrafoPrueba.eliminar_vertice(origen);
    			cout << endl << "Vertice Eliminado! " << endl;
    			/*cout << "Cantidad de vertices: " << pelele.Cantidad_vertices() << endl;*/
    		}
	            break;
    		case 8:{
    			 imprime_vertices(GrafoPrueba);
    		}
	            break;
    		case 9:{
    		    cout << "Ingrese vertice: ";
				cin >> origen;
    			if (GrafoPrueba.existe_vertice(origen))
    				cout << endl <<  "El vertice " << origen << " Existe";
    			else
    				cout << endl <<  "El vertice " << origen << " NO Existe";
			}
	            break;
    		default:{
                cout <<  endl << "Opción invalida\n" << "Ingrese una nueva opción\n";
            }
            break;}
        imprime_menu();
        cin >> opcion;}

    return 0;
}
