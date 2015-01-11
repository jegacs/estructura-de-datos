/* Cola Dinamica */
#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

#define type_ int
typedef type_ Dato;

struct elemento {
  struct elemento *sig;
  Dato dato;
};

typedef struct elemento elemento;

struct ColaDinamica { 
  int size; /* Numero de elementos */
  elemento *frente; /* Apuntador al elemento a sacar */
  elemento *fin; /* Final de la cola*/
};

typedef struct ColaDinamica ColaDinamica;

ColaDinamica *inicializa();
void agregar(ColaDinamica *, Dato);
void quitar(ColaDinamica *);
void mostrar(ColaDinamica *);

int main()
{
    
  ColaDinamica *cola = inicializa();
  
  /*inicializa(cola);
  agregar(cola, 2);
  agregar(cola, 5);
  agregar(cola, 6);
  agregar(cola, 10);
  mostrar(cola);
  
  quitar(cola);
  quitar(cola);
  quitar(cola);
  printf("\n");
  mostrar(cola);*/

  int opcion = 0;
  while(opcion != 4) {
    int in;
    printf("1. Insertar\n");
    printf("2. Eliminar\n");
    printf("3. Ver lista\n");
    printf("4. Salir\n");
    scanf("%i", &opcion);

    switch(opcion) {
    case 1:
      scanf("%i", &in);
      agregar(cola, in);
      break;
    case 2:
      quitar(cola);
      break;
    case 3:
      mostrar(cola);
      break;
    case 4:
      printf("Adios\n");
      break;
    default:
      printf("Invalido\n");
      break;
    }
    
  }
  
  return 0;
}

ColaDinamica *inicializa() 
{
  ColaDinamica *cola = (ColaDinamica *) malloc(sizeof(ColaDinamica *));
  cola->size = 0;
  cola->frente = cola->fin;
  return cola;
}

void agregar(ColaDinamica *cola, Dato dato) 
{
  if(cola->fin == NULL) {
    cola->fin = (elemento *) malloc(sizeof(elemento *));
    cola->fin->dato = dato;
    cola->frente = cola->fin;
    cola->size++;
    
  } else {
    elemento *nuevo;
    nuevo = (elemento *) malloc(sizeof(elemento *));
    nuevo->dato = dato;
    cola->fin->sig  = nuevo;
    cola->fin = nuevo;
    cola->size++;
  }
}

void quitar(ColaDinamica *cola)
{
  if(!vacia(cola)) {
    elemento *eliminado = cola->frente;
    cola->frente = cola->frente->sig;
    cola->size--;
    free(eliminado);
  }
}

void mostrar(ColaDinamica *cola)
{
  elemento *it = cola->frente;
  while(it != NULL) { 
  printf("%i ", it->dato);
  it = it->sig;
  }

  printf("\n");

}

bool vacia(ColaDinamica *cola)
{
  if(cola->size >  0)
    return false;
  else 
    return true;
}
