#ifndef CARGARYGUARDAR_H
#define CARGARYGUARDAR_H

#include "tdas/hashmap.h"

void guardarRecetas(HashMap *mapaRecetas, const char* nombreArchivo);

void separarConLimitadorDe(char *cadena, char **cantidad, char**ingrediente);

void cargarRecetas(HashMap *mapaRecetas, HashMap *mapaCategorias, const char* nombreArchivo);

#endif