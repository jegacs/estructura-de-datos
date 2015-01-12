#include <stdio.h>
#include <stdlib.h>
/*
  Ejercicio hecho en clase.
  Arbol binario 
  12/Enero/2015
  Gabriel Acosta
  Estructura de Datos
 */

struct NodoBinario {
  int dato;
  struct NodoBinario *izq;
  struct NodoBinario *der;
};

struct ArbolBinario {
  struct NodoBinario *raiz;
};

typedef struct ArbolBinario ArbolBinario;
typedef struct NodoBinario NodoBinario;

ArbolBinario *crear(ArbolBinario *, int); 		/* Inicializa el arbol */
NodoBinario *insertar_izq(NodoBinario *, int);
NodoBinario *insertar_der(NodoBinario *, int);
void imprimir(NodoBinario *);
void preorden(NodoBinario *);
void inorden(NodoBinario *);
int main()
{
  ArbolBinario *bt = crear(bt, 304);
  NodoBinario *nodo_actual = bt->raiz;

    
  nodo_actual = insertar_der(nodo_actual, 1995);
  nodo_actual = insertar_der(nodo_actual, 609);
  nodo_actual = insertar_der(nodo_actual, 300);
  
  nodo_actual = bt->raiz->der;
  nodo_actual = insertar_izq(nodo_actual, 876);

  nodo_actual = bt->raiz;
  nodo_actual = insertar_izq(nodo_actual, 550);
  nodo_actual = insertar_izq(nodo_actual, 143);

  nodo_actual = bt->raiz->izq;
  nodo_actual = insertar_der(nodo_actual, 2020);

  preorden(bt->raiz);
  printf("\n");
  inorden(bt->raiz);
  printf("\n");
  return 0;
}

void inorden(NodoBinario *raiz)
{
  if(raiz != NULL) {
    inorden(raiz->izq);
    imprimir(raiz);
    inorden(raiz->der);
  }
}

void preorden(NodoBinario *raiz)
{
  if(raiz != NULL) {
    imprimir(raiz);
    preorden(raiz->izq);
    preorden(raiz->der);
  }
}

ArbolBinario *crear(ArbolBinario *bt, int dato)
{
  bt = (ArbolBinario *)malloc(sizeof(ArbolBinario));
  bt->raiz = (NodoBinario *)malloc(sizeof(NodoBinario));
  bt->raiz->dato = dato;
  return bt;
}

NodoBinario *insertar_der(NodoBinario *padre, int dato) {
  padre->der = (NodoBinario *)malloc(sizeof(NodoBinario));
  padre->der->dato = dato;
  return padre->der;
}

NodoBinario *insertar_izq(NodoBinario *padre, int dato) {
  padre->izq = (NodoBinario *)malloc(sizeof(NodoBinario));
  padre->izq->dato = dato;
  return padre->izq;
}

void imprimir(NodoBinario *r)
{
  printf("%i ", r->dato);
}
