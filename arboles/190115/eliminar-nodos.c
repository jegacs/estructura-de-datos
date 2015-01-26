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
void eliminar_nodo(NodoBinario *, NodoBinario *); /* Devuelve 1 si existe, 0 si no */
NodoBinario *buscar_nodo(NodoBinario *, int);
NodoBinario *padre(NodoBinario *, NodoBinario *);
#define MAX 8 - 1

int main(int argc, char **argv)
{
  int entrada;
  NodoBinario *nodo;
  ArbolBinario *bt = crear(40); /* 40 es la raiz */
  int numeros[] = {0, 10, 30, 60, 52, 45, 58, 90
  }; /* Para agilizar el proceso, se introducen valores
	concretos.
     */
  int i = MAX;
  while(i > -1) {
    /* Debido a la naturaleza de la iteracion, los numeros
       del arreglo numeros se introducen inversamente a como
       estan dispuestos.
     */
    insertar_ordenados(bt->raiz, numeros[i]);
    --i;
  }

  
  printf("\n");
  inorden(bt->raiz);
  printf("\n");

  /* buscamos un nodo */
  printf("¿Que dato desea buscar? #:");
  scanf("%i", &entrada);
  if((nodo = buscar_nodo(bt->raiz, entrada)) != NULL) {
    printf("El nodo que buscas existe");
    printf("\n%i\n", nodo->dato);
    eliminar_nodo(bt->raiz, nodo);
  }

  printf("\n");
  inorden(bt->raiz);
  printf("\n");
  return 0;
}

void eliminar_nodo(NodoBinario *raiz, NodoBinario *nodo) {
  
  if(nodo->izq == NULL && nodo->der == NULL) { /* Nodo hoja */
    NodoBinario *p = padre(raiz , nodo);
    printf("\nNodo hoja\n");
    if(p->izq == nodo) {
      p->izq = NULL;
    }
    else {
      if(p->der == nodo)
    	p->der = NULL;
    }
  }
  else {
    if(nodo->izq != NULL && nodo->der != NULL) {
      /* Nodo con dos subarboles */
      printf("\nNodo con dos subarboles\n");
    }
    else {
      if((nodo->izq != NULL && nodo->der == NULL) || (nodo->izq == NULL && nodo->der != NULL)) {
	printf("\nNodo con un solo subarbol\n");
      }
    }
  }
    
    free(nodo);
}


NodoBinario *padre(NodoBinario *raiz, NodoBinario *hijo) { /* Busca el padre del nodo */
  NodoBinario *p = NULL;
  if(raiz != NULL) {
    if(raiz->izq == hijo) {
      p = raiz;
    
    }
    else {
      if(raiz->der == hijo) {
	p = raiz;
      }
      else {
	p = padre(raiz->izq, hijo);
	if(p == NULL)
	  //if(p->izq == NULL) 
	    p = padre(raiz->der, hijo);
      }
    }
  }
  return p;
}

NodoBinario *buscar_nodo(NodoBinario *nodo, int in)
{
  NodoBinario *aux;
  if(nodo != NULL) {
    if(nodo->dato == in) {
      return nodo;
    }
    else { 
      if(in > nodo->dato) {
	aux = buscar_nodo(nodo->der, in);
      }
      else {
	aux = buscar_nodo(nodo->izq, in);
	
      }
      
    }
    
  }
  else { 
    return NULL;
  }
  
  return aux;
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

