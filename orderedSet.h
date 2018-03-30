#ifndef ORDSET_H
#define ORDSET_H
#include <stdio.h>
#include <stdlib.h>


typedef struct str_set {
    int pos;
    struct str_set * next;
} ordSet;
void memerr();
ordSet *initOrderedSet();
void freeOrderedSet(ordSet *s);
int getNumberElt(ordSet *s);
int contains(ordSet *s, int x);
/**
  * fonction getInsertPosition
  * Pré-condition : l'ensemble s n'est pas vide
  * Retourne :
  *     - le maillon après lequel l'élément doit être inséré
  *     - NULL si l'ensemble contient déjà l'élément
  */
ordSet *getInsertPosition(ordSet *s, int x);
ordSet *insertValue(ordSet *s, int x);
void printOrderedSet(ordSet *s);
ordSet *copyOrderedSet(ordSet *s);
ordSet *intersect(ordSet *s1, ordSet *s2);
#endif