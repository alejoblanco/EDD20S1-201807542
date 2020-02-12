#include <iostream>
using namespace std;
#ifndef __LISTAS_H_INCLUDED__
#define __LISTAS_H_INCLUDED__

class Nodo{
private:
    int num;
    Nodo *siguiente;
    Nodo *anterior;
public:
    Nodo(void) { siguiente = anterior = NULL; }
 
    Nodo( int x , Nodo* sig = NULL , Nodo* ant = NULL )
    {
        num = x;
        siguiente = sig;
        anterior = ant;
    }
    void setNum(int x) { num = x; }
    void setAnterior(Nodo *ant) { anterior = ant; }
    void setSiguiente(Nodo *sig) { siguiente = sig; }
    int getNum()  { return num;}
    Nodo *getAnterior() { return anterior; }
    Nodo *getSiguiente() { return siguiente; }
};
class Lista
{
private:
    Nodo *lista;
public:
    Lista(void) { Inicializar(); } 
Nodo *Primero() { return lista; }
Nodo *Siguiente(Nodo *post) { return post->getSiguiente(); }
Nodo *Anterior(Nodo *post) { return post->getAnterior(); }
Nodo *Ultimo() {Nodo *aux = lista; if ( !Vacia() ) { while ( aux->getSiguiente() ) { aux = aux->getSiguiente(); } }return aux;}

void Inicializar() { lista = NULL; }
    bool Vacia() { return lista==NULL; }
    void Mostrar();
    void Insertar(int x, Nodo* post = NULL);
};

void Lista::Insertar(int x, Nodo* post)
{
    Nodo* aux;
    Nodo* tempo = new Nodo(x);
        if ( Vacia() ){
                lista = tempo;
        }else{
                if ( post == Primero() ){
                        aux = Primero();
                        aux->setAnterior(tempo);
                        tempo->setSiguiente(aux);
                        lista = tempo;
                }else if ( post == NULL ){
 
                        aux = Ultimo();
                        aux->setSiguiente(tempo);
                        tempo->setAnterior(aux);
                }else{
                        aux = Primero();
                        while ( aux ){
                                if ( aux == post ){
                                        Anterior(aux)->setSiguiente( tempo );
                                        tempo->setAnterior( Anterior(aux) );
                                        tempo->setSiguiente( aux );
                                        aux->setAnterior( tempo );
 
                                }else {
                                    aux = aux->getSiguiente();}
                        }
                }
        }
}
