#ifndef EXTRA_H
#define EXTRA_H
#include "list.h"

// Estructura que representa una receta
typedef struct
{
  char *nombre; //Nombre de la receta
  char *categoria; // Categoria de la receta(entrada, almuerzo, cena, pasteleria, etc.)
  List *ingredientes; // Lista de Ingredientes
  List *instrucciones;// Lista de Instrucciones
} tipoReceta;

// Estructura que representa un ingrediente
typedef struct
{
  char *ingrediente; // Nombre del ingrediente
  char *cantidad; // Cantidad del ingrediente
} tipoIngrediente;

// Estructura que representa una instruccion
typedef struct
{
  char *instruccion; // Descripcion de la instruccion
  int paso; // Numero de paso de la instruccion
} tipoInstruccion;

#define BLANCO printf("\x1b[m");
#define NEGRO printf("\x1b[30m");
#define ROJO_OSCURO printf("\x1b[31m");
#define VERDE_OSCURO printf("\x1b[32m");
#define AMARILLO_OSCURO printf("\x1b[33m");
#define AZUL_OSCURO printf("\x1b[34m");
#define MAGENTA_OSCURO printf("\x1b[35m");
#define CYAN_OSCURO printf("\x1b[36m");
#define GRIS_CLARO printf("\x1b[37m");
#define GRIS_OSCURO printf("\x1b[90m");
#define ROJO_CLARO printf("\x1b[91m");
#define VERDE_CLARO printf("\x1b[92m");
#define AMARILLO_CLARO printf("\x1b[93m");
#define AZUL_CLARO printf("\x1b[94m");
#define MAGENTA_CLARO printf("\x1b[95m");
#define CYAN_CLARO printf("\x1b[96m");
#define BLANCO_BRILLANTE printf("\x1b[97m");

void limpiarPantalla();

void limpiarBuffer();

void mostrarMenu();

void presionaParaContinuar();

void capitalizar(char *cadena);

tipoReceta *copiarReceta(tipoReceta *recetaOriginal);

void mostrarReceta(tipoReceta *receta);

#endif