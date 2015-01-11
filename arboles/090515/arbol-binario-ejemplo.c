#include <stdio.h>
#include <stdlib.h>
/*
  Ejercicio hecho en clase.
  Arbol binario 
   9/Enero/2015
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
  
  printf("%i\n", bt->raiz->izq->izq->dato);
  return 0;
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
