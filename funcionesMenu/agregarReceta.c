#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tdas/list.h"
#include "tdas/hashmap.h"
#include "tdas/extra.h"

// Interactúa con el usuario para agregar ingredientes a una lista hasta que el usuario ingrese "FIN".
void poblarIngredientes(List *ingredientes)
{
  AZUL_OSCURO
  printf("| ----------- Ingredientes ----------- |\n");
  ROJO_OSCURO
  printf("Si no quiere ingresar mas ingredientes, ingrese FIN\n");
  BLANCO
  while (1) // Bucle infinito hasta que se ingrese "FIN".
  {
    printf("Ingrese su ingrediente: ");
    char *nombre = (char *) malloc(sizeof(char) * 50); // Reserva memoria para el nombre del ingrediente.
    fscanf(stdin, "%[^\n]49s", nombre); // Lee el nombre del ingrediente del usuario.
    limpiarBuffer(); // Limpia el buffer de entrada para evitar problemas de lectura.
    if ( !strcmp(nombre, "FIN") || !strcmp(nombre, "fin") || !strcmp(nombre, "Fin") ) break; // Si el usuario ingresa "FIN", termina el bucle.


    printf("Ingrese la cantidad del ingrediente: "); 
    char *cantidad = (char *) malloc(sizeof(char) * 50); // Reserva memoria para la cantidad del ingrediente.
    fscanf(stdin, "%[^\n]49s", cantidad); // Lee la cantidad del ingrediente del usuario.
    limpiarBuffer(); // Limpia el buffer de entrada para evitar problemas de lectura.

    printf("%s de %s\n", cantidad, nombre);
    printf("\n");

    tipoIngrediente *ingrediente = (tipoIngrediente *) malloc(sizeof(tipoIngrediente)); // Reserva memoria para la estructura del ingrediente.
    ingrediente->ingrediente = strdup(nombre); // Duplica el nombre del ingrediente para guardarlo en la estructura.
    ingrediente->cantidad = strdup(cantidad); // Duplica la cantidad del ingrediente para guardarlo en la estructura.
    free(nombre); // Libera la memoria del nombre temporal.
    free(cantidad); // Libera la memoria de la cantidad temporal.
    list_pushBack(ingredientes, ingrediente); // Agrega el ingrediente al final de la lista.
  }
}

// Interactúa con el usuario para agregar instrucciones a una lista de instrucciones.
void poblarInstrucciones(List *instrucciones)
{
  AZUL_OSCURO
  printf("| ---------- Instrucciones ---------- |\n");
  ROJO_OSCURO
  printf("Si no quiere ingresar mas instrucciones, ingrese FIN\n");
  BLANCO
  int paso = 1;  // Inicializa el contador de pasos.
  while (1)  // Bucle infinito hasta que se ingrese "FIN".
  {

    printf("Ingrese su instruccion: ");
    char *texto = (char *) malloc(sizeof(char) * 100); // Reserva memoria para el texto de la instrucción.
    fscanf(stdin, "%[^\n]99s", texto); // Lee el texto de la instrucción del usuario.
    limpiarBuffer();
    if ( !strcmp(texto, "FIN") || !strcmp(texto, "fin") || !strcmp(texto, "Fin") ) break; // Si el usuario ingresa "FIN", termina el bucle.
    printf("Paso %i instruccion: %s\n", paso, texto);
    tipoInstruccion *instruccion = (tipoInstruccion *) malloc(sizeof(tipoInstruccion)); // Reserva memoria para la estructura de instrucción.
    instruccion->instruccion = strdup(texto); // Duplica el texto de la instrucción para guardarlo en la estructura.
    free(texto); // Libera la memoria del texto temporal.
    instruccion->paso = paso; // Asigna el número del paso actual a la instrucción.
    list_pushBack(instrucciones, instruccion); // Agrega la instrucción al final de la lista.
    paso++; // Incrementa el número del paso para la próxima instrucción.
    printf("\n");
  }
}

