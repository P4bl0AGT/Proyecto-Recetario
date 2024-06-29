#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "extra.h"

void limpiarPantalla() { system("clear"); }

void limpiarBuffer() { while ((getchar()) != '\n'); }

void mostrarMenu()
{
  VERDE_OSCURO
  printf("=====================================\n");
  printf("              Recetario\n");
  printf("=====================================\n");
  printf("(1) Ingresar Receta\n");
  printf("(2) Mostrar Recetas Por Nombres\n");
  printf("(3) Mostrar Recetas Por Categorias\n");
  printf("(4) Consultar Receta\n");
  printf("(5) Modificar Receta\n");
  printf("(6) Eliminar Receta\n");
  printf("(7) Salir\n");
  printf("Ingrese una opcion: ");
}

void presionaParaContinuar()
{
  printf("Presiona una tecla para continuar");
  limpiarBuffer();
  printf("\n");
}

// Función que capitaliza la primera letra de cada palabra en una cadena y convierte las demás en minúsculas.
void capitalizar(char *cadena)
{
  int flag = 1; // Bandera para determinar si es el inicio de una palabra.
  while(*cadena) // Itera sobre cada caracter de la cadena.
  {
    if(isspace(*cadena)) // Si el caracter es un espacio, se activa la bandera.
      flag = 1;
    else
    {
      if(flag) // Si el caracter es el inicio de una palabra, lo convierte en mayúscula.
      {
        *cadena = toupper(*cadena);
        flag = 0; // Desactiva la bandera para las siguientes letras de la palabra.
      }
      else // Si no es el inicio de una palabra, lo convierte en minúscula.
        *cadena = tolower(*cadena);
    }
    cadena++; // Avanza al siguiente caracter.
  }
}

// Función que copia una receta, incluyendo sus ingredientes e instrucciones.
tipoReceta *copiarReceta(tipoReceta *recetaOriginal)
{
  // CREAR NUEVA RECETA
  tipoReceta *recetaCopia = (tipoReceta *) malloc(sizeof(tipoReceta)); // Asigna memoria para la nueva receta.

  // COPIAR NOMBRE Y CATEGORIA 
  recetaCopia->nombre = strdup(recetaOriginal->nombre); // Copia el nombre de la receta original.
  recetaCopia->categoria = strdup(recetaOriginal->categoria); // Copia la categoría de la receta original.

  // COPIAR INGREDIENTES
  recetaCopia->ingredientes = list_create(); // Crea una nueva lista para los ingredientes.
  tipoIngrediente *ingAux = list_first(recetaOriginal->ingredientes); // Obtiene el primer ingrediente de la lista original.
  while(ingAux != NULL) // Itera sobre todos los ingredientes.
  {
    tipoIngrediente *nuevoIngrediente = (tipoIngrediente *) malloc(sizeof(tipoIngrediente)); // Asigna memoria para un nuevo ingrediente.
    nuevoIngrediente->ingrediente = strdup(ingAux->ingrediente); // Copia el nombre del ingrediente.
    nuevoIngrediente->cantidad = strdup(ingAux->cantidad); // Copia la cantidad del ingrediente.
    list_pushBack(recetaCopia->ingredientes, nuevoIngrediente); // Añade el nuevo ingrediente al final de la lista.
    ingAux = list_next(recetaOriginal->ingredientes); // Avanza al siguiente ingrediente.
  }

  // COPIAR ESTRUCCIONES
  recetaCopia->instrucciones = list_create(); // Crea una nueva lista para las instrucciones.
  tipoInstruccion *intAux = list_first(recetaOriginal->instrucciones); // Obtiene la primera instrucción de la lista original.
  while(intAux != NULL) // Itera sobre todas las instrucciones.
  {
    tipoInstruccion *nuevaInstruccion = (tipoInstruccion *) malloc(sizeof(tipoInstruccion)); // Asigna memoria para una nueva instrucción.
    nuevaInstruccion->instruccion = strdup(intAux->instruccion); // Copia el texto de la instrucción.
    nuevaInstruccion->paso = intAux->paso; // Copia el número del paso.
    list_pushBack(recetaCopia->instrucciones, nuevaInstruccion); // Añade la nueva instrucción al final de la lista.
    intAux = list_next(recetaOriginal->instrucciones);  // Avanza a la siguiente instrucción.
  }
  return recetaCopia; // Retorna la receta copiada.
}

// Función para mostrar en consola todos los detalles de una receta.
void mostrarReceta(tipoReceta *receta)
{
  //limpiarPantalla();
  AZUL_OSCURO
  printf("| ---------- Datos Receta ---------- |\n");
  BLANCO
  printf("  Nombre de la receta: %s\n", receta->nombre); // Muestra el nombre de la receta.
  printf("  Categoria de la receta: %s\n", receta->categoria);  // Muestra la categoría de la receta.

  AZUL_OSCURO
  printf("| ---------- Ingredientes ---------- |\n");
  BLANCO
  tipoIngrediente *ingAux = list_first(receta->ingredientes); // Obtiene el primer ingrediente.
  while (ingAux != NULL) // Itera sobre todos los ingredientes.
  {
    printf("  %s de %s\n", ingAux->cantidad, ingAux->ingrediente); // Muestra la cantidad y el nombre del ingrediente.
    ingAux = list_next(receta->ingredientes); // Avanza al siguiente ingrediente.
  }

  AZUL_OSCURO
  printf("| ---------- Instrucciones ---------- |\n");
  BLANCO
  tipoInstruccion *intAux = list_first(receta->instrucciones); // Obtiene la primera instrucción.
  while (intAux != NULL) // Itera sobre todas las instrucciones.
  {
    printf("  %i) %s\n", intAux->paso , intAux->instruccion); // Muestra el número del paso y el texto de la instrucción.
      intAux = list_next(receta->instrucciones); // Avanza a la siguiente instrucción.
  }
  printf("\n");


}