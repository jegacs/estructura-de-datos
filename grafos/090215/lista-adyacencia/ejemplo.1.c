#include <stdio.h>
#include <stdlib.h>

struct Arista {
  int dato;
  struct Arista *siga;
};

struct Vertice {
  int dato;
  struct Vertice *sig;
  struct Arista *siga;
};

struct Vertice *crear_nodo_raiz(int);
void mostrar(struct Vertice*);


int main()
{
  struct Vertice *v = crear_nodo_raiz(1);
  v->sig = crear_nodo_raiz(2);
  v->sig->sig = crear_nodo_raiz(3);
  v->sig->sig->sig = crear_nodo_raiz(4);
  v->sig->sig->sig->sig = crear_nodo_raiz(5);
  
  mostrar(v);
    
  return 0;
}

struct Vertice *crear_nodo_raiz(int d)
{
  struct Vertice *v = (struct Vertice *)malloc(sizeof(struct Vertice));
  v->sig = (struct Vertice *)malloc(sizeof(struct Vertice));
  v->siga = NULL;
  v->dato = d;
}

void mostrar(struct Vertice *v)
{
  struct Vertice *it = v;
  while(v->sig != NULL) {
    printf("%i ", v->dato);
    v = v->sig;
  }
  printf("\n");
}
