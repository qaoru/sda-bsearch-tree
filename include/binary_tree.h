#ifndef BINTREE_H
#define BINTREE_H
#include "orderedSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_SIZE 256
#define TAB_SIZE 50

typedef struct {
    char* mot;
    struct str_ordSet positions;
} Couple;

typedef struct s_bTree{
    Couple c;
    struct s_bTree* droite;
    struct s_bTree* gauche;
} bTree;

bTree* initBinarySearchTree();
void freeBinarySearchTree(bTree* b);
void getNumberStringAux(bTree *b, char** words, int* count);
int getNumberString(bTree *b);
void getTotalNumberStringAux(bTree *b, int* count);
int getTotalNumberString(bTree *b);
void exist(char* mot, bTree *b, int* ex);
void insert(char* mot, int position, bTree **b);
void findCooccurencesAux(bTree* b, char** mots,int nb_mots, ordSet* indices);
ordSet findCooccurences(bTree* b, char** mots, int nb_mots);
void findAux(char* mot, bTree *b, ordSet* allindices);
ordSet find(char *mot, bTree *b);
void printBinarySearchTree(bTree *b, int prof);
#endif
