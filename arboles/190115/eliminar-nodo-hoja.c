#include <stdio.h>
#include <stdlib.h>

/*
  Ejercicio hecho en clase.
  Eliminacion de un nodo hoja.
  19/Enero/2015
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

ArbolBinario *crear(int); 		/* Inicializa el arbol */
NodoBinario *insertar_izq(NodoBinario *, int);
NodoBinario *insertar_der(NodoBinario *, int);
void imprimir(NodoBinario *);
void postorden(NodoBinario *);
void preorden(NodoBinario *);
void inorden(NodoBinario *);
void insertar_ordenados(NodoBinario *, int num);

#define MAX 11

int main(int argc, char **argv)
{
  ArbolBinario *bt = crear(40);
  int numeros[] = {20, 10, 30, 60, 60, 52, 45, 58, 90, 95};
  int i = 11;
  while(--i) {
    insertar_ordenados(bt->raiz, numeros[i]);
  }

  /* Se elimina el hijo izquierdo del nodo */
  printf("\n");
  inorden(bt->raiz);
  printf("\n");

  /* Eliminando el nodo 52, entonces, sube a sustituirlo el 45 */
  /* buscar_nodo... */
  /* eliminar_nodo_hoja... */
  return 0;
}

void insertar_ordenados(NodoBinario *raiz, int num)
{
  if(raiz != NULL) {
    if(raiz->dato >= num) {
      if(raiz->izq != NULL)
	insertar_ordenados(raiz->izq, num);
      else
	insertar_izq(raiz, num);
    } else {
      if(raiz->der != NULL)
	insertar_ordenados(raiz->der, num);
      else
	insertar_der(raiz, num);
    }
  }
  else {
    printf("\nObjeto no inicializado\n");
    exit(1);
  }
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

void postorden(NodoBinario *raiz)
{
  if(raiz != NULL) {
    postorden(raiz->izq);
    postorden(raiz->der);
    imprimir(raiz);
  }
}

ArbolBinario *crear(int dato)
{
  ArbolBinario *bt = (ArbolBinario *)malloc(sizeof(ArbolBinario));
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

