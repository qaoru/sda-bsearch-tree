#include "orderedSet.h"

typedef struct s_bTree{
    Couple c;
    struct s_bTree* droite;
    struct s_bTree* gauche;
} bTree;

typedef struct {
    char* mot;
    struct str_set* positions;
} Couple;

bTree* initBinarySearchTree();
void freeBinarySearchTree(bTree* b);
int getNumberString(bTree *b);
int getTotalNumberString(bTree *b);
bTree* insert(Couple d, bTree *b);
// Ajouter cooccurences ici
ordSet* find(char* mot, bTree *b);
void printBinarySearchTree(bTree *b);
