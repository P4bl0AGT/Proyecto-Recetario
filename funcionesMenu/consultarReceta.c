#include <stdio.h>
#include <stdlib.h>


#include "tdas/hashmap.h"
#include "tdas/extra.h"

// Busca y muestra los detalles de una receta específica ingresada por el usuario.
void consultarRecetas(HashMap *mapaRecetas)
{
  limpiarPantalla(); // Limpia la pantalla para mostrar claramente los detalles de la receta.
  AZUL_OSCURO
  printf("| ---------- Revisar Receta ---------- |\n");
  char *nombre = (char *) malloc(sizeof(char) * 50); // Reserva memoria para el nombre de la receta.
  BLANCO
  printf("Ingrese el nombre de la receta: ");
  fscanf(stdin, "%[^\n]49s", nombre); // Lee el nombre de la receta desde la entrada estándar.
  limpiarBuffer(); // Limpia el buffer de entrada para evitar errores en lecturas 
  capitalizar(nombre); // Capitaliza el nombre ingresado para que coincida con el formato almacenado.

  Pair *pareja = searchMap(mapaRecetas, nombre); // Busca la receta en el mapa utilizando el nombre como clave.
  if(pareja != NULL) // Si la receta existe en el mapa
  {
    mostrarReceta(pareja->value); // Muestra los detalles de la receta encontrada.
    presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
    return;
  }
  ROJO_OSCURO
  printf("NO SE ENCONTRO LA RESETA QUE SE INGRESO\n");
  BLANCO;
  presionaParaContinuar(); // Pausa hasta que el usuario presione una tecla.
  return;
}