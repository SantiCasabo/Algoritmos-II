#include <iostream>
#include <cmath>

using namespace std;

bool poda(int R[], int i) {
    for(int j=0; j<i; j++)
        if (R[i] == R[j] || (i-j == abs(R[i] - R[j])))
            return true;
    return false;
}

void Imprimir(int Arr[], int N) {
    cout << endl;
    for (int i=0; i<N; i++)
        cout << "| " << Arr[i];
    cout << "|" << endl;
}

int BackNReinas(int Reinas[], int nroReinas, int N) {
    if (nroReinas == N) {
        Imprimir(Reinas, N);
        return 1;
    }
    else {
        int columna = 0, solucion = 0;
        while (columna < N && solucion == 0) {
            Reinas[nroReinas] = columna;
            if (!poda(Reinas, nroReinas))
                solucion = BackNReinas(Reinas, nroReinas + 1, N);
            columna++;
        }
        return solucion;
    }
}

bool tablero_lleno(int A[]) {
    for (int i=0; i<9; i++)
        if (A[i] == 0)
            return false;
    return true;
}

bool iguales_filas(int A[], int & valor) {
    for (int fila=0; fila<9; fila += 3){
        if (A[fila] == 1 && A[fila+1] == 1 && A[fila+2] == 1) {
            valor = 1;
            return true;
        }
        if (A[fila] == -1 && A[fila+1] == -1 && A[fila+2] == -1) {
            valor = -1;
            return true;
        }
    }
    return false;
}

bool iguales_columnas(int A[], int & valor) {
    for (int columna=0; columna<3; columna++){
        if (A[columna] == 1 && A[columna+3] == 1 && A[columna+6] == 1) {
            valor = 1;
            return true;
        }
        if (A[columna] == -1 && A[columna+3] == -1 && A[columna+6] == -1) {
            valor = -1;
            return true;
        }
    }
    return false;
}

bool iguales_diagonal(int A[], int & valor) { //SE PUEDE OPTIMIZAR
    if (A[0] == 1 && A[4] == 1 && A[8] == 1) {
        valor = 1;
        return true;
    }
    if (A[2] == 1 && A[4] == 1 && A[6] == 1) {
        valor = 1;
        return true;
    }
    if (A[0] == -1 && A[4] == -1 && A[8] == -1) {
        valor = -1;
        return true;
    }
    if (A[2] == -1 && A[4] == -1 && A[6] == -1) {
        valor = -1;
        return true;
    }
    return false;
}

bool Hoja(int A[], int & valor) { //verifica si es estado terminal
    if (iguales_columnas(A, valor) || iguales_filas(A, valor) || iguales_diagonal(A, valor))
        return true;
    else
        if(tablero_lleno(A)) {
            valor = 0;
            return true;
        }
    return false;
}

int minimo(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int maximo(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void imprime(int A[]) {
    int indice = 0;
    cout << endl;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++){
            cout << "| " << A[indice];
            indice++;
        }
        cout << "|" << endl;
    }
}

int BackMiniMax(int A[], bool modoMAX, int indice) { //TRABAJA DE MANERA SECUENCIAL EN VEZ DE INTELIGENTEMENTE
    int nroHijos, valor;
    if (Hoja(A, valor)){
        imprime(A);
        return valor;} //supongo que deberia usar una heuristica en vez de evaluar asi nomas
    else {
        nroHijos = 0;
        if (modoMAX == 0)
            valor = -100;
        else
            valor = 100;
        while (nroHijos < 9) { //demasiados nodos para examinarlos todos por eso el error creo.
         //  if (A[nroHijos] == 0) { cuando lo comento tira error, sino o hace secuencial
            if (modoMAX == 0){
                A[nroHijos] = 1;
                valor = maximo(valor, BackMiniMax(A, 1, nroHijos+1));
            }
            else {
                A[nroHijos] = -1;
                valor = minimo(valor, BackMiniMax(A, 0, nroHijos+1));
            }
          // }
            nroHijos++;
        }
    }
    return valor;
}

int main()
{
    int cantidad, sol;

    cout << "Hello world!" << endl;

    //PARA N REINAS
   /* cout << "defina cantidad de reinas a ubicar: " << endl;
    cin >> cantidad;
    int Reinas[cantidad];
    sol = BackNReinas(Reinas, 0, cantidad);
    if (sol == 1)
        cout << "Se encontro solucion al problema" << endl;
    else
        cout << "No se encontro solucion al problema" << endl;
*/
    //PARA TA-TE-TI
    int tablero[9];
    for(int i=0; i<9; i++)
        tablero[i] = 0;
    imprime(tablero);
    sol = BackMiniMax(tablero, 0, 0);
    if (sol == 1)
        cout << "existe solucion factible" << endl;
    else
        cout << "no existe solucion factible" << endl;
    imprime(tablero);

    return 0;
}
