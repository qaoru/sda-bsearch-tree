#include "binary_tree.h"

/*
 * Fonction qui créé un nouvel arbre binaire
 */
bTree* initBinarySearchTree(){
    if((bTree* newt = malloc(sizeof(struct s_bTree)))==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newt->droite = NULL;
    newt->gauche = NULL;
    Couple newc;
    if(news.mot = malloc(MAX_WORD_SIZE))==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    news.positions = initOrderedSet();
    new->c = newc;
    return newt;
}

/*
 * Focntion qui libère la mémoire allouée à un arbre binaire
 */
void freeBinarySearchTree(bTree* b){
    if(b==NULL){
        exit(EXIT_SUCCESS);
    }
    freeBinarySearchTree(b->droite);
    freeBinarySearchTree(b->gauche);
    free(b->c.mot);
    free(b);
}

/*
 * Fonction qui renvoie le nombre de mots différents dans un arbre
 */
int getNumberString(bTree *b){
    //à implémenter
}

int getTotalNumberString(bTree *b){
    //à implémenter
}

bTree* insert(Couple d, bTree *b){
    //à implémenter
}

/*
 *Ajouter cooccurences ici
 */

ordSet* find(char* mot, bTree *b){
    // à implémenter
}

void printBinarySearchTree(bTree *b){
    //à implémenter
}
