#include "grafo.h"
#include <stdlib.h>
Grafo *inic_grafo() 
{
  Grafo *g = (Grafo *) malloc(sizeof(Grafo));
  g->vertices = 0;
  return g;
}

void agregar_vertice(Grafo *g, int info)
/* Necesita ser enviado un apuntador a apuntador, declarando
   solamente un apuntador a grafo, la informacion del puntero
   es perdida al regresar de la funcion. Debido a que si se quiere
   cambiar el apuntador, el apuntador sera destruido al finalizar
   la llamada a la funcion, debido a que el apuntador realmente 
   se pasa por valor.*/
{
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
