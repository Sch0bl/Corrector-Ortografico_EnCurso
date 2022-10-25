#ifndef __GLIST_H__
#define __GLIST_H__

typedef int (*FuncionComparadoraGList) (void* dato1, void* dato2);
typedef void (*FuncionDestructoraGlist)(void *dato);
typedef void *(*FuncionCopiaGlist)(void *dato);
typedef void (*FuncionVisitanteGlist)(void *dato);
typedef int (*PredicadoGlist) (void *dato); //Se declara puntero a void y luego se le puede pasar cualquier
                                       //puntero para poder usarla para cualquier tipo de dato.

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode *GList;

/**
 * Devuelve una lista vacía.
 */
GList glist_crear();

/**
 * Destruccion de la lista.
 */
void glist_destruir(GList lista, FuncionDestructoraGlist destruir);

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
GList glist_agregar_inicio(GList lista, void *dato, FuncionCopiaGlist copiar);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList lista, FuncionVisitanteGlist visitar);

/**
 * Dada una lista general, retorna una nueva lista
 * con los elementos que cumplen con el predicado.
 */
GList glist_filtrar(GList lista, FuncionCopiaGlist c, PredicadoGlist p);

void* glist_buscar(GList lista, void *dato, FuncionComparadoraGList compara);

#endif /* __GLIST_H__ */