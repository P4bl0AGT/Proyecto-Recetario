#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcionesMenu/tdas/list.h"
#include "funcionesMenu/tdas/extra.h"
#include "funcionesMenu/tdas/hashmap.h"

#include "funcionesMenu/cargaryguardar.h"
#include "funcionesMenu/agregarReceta.h"
#include "funcionesMenu/mostrarReceta.h"
#include "funcionesMenu/eliminarReceta.h"
#include "funcionesMenu/modificarReceta.h"
#include "funcionesMenu/consultarReceta.h"

int main()
{
  HashMap *mapaRecetas = createMap(1); // Crea un mapa para almacenar las recetas.
  HashMap *mapaCategorias = createMap(1); // Crea un mapa para almacenar las recetas
  cargarRecetas(mapaRecetas, mapaCategorias, "recetas.txt"); // Carga las recetas desde un archivo de texto.
  
  while (1)
  {
    limpiarPantalla();
    mostrarMenu();
    char opcion;
    fscanf(stdin, "%c", &opcion);
    limpiarBuffer();
    
    if (opcion == '1')
      agregarRecetas(mapaRecetas, mapaCategorias); // Permite al usuario agregar una nueva receta.
    else if (opcion == '2')
      mostrarRecetasNombre(mapaRecetas); // Muestra las recetas por nombre.
    else if (opcion == '3')
      mostrarRecetasCategoria(mapaCategorias); // Muestra las recetas por categoría.
    else if (opcion == '4')
      consultarRecetas(mapaRecetas); // Permite al usuario consultar los detalles de una receta.
    else if(opcion == '5')
      modificarReceta(mapaRecetas, mapaCategorias); // Permite al usuario modificar una receta existente.
    else if(opcion == '6')
      eliminarReceta(mapaRecetas, mapaCategorias, "nohaynombre"); // Permite al usuario eliminar una receta.
    else if(opcion == '7')
      break;
    else
    {
      ROJO_OSCURO
      printf("OPCION INVALIDA INGRESE UNA OPCION VALIDA\n");
      BLANCO  
      presionaParaContinuar();
    }
  }
  guardarRecetas(mapaRecetas,"recetas.txt"); // Guarda todas las recetas en un archivo de texto al salir de la aplicación.
}