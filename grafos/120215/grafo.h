struct Arco {
  struct Vertice *vert;
  struct Arco *sig;
};

struct Vertice {
  int info;
  struct Vertice *sig;
  struct Arco *arc;
};

struct Grafo {
  struct Vertice *inicio;	/* Apuntador al primero vertice del arreglo de nodos */
  int vertices; 	       	/* Numero de vertices del grafo*/
};

typedef struct Grafo Grafo;
typedef struct Arco Arco;
typedef struct Vertice Vertice;

Grafo *inic_grafo();
void agregar_arco(Vertice *, Vertice *); /* Recibe el grafo, el vertice donde crear el arco  
						     y el vertice a donde apunta el arco.*/
void agregar_vertice(Grafo *, int); /* Recibe el grafo, y agrega un nuevo vertice con el dato int  */
void imprimir(Grafo *);
Vertice *buscar_vertice(Grafo *, int);
