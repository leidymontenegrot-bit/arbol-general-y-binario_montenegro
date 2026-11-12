#include <iostream>
using namespace std;


// 1. Estructura del nodo del árbol
struct Nodo {
    int dato;
    Nodo* izquierdo;
    Nodo* derecho;
};


// Función para crear un nuevo nodo
Nodo* crearNodo(int n) {
    Nodo* nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->izquierdo = NULL;
    nuevo_nodo->derecho = NULL;
    return nuevo_nodo;
}


// 2. Función para insertar elementos en el árbol binario de búsqueda
Nodo* insertar(Nodo* arbol, int n) {
    if (arbol == NULL) {
        return crearNodo(n);
    }
    if (n < arbol->dato) {
        arbol->izquierdo = insertar(arbol->izquierdo, n);
    } else {
        arbol->derecho = insertar(arbol->derecho, n);
    }
    return arbol;
}


// 3. Recorrido en Preorden: Raíz -> Izquierda -> Derecha
void preOrden(Nodo* arbol) {
    if (arbol == NULL) return;
    cout << arbol->dato << " ";
    preOrden(arbol->izquierdo);
    preOrden(arbol->derecho);
}


// 4. Recorrido en Inorden: Izquierda -> Raíz -> Derecha
void inOrden(Nodo* arbol) {
    if (arbol == NULL) return;
    inOrden(arbol->izquierdo);
    cout << arbol->dato << " ";
    inOrden(arbol->derecho);
}


// 5. Recorrido en Posorden: Izquierda -> Derecha -> Raíz
void posOrden(Nodo* arbol) {
    if (arbol == NULL) return;
    posOrden(arbol->izquierdo);
    posOrden(arbol->derecho);
    cout << arbol->dato << " ";
}


// Función principal para probar el árbol
int main() {
    Nodo* arbol = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};


    // Insertar valores en el árbol
    for (int v : valores) {
        arbol = insertar(arbol, v);
    }


    cout << "\nRecorrido en Preorden (Raiz -> Izq -> Der): ";
    preOrden(arbol);


    cout << "\n\nRecorrido en Inorden (Izq -> Raiz -> Der): ";
    inOrden(arbol);


    cout << "\n\nRecorrido en Posorden (Izq -> Der -> Raiz): ";
    posOrden(arbol);
    cout << endl;


    return 0;
}