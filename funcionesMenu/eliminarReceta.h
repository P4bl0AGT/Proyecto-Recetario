#ifndef ELIMINARRECETA_H
#define ELIMINARRECETA_H

#include "tdas/hashmap.h"

void eliminarMapaCategorias(HashMap *mapaCategorias, char* nombre, char* categoria);

void eliminarReceta(HashMap *mapaRecetas, HashMap *mapaCategorias, char *centinela);

#endif