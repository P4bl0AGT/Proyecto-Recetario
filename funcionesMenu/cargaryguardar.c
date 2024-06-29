#include <stdio.h>
#include <stdlib.h>
#include "cargaryguardar.h"
#include "string.h"
#include "tdas/hashmap.h"
#include "tdas/extra.h"
#include "agregarReceta.h"

// Guarda todas las recetas almacenadas en el mapa en un archivo especificado.
void guardarRecetas(HashMap *mapaRecetas, const char* nombreArchivo){
  FILE *archivo = fopen(nombreArchivo, "w"); // Abre el archivo especificado en modo de escritura.
  if(archivo == NULL){ // Verifica si la apertura del archivo falló.
    perror("No se pudo abrir el archivo"); // Imprime un mensaje de error.
    return;
  }
  Pair *pareja = firstMap(mapaRecetas); // Obtiene el primer par del mapa de recetas.
  while(pareja != NULL) // Itera a través de todas las recetas en el mapa.
  { 
    tipoReceta *receta = pareja->value; // Obtiene la receta del par actual.
    // Escribe los detalles de la receta en el archivo.
    fprintf(archivo, "# ------ Nombre de la receta ------ #\n%s\n", receta->nombre);
    fprintf(archivo, "# ----------- Categoria ----------- #\n%s\n", receta->categoria);

    tipoIngrediente *ingAux = list_first(receta->ingredientes); // Obtiene el primer ingrediente de la lista.
    fprintf(archivo, "# --------- Ingredientes ---------- #\n");
    while(ingAux != NULL){ // Itera a través de todos los ingredientes de la receta.
      fprintf(archivo, "%s de %s\n", ingAux->cantidad, ingAux->ingrediente); // Escribe cada ingrediente en el archivo.
      ingAux = list_next(receta->ingredientes); // Avanza al siguiente ingrediente.
    }
    tipoInstruccion *intAux = list_first(receta->instrucciones); // Obtiene la primera instrucción de la lista.
    fprintf(archivo, "# --------- Instrucciones --------- #\n"); 
    while(intAux != NULL){ // Itera a través de todas las instrucciones de la receta.
      fprintf(archivo, "%i.- %s\n", intAux->paso, intAux->instruccion); // Escribe cada instrucción en el archivo.
      intAux = list_next(receta->instrucciones); // Avanza a la siguiente instrucción.
    }
    fprintf(archivo, "# -------------- FIN -------------- #\n\n"); // Escribe un separador para la próxima receta.
    pareja = nextMap(mapaRecetas); // Avanza al siguiente par en el mapa.
  }
  fclose(archivo); // Cierra el archivo una vez completada la escritura.
}

void separarConLimitadorDe(char *cadena, char **cantidad, char**ingrediente)
{
  size_t largo = strlen(cadena); //largo de la cadena original

  char *cadenaPostDe = strstr(cadena, " de "); // obtener cadena despues del separador " de "
  size_t largoPostDe = strlen(cadenaPostDe); // obtener el largo de la cadena despues del separador " de "
  size_t largoPreDe = largo - largoPostDe; // obtener el largo de la cadena desde el inicio hasta el separador " de "

  *cantidad = (char *) malloc(sizeof(char) * (largoPreDe + 1)); // asignar memoria
  strncpy(*cantidad, cadena, largoPreDe); //copiar la cadena original desde el principio hasta el largo osea hasta el limitador " de "
  (*cantidad)[largoPreDe] = '\0'; // asegurarnos que termine con caracter nulo

  *ingrediente = (char *) malloc(sizeof(char) * (largoPostDe + 1)); // asginar memoria
  strcpy(*ingrediente, cadenaPostDe + 4); // copiar desde el " de "  hasta el final de la cadena, por el el +4 porque quiero copiar la cadena despues de los primero 4 caracteres
  (*ingrediente)[largoPostDe] = '\0'; // asegurarnos que termine con caracter nulo
}

