#include <stdio.h>
#include <stdlib.h>

#include "tdas/hashmap.h"
#include "tdas/extra.h"

// Muestra todas las recetas almacenadas en el mapa de recetas, listando sus nombres.
void mostrarRecetasNombre(HashMap *mapaRecetas)
{
  limpiarPantalla(); // Limpia la pantalla para mostrar claramente los nombres de las recetas.
  AZUL_OSCURO
  printf("| ---------- Mostrar Recetas ---------- |\n");
  Pair *pareja = firstMap(mapaRecetas); // Obtiene el primer par (nombre-receta) del mapa.
  while(pareja != NULL) // Itera sobre todos los pares en el mapa.
  {
    tipoReceta *receta = pareja->value; // Extrae la receta del par.
    printf("  -%s\n", receta->nombre); // Imprime el nombre de la receta.
    pareja = nextMap(mapaRecetas); // Avanza al siguiente par en el mapa.
  }
  BLANCO;
  presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
}

// Muestra las recetas organizadas por categorías almacenadas en el mapa de categorías.

void mostrarRecetasCategoria(HashMap *mapaCategorias)
{
  limpiarPantalla(); // Limpia la pantalla para una presentación clara.
  AZUL_OSCURO
  printf("| ---------- Mostrar Recetas por Categorias ---------- |\n");
  Pair *pareja = (Pair *)firstMap(mapaCategorias); // Obtiene el primer par (categoría-lista de recetas) del mapa.

  while(pareja != NULL) // Itera sobre todos los pares en el mapa.
  {
    char *categoria = (char *) pareja->key; // Extrae la categoría del par.
    List *lista = (List *) pareja->value; // Extrae la lista de recetas asociada a la categoría.
    printf("Categoria: %s\n", categoria); // Imprime la categoría.

    tipoReceta *receta = list_first(lista); // Obtiene la primera receta de la lista.
    while(receta != NULL) // Itera sobre todas las recetas en la lista.
    {
      printf("  -%s\n", receta->nombre); // Imprime el nombre de la receta.
      receta = list_next(lista); // Avanza a la siguiente receta en la lista.
    }

    pareja = nextMap(mapaCategorias); // Avanza al siguiente par en el mapa.
  }
  BLANCO;
  presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
}
