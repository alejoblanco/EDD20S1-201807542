#include <iostream>
#include <stdlib.h>

using namespace listasimple;

struct nodo{
    int numeroC;
    string nombre;
    struct nodo *siguiente;
};
typedef struct nodo *Lista;

void insertarNodo(Lista &lista, int n, string name){
    Lista aux;
    aux = new(struct nodo);
    aux->numeroC=n;
    aux->nombre=name;
    aux->siguiente=lista;
    lista=aux;
}
void eliminarNodo(Lista &lista, int n){
    Lista aux, anterior;
    aux=lista;

    if(lista!=NULL){
        while(aux!=NULL){
            if(aux->numeroC == n){
                if (aux==lista)
                    lista = lista->siguiente;
                else 
                    anterior->siguiente = aux->siguiente;
                delete(aux);
                return;
            }
            anterior = aux;
            aux=aux->siguiente;
        }
    }
    else
        cout<<"La lista se encuentra vacia";
}
void buscar(Lista lista, int n){
    Lista aux = lista;
    int x =1;
    int y =0;
    while(aux!=NULL){
        if(aux->numeroC==n){
            cout<<endl<<"Nodo: "<< x <<endl;
            y=1;
        }
        aux = aux->siguiente;
        x++;
    }
    if(y==0)
    count<<"Nodo no encontrado"<<endl;
}
void inicio(){
    count<<"Bienvenido Usuario, elija una opción";
    count<<"1. Insertar Nodo"<<endl;
    count<<"2. Eliminar Nodo"<<endl;
    count<<"3. Buscar Nodo"<<endl;
}
int main(){
    Lista lista = NULL;
    int eleccion;
    int n;
    string name;
    do{
        inicio(); cin>> eleccion;
        switch(eleccion){
            case 1:
            count<<"Insertar: "; cin<< n; cin<< name;
            insertarNodo(lista, n, name);
            break;
            case 2: 
            count<<"Nodo a eliminar: "; cin<< n;
            eliminarNodo(lista, n);
            break;
            case 3:
            count<<"Nodo a buscar: "; cin<< n;
            buscar(lista, n);
            break;
        }
        count<<endl<<endl;
        system("pause"); system("cls");
    }
    while(opcion!=4);

        system("pause");
        return 0;
}