// Inserta una receta en el mapa de categorías.
void insertarEnMapaCategorias(HashMap *mapaCategorias, tipoReceta *receta)
{
  char *key = strdup(receta->categoria); // Duplica la categoría de la receta para usarla como clave en el mapa.
  Pair *pareja = searchMap(mapaCategorias, key); // Busca la categoría en el mapa de categorías.

  if (pareja == NULL) // Si la categoría no existe en el mapa
  {
    List *lista = list_create(); // Crea una nueva lista para almacenar recetas de esta categoría.
    list_pushBack(lista, receta); // Añade la receta a la nueva lista.
    insertMap(mapaCategorias, key, lista); // Inserta la nueva lista en el mapa de categorías.
  }
  else // Si la categoría ya existe
  {
    List *lista = (List *)pareja->value; // Obtiene la lista de recetas asociada a esta categoría.
    list_pushBack(lista, receta); // Añade la receta a la lista existente.
    free(key); // Libera la memoria de la clave duplicada ya que no es necesaria.
  }


}

// Agrega una nueva receta al mapa de recetas y al mapa de categorías después de interactuar con el usuario para obtener los datos.
void agregarRecetas(HashMap *mapaRecetas, HashMap *mapaCategorias)
{
  limpiarPantalla();
  AZUL_OSCURO
  printf("| ----------  Agregar Receta ---------- |\n");
  tipoReceta *receta = (tipoReceta *) malloc(sizeof(tipoReceta)); // Asigna memoria para una nueva receta.
  // NOMBRE DE LA RECETA //
  char *nombre = (char *) malloc(sizeof(char) * 50); // Asigna memoria para el nombre de la receta.
  BLANCO
  printf("Ingrese el nombre de su receta: ");
  fscanf(stdin, "%[^\n]49s", nombre); // Lee el nombre desde la entrada estándar.
  limpiarBuffer(); // Limpia el buffer de entrada para evitar errores en lecturas futuras.
  capitalizar(nombre); // Capitaliza el nombre de la receta.
  receta->nombre = strdup(nombre); // Guarda el nombre capitalizado en la estructura de la receta.
  free(nombre); // Libera la memoria asignada para el nombre temporal.
  // NOMBRE DE LA RECETA //

  // CATEGORIA DE LA RECETA //
  char *categoria = (char *) malloc(sizeof(char) * 50); // Asigna memoria para la categoría de la receta.
  printf("Ingrese la categoria de su receta: ");
  fscanf(stdin, "%[^\n]49s", categoria);  // Lee la categoría desde la entrada estándar.
  limpiarBuffer(); // Limpia el buffer de entrada.
  capitalizar(categoria); // Capitaliza la categoría.
  receta->categoria = strdup(categoria); // Guarda la categoría capitalizada en la estructura de la receta.
  free(categoria); // Libera la memoria asignada para la categoría temporal.
  // CATEGORIA DE LA RECETA //

  // INGREDIENTES DE LA RECETA //
  List *ingredientes = list_create(); // Crea una nueva lista para los ingredientes de la receta.
  poblarIngredientes(ingredientes); // Llena la lista de ingredientes interactuando con el usuario.
  receta->ingredientes = ingredientes; // Asigna la lista de ingredientes a la estructura de la receta.
  // INGREDIENTES DE LA RECETA //

  // INSTRUCCIONES DE LA RECETA //
  List *instrucciones = list_create(); // Crea una nueva lista para las instrucciones de la receta.
  poblarInstrucciones(instrucciones);  // Llena la lista de instrucciones interactuando con el usuario.
  receta->instrucciones = instrucciones; // Asigna la lista de instrucciones a la estructura de la receta.
  // INSTRUCCIONES DE LA RECETA //

  insertMap(mapaRecetas, receta->nombre, receta); // Inserta la receta en el mapa de recetas, usando el nombre como clave.
  insertarEnMapaCategorias(mapaCategorias, receta); // Inserta la receta en el mapa de categorías.
  VERDE_OSCURO
  printf("RECETA GUARDADA EXITOSAMENTE\n");
  BLANCO
  presionaParaContinuar(); // Pausa la ejecución hasta que el usuario presione una tecla.
  return;
}