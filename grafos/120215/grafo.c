#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>
Grafo *inic_grafo() 
{
  Grafo *g = (Grafo *) malloc(sizeof(Grafo));
  g->vertices = 0;
  return g;
}

void agregar_vertice(Grafo *g, int info)
{
  /* Se usa un apuntador a apuntador para 
     poder modificar la variable original,
     si no se usara de esta manera, no 
     haría efecto en la variable original, 
     esto debido a que el apuntador simple 
     es pasado por valor, y es destruido 
     cuando sale del scope/ambito*/

  Vertice **it = &(g->inicio); /* Referencia del nodo */
  if((*it) == NULL) {
    *it = (Vertice *)malloc(sizeof(Vertice));
    (*it)->info = info;
  }
  else {
    
    while(*it != NULL) {
      it = &((*it)->sig);
    }
    *it = (Vertice *)malloc(sizeof(Vertice));
    (*it)->info = info;
  }
  
  g->vertices++;
}

Vertice *buscar_vertice(Grafo *g, int info)
{
  Vertice *it = g->inicio;
  while(it != NULL) {
    if(it->info == info) 
      return it;
    else
      it = it->sig;
  }
  return NULL;
}

void agregar_arco(Vertice *v, Vertice *v_ptr)
{
  Arco **it = &(v->arc); 	/* Apuntador doble, para poder modificar el contenido 
				   original.*/
  while(*it != NULL) {
    it = &((*it)->sig);
  }
  *it = (Arco *)malloc(sizeof(Arco));
  (*it)->vert = v_ptr;
  
}

void imprimir(Grafo *g) 
{
  Vertice *it = g->inicio;
  Arco *arc;
  while(it != NULL) {
    arc = it->arc;
    printf("Vertice %i -> ", it->info);
    while(arc != NULL) {
      printf("%i ->", arc->vert->info);
      arc = arc->sig;
    }
    printf("\n");
    it = it->sig;
  } 
		     
}