// Carga recetas desde un archivo especificado y las agrega al mapa de recetas y categorías.
void cargarRecetas(HashMap *mapaRecetas, HashMap *mapaCategorias, const char* nombreArchivo)
{
  FILE *archivo = fopen(nombreArchivo, "r"); // Abre el archivo en modo de lectura.
  if (archivo == NULL) // Verifica si la apertura del archivo falló.
  {  
    perror("No se pudo abrir el archivo"); // Imprime un mensaje de error.
    return;
  }

  char *linea = (char *) malloc(sizeof(char) * 256); // Asigna memoria para la línea de lectura.
  while(fscanf(archivo, "%255[^\n]\n", linea) != EOF) // Lee líneas del archivo hasta el final del mismo.
  {
    tipoReceta *receta = (tipoReceta *) malloc(sizeof(tipoReceta)); // Crea una estructura de receta.
    receta->ingredientes = list_create(); // Inicializa la lista de ingredientes.
    receta->instrucciones = list_create(); // Inicializa la lista de instrucciones.

    if(strcmp(linea, "# ------ Nombre de la receta ------ #") == 0)
    {
      fscanf(archivo, "%255[^\n]\n", linea);  // Lee el nombre de la receta.
      receta->nombre = strdup(linea); // Asigna el nombre leído a la estructura de la receta.
      fscanf(archivo, "%255[^\n]\n", linea); // Prepara la siguiente lectura.
    }

    if(strcmp(linea, "# ----------- Categoria ----------- #") == 0)
    {
      fscanf(archivo, "%255[^\n]\n", linea); // Lee la categoría de la receta.
      receta->categoria = strdup(linea); // Asigna la categoría leída a la estructura de la receta.
      fscanf(archivo, "%255[^\n]\n", linea); // Prepara la siguiente lectura.
    }

    if(strcmp(linea, "# --------- Ingredientes ---------- #") == 0)
    {
      while(1)
      {
        fscanf(archivo, "%255[^\n]\n", linea); // Lee un ingrediente.
        if(strcmp(linea, "# --------- Instrucciones --------- #") == 0) break; // Si se alcanza el inicio de las instrucciones, detiene la lectura de ingredientes.
        tipoIngrediente *ingrediente = (tipoIngrediente *) malloc(sizeof(tipoIngrediente)); // Crea un nuevo ingrediente.
        separarConLimitadorDe(linea, &ingrediente->cantidad, &ingrediente->ingrediente); // Separa la cantidad del nombre del ingrediente.
        list_pushBack(receta->ingredientes, ingrediente); // Añade el ingrediente a la lista de ingredientes.
      }
    }

    if(strcmp(linea, "# --------- Instrucciones --------- #") == 0)
    {
      int paso = 1; // Inicializa el contador de pasos para las instrucciones.
      while(1)
      {
        fscanf(archivo, "%255[^\n]\n", linea); // Lee una instrucción.
        if(strcmp(linea, "# -------------- FIN -------------- #") == 0) break; // Si se alcanza el final del archivo de recetas, detiene la lectura.
        tipoInstruccion *instruccion = (tipoInstruccion *) malloc(sizeof(tipoInstruccion)); // Crea una nueva instrucción.
        instruccion->paso = paso; // Asigna el número de paso a la instrucción.
        strcpy(linea, linea + 4); 
        instruccion->instruccion = strdup(linea); // Asigna el texto de la instrucción, omitiendo el número de paso al principio.
        list_pushBack(receta->instrucciones, instruccion);  // Añade la instrucción a la lista de instrucciones.
        paso++; // Incrementa el número de paso para la próxima instrucción.
      }
    }

    insertMap(mapaRecetas, receta->nombre, receta); // Inserta la receta en el mapa de recetas.
    insertarEnMapaCategorias(mapaCategorias, receta); // Inserta la receta en el mapa de categorías.
  }
  free(linea); // Libera la memoria asignada para la línea de lectura.
  fclose(archivo); // Cierra el archivo una vez completada la carga de recetas.
}