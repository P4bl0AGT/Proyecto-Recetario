#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tdas/hashmap.h"
#include "tdas/extra.h"


// Función que elimina una receta específica del mapa de categorías.
void eliminarMapaCategorias(HashMap *mapaCategorias, char* nombre, char* categoria)
{
  Pair *pareja = searchMap(mapaCategorias, categoria); // Busca en el mapa de categorías utilizando la categoría proporcionada como clave.
  if(pareja == NULL) return; // Si no encuentra ninguna pareja, significa que la categoría no existe y termina la función.
  List *recetas = pareja->value; // Obtiene la lista de recetas asociada con la categoría encontrada.
  // Comienza a iterar desde la primera receta en la lista.
  tipoReceta *pivote = list_first(recetas);
  while(pivote != NULL) // Continúa mientras haya recetas en la lista.
  {
    if (strcmp(pivote->nombre, nombre) == 0) // Compara el nombre de la receta actual con el nombre proporcionado.
    {
      list_popCurrent(recetas); // Si encuentra una coincidencia, elimina la receta actual de la lista.
      if(list_size(recetas) == 0)  // Después de eliminar, verifica si la lista está vacía.
      {
        eraseMap(mapaCategorias, categoria); // Si la lista está vacía, también elimina la entrada del mapa de categorías.
        free(categoria); // Libera la memoria asociada con la clave de categoría.
      }
      return;
    }
    pivote = list_next(recetas); // Avanza a la siguiente receta en la lista si la receta actual no coincide.
  }

}


// Elimina una receta específica del sistema, incluyendo sus referencias en el mapa de categorías.
void eliminarReceta(HashMap *mapaRecetas, HashMap *mapaCategorias, char *centinela)
{
  char *nombre;

  if(strcmp(centinela, "nohaynombre") == 0) // Si no se proporcionó un nombre previamente
  {
    limpiarPantalla();  // Limpia la pantalla para mostrar claramente la interfaz de eliminación.
    AZUL_OSCURO
    printf("| ---------- Eliminar Receta ---------- |\n");
    nombre = (char *) malloc(sizeof(char) * 50); // Reserva memoria para el nombre de la receta.
    BLANCO
    printf("Ingrese el nombre de la receta: ");
    fscanf(stdin, "%[^\n]49s", nombre); // Lee el nombre desde la entrada estándar.
    limpiarBuffer(); // Limpia el buffer de entrada.
    capitalizar(nombre); // Capitaliza el nombre para coincidir con el formato almacenado.
  }
  else
    nombre = strdup(centinela); // Utiliza el nombre ya proporcionado.

  Pair *pareja = searchMap(mapaRecetas, nombre); // Busca la receta en el mapa utilizando el nombre como clave.
  if(pareja != NULL) // Si encuentra la receta
  {
    tipoReceta *receta = pareja->value; // Extrae la receta del par encontrado.
    eraseMap(mapaRecetas, nombre); // Elimina la receta del mapa de recetas.
    eliminarMapaCategorias(mapaCategorias, receta->nombre, receta->categoria); // Elimina la receta del mapa de categorías.
    if(strcmp(centinela, "nohaynombre") == 0) // Si el nombre fue ingresado durante esta función
    {
      VERDE_OSCURO
      printf("LA RECETA %s SE ELIMINO CORRECTAMENTE\n", nombre); // Informa al usuario de la eliminación exitosa.
      BLANCO
      presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
    }

    free(nombre); // Libera la memoria reservada para el nombre.
    return;
  }
  ROJO_OSCURO
  printf("NO SE ENCONTRO LA RESETA QUE SE INGRESO\n");
  BLANCO
  presionaParaContinuar();
  free(nombre);
  return;
}
