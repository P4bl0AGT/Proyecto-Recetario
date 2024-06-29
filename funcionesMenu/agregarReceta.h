#ifndef AGREEGARRECETA_H
#define AGREEGARRECETA_H
#include "tdas/list.h"
#include "tdas/hashmap.h"
#include "tdas/extra.h"

void poblarIngredientes(List *ingredientes);

void poblarInstrucciones(List *instrucciones);

void insertarEnMapaCategorias(HashMap *mapaCategorias, tipoReceta *receta);

void agregarRecetas(HashMap *mapaRecetas, HashMap *mapaCategorias);


#endif