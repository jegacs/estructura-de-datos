/* 
   Gabriel Acosta
   Implementacion de una estructura de datos
   grafos (dirigido), para ejemplificar su funcionamiento.
*/

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"


int main() 
{
  //  Grafo grafo;
  Grafo *g = inic_grafo();
  
  agregar_vertice(g, 10);
  agregar_vertice(g, 12);
  agregar_vertice(g, 115);
  Vertice *v = g->inicio;
  while(v != NULL) {
    printf("Vertice %i\n", v->info);
    v = v->sig;
  }
  return 0;
}
