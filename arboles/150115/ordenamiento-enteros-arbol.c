#include <stdio.h>
#include <stdlib.h>
/*
  Ejercicio hecho en clase.
  Insercion de elementos a un arbol por orden ascendente. 
  15/Enero/2015
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
#define MAX 5
ArbolBinario *crear(int); 		/* Inicializa el arbol */
NodoBinario *insertar_izq(NodoBinario *, int);
NodoBinario *insertar_der(NodoBinario *, int);
void imprimir(NodoBinario *);
void postorden(NodoBinario *);
void preorden(NodoBinario *);
void inorden(NodoBinario *);
void insertar_ordenados(NodoBinario *, int num);
int main()
{
  int num[MAX] = {9,3, 5, 45, 876};    
  
  ArbolBinario *bt = crear(num[0]);
  int i = MAX;
  while(--i) {
    insertar_ordenados(bt->raiz, num[i]);
    printf("%i", i);
  }
  printf("\npreorden: \n");
  preorden(bt->raiz);
  printf("\ninorden: \n");
  inorden(bt->raiz);
  printf("\npostorden: \n");
  postorden(bt->raiz);
  printf("\n");
  return 0;
}

void insertar_ordenados(NodoBinario *raiz, int num)
{
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
