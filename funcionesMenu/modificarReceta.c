#include <stdio.h>
#include <stdlib.h>

#include "tdas/hashmap.h"
#include "tdas/extra.h"
#include "agregarReceta.h"
#include "eliminarReceta.h"

// Permite al usuario modificar los detalles de una receta existente.
void modificarReceta(HashMap *mapaRecetas, HashMap *mapaCategorias)
{
  limpiarPantalla(); // Limpia la pantalla para una visualización clara.
  AZUL_OSCURO
  printf("| ---------- Modificar Receta ---------- |\n");
  char *nombre = (char *) malloc(sizeof(char) * 50); // Reserva memoria para el nombre de la receta.
  BLANCO
  printf("Ingrese el nombre de la receta: ");
  fscanf(stdin, "%[^\n]49s", nombre); // Lee el nombre desde la entrada estándar.
  limpiarBuffer(); // Limpia el buffer de entrada.
  capitalizar(nombre); // Capitaliza el nombre para coincidir con el almacenado.

  Pair *pareja = searchMap(mapaRecetas, nombre); // Busca la receta en el mapa de recetas.
  if(pareja == NULL) // Si no se encuentra la receta
  {
    ROJO_OSCURO
    printf("NO SE ENCONTRO LA RECETA QUE SE INGRESO\n");
    BLANCO
    presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
    free(nombre); // Libera la memoria asignada al nombre.
    return;
  }
  free(nombre); // Libera la memoria asignada al nombre.

  tipoReceta *recetaOriginal = (tipoReceta *) pareja->value; // Obtiene la receta del par encontrado.
  tipoReceta *recetaCopia = copiarReceta(recetaOriginal); // Crea una copia de la receta para modificar.

  eliminarReceta(mapaRecetas, mapaCategorias, recetaCopia->nombre); // Elimina la receta original del sistema.

  // ---------- MODIFCAR EL NOMBRE ---------- //
  AZUL_OSCURO
  printf("| ---------- NOMBRE ---------- |\n");
  BLANCO
  printf("Desea modificar el nombre de la receta? (s/n) :");  // Solicita al usuario si desea modificar el nombre de la receta.
  char opcion;
  fscanf(stdin, "%c", &opcion); // Lee la opción del usuario.
  limpiarBuffer(); // Limpia el buffer de entrada.
  if(opcion == 's' || opcion == 'S') // Si la respuesta es afirmativa
  {
    char *cadena = (char *) malloc(sizeof(char) * 50); // Reserva memoria para el nuevo nombre.
    printf("Ingrese el nuevo nombre de la receta: "); 
    fscanf(stdin, "%[^\n]49s", cadena);  // Lee el nuevo nombre desde la entrada estándar.
    limpiarBuffer(); // Limpia el buffer de entrada.
    capitalizar(cadena); // Capitaliza el nuevo nombre.
    recetaCopia->nombre = strdup(cadena); // Asigna el nuevo nombre a la copia de la receta.
    free(cadena); // Libera la memoria del nombre temporal.
  }
  // ---------- MODIFCAR EL NOMBRE ---------- //

  // ---------- MODIFCAR LA CATEGORIA ---------- //
  AZUL_OSCURO
  printf("| ---------- CATEGORIA ---------- |\n");
  BLANCO
  printf("Desea modificar la categoria de la receta? (s/n) :");
  fscanf(stdin, "%c", &opcion); // Lee la opción del usuario.
  limpiarBuffer(); // Limpia el buffer de entrada.
  if(opcion == 's' || opcion == 'S') // Si la respuesta es afirmativa
  {
    char *cadena = (char *) malloc(sizeof(char) * 50); // Reserva memoria para la nueva categoría.
    printf("Ingrese la nueva categoria de la receta: ");
    fscanf(stdin, "%[^\n]49s", cadena); // Lee la nueva categoría desde la entrada estándar.
    limpiarBuffer(); // Limpia el buffer de entrada.
    capitalizar(cadena); // Capitaliza la nueva categoría.
    recetaCopia->categoria = strdup(cadena); // Asigna la nueva categoría a la copia de la receta.
    free(cadena); // Libera la memoria de la categoría temporal.
  }
  // ---------- MODIFCAR LA CATEGORIA ---------- //

  // ---------- MODIFCAR LOS INGREDIENTES ---------- //
  AZUL_OSCURO
  printf("| ---------- INGREDIENTES ---------- |\n");
  BLANCO
  printf("Desea modificar los ingredientes de la receta? (s/n) :");
  fscanf(stdin, "%c", &opcion);
  limpiarBuffer();
  if(opcion == 's' || opcion == 'S')
  {
    List *nuevosIngredientes = list_create(); // Crea una nueva lista para los ingredientes de la receta.
    poblarIngredientes(nuevosIngredientes); // Llena la lista de ingredientes interactuando con el usuario.
    recetaCopia->ingredientes = nuevosIngredientes;
  }
  // ---------- MODIFCAR LOS INGREDIENTES ---------- //

  // ---------- MODIFCAR LAS INSTRUCCIONES ---------- //
    AZUL_OSCURO
    printf("| ---------- INGREDIENTES ---------- |\n");
    BLANCO
    printf("Desea modificar las instrucciones de la receta? (s/n) :");
    fscanf(stdin, "%c", &opcion);
    limpiarBuffer();
    if(opcion == 's' || opcion == 'S')
    {
      List *nuevasInstrucciones = list_create(); // Crea una nueva lista para las instrucciones de la receta.
      poblarInstrucciones(nuevasInstrucciones);  // Llena la lista de instrucciones interactuando con el usuario.
      recetaCopia->instrucciones = nuevasInstrucciones; // Asigna la lista de instrucciones a la estructura de la receta.
    }
  // ---------- MODIFCAR LAS INSTRUCCIONES ---------- //

  insertMap(mapaRecetas, recetaCopia->nombre, recetaCopia); // Reinserta la receta modificada en el mapa de recetas.
  insertarEnMapaCategorias(mapaCategorias, recetaCopia); // Reinserta la receta modificada en el mapa de categorías.

  VERDE_OSCURO
  printf("LA RECETA SE MODIFICO CORRECTAMENTE\n");
  BLANCO
  presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
}