#include "glist.h"
#include <assert.h>
#include <stdlib.h>


/**
 * Devuelve una lista vacía.
 */
GList glist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void glist_destruir(GList list, FuncionDestructoraGlist destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList list) { return (list == NULL); }

/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
GList glist_agregar_inicio(GList list, void *data, FuncionCopiaGlist copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList list, FuncionVisitanteGlist visit) {
  GList temp = list;
  for (; temp != NULL; temp = temp->next)
    visit(temp->data);
}

/**
 * Filtrado de la lista en base al predicado dado.
 */
GList glist_filtrar(GList lista, FuncionCopiaGlist c, PredicadoGlist p){
  GList lista_filtrada = glist_crear(), temp = lista;

  for(;temp != NULL;temp = temp->next){ 
    if(p(temp->data)){
      lista_filtrada = glist_agregar_inicio(lista_filtrada, temp->data, c);
    }
  }
  return lista_filtrada;
}

void* glist_buscar(GList lista, void* dato, FuncionComparadoraGList compara){
  GList nodo = lista;
  for(; nodo != NULL; nodo = nodo->next){
    if (!compara(dato, lista->data))
      return dato;
  }
  return NULL;
}