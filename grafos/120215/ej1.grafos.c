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
  
  Vertice *v1 = buscar_vertice(g, 10);
  Vertice *v2 = buscar_vertice(g, 12);

  agregar_arco(v1, v2);
  
  imprimir(g);

  return 0;
}
