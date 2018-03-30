#ifndef BINTREE_H
#define BINTREE_H
#include "orderedSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 256
#define TAB_SIZE 10

typedef struct {
    char* mot;
    struct str_set* positions;
} Couple;

typedef struct s_bTree{
    Couple c;
    struct s_bTree* droite;
    struct s_bTree* gauche;
} bTree;

bTree* initBinarySearchTree();
void freeBinarySearchTree(bTree* b);
int getNumberString(bTree *b);
int getTotalNumberString(bTree *b);
bTree* insert(Couple d, bTree *b);
// Ajouter cooccurences ici
ordSet* find(char* mot, bTree *b);
void printBinarySearchTree(bTree *b);
#endif
