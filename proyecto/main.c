#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNODOS 5
#define INF 1000000 		/* La imposibilidad */
#define MIEMBRO	1		/* 1 si el nodo es miembro del arreglo de vertices*/
#define NOMIEMBRO 0		/* ya revisados, 0 si no*/
struct Vertice {
  char n;
};
/* Encuentra el peso minimo para llegar de un nodo a otro. */
void caminominimo(unsigned int matrix[MAXNODOS][MAXNODOS],
		  int, int,
		  int *, int []);
void recuperacamino(int, int, int []);
int main()
{
  int anteriores[MAXNODOS];	/* Se guardan los nodos que ya han sido procesados*/
  int i, pd;
      
  unsigned int MatrizAdy[MAXNODOS][MAXNODOS] = {
    { INF, 10, 5, 1, INF},
    { INF, INF, INF, INF, 15},
    { INF, INF, INF, INF, 32},
    { INF, INF, INF, INF, INF},
    { INF, INF, INF, INF, INF}    
  };

  caminominimo(MatrizAdy, 0, 4, &pd, anteriores);
  printf("La distancia mas corta es %d\n", pd);
  printf("Los caminos son ");
  recuperacamino(4, 0, anteriores);
  printf("\n");
  return 0;
}
void recuperacamino(int v, int s, int anteriores[])
{
  int anterior = anteriores[v];
  if(v != s) {
    recuperacamino(anterior, s, anteriores);
    printf(" -> V%d", v);
  } else {
    printf("V%d", s);
  }
  
}
void caminominimo(unsigned int matrix[MAXNODOS][MAXNODOS],
		  int s, int t,
		  int *pd, int precede[])
{
  int distance[MAXNODOS], perm[MAXNODOS];
  int current, i, k, dc;
  int smalldist, newdist;

  for(i = 0; i < MAXNODOS; i++) {
    perm[i] = NOMIEMBRO;
    distance[i] = INF;
  }
  perm[s] = MIEMBRO;
  distance[s] = 0; 		/* La distancia del nodo s a si mismo, es 0*/
  current = s;
  while(current != t) {
    smalldist = INF;
    dc = distance[current];
    for(i = 0; i < MAXNODOS; i++) { 
      if(perm[i] == NOMIEMBRO) {
	newdist = dc + matrix[current][i];
	if(newdist < distance[i]) {
	  /* La distancia de s a i, a traves de current */
	  /* es mas pequenia que distance[i] */
	  distance[i] = newdist;
	  precede[i] = current;
	}
	/* determinar la distancia mas pequenia */
	if(distance[i] < smalldist) {
	  smalldist = distance[i];
	  k = i;
	}
      }
    }
    current = k;
    perm[current] = MIEMBRO;
  }
  *pd = distance[t];
}
