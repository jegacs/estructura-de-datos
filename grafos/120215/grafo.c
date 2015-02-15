#include "grafo.h"
#include <stdlib.h>
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

