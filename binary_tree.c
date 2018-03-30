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
 // !!!!! Fonction très probablement beugé !!!!
int getNumberString(bTree *b){
    static int i=0;
    static int size_tab = 10;
    if(i==0){
        if((static char** mots_arbre = malloc(size_tab*sizeof(char*)))==NULL){
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
    if(i==(size_tab-1)){
        if((*mots_arbre = realloc(*mots_arbre,(size_tab+10)*sizeof(char*)))==NULL){
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        size_tab+=10;
    }
    int cpt;
    int counted=0;
    for(cpt=0;cpt<i;cpt++){
        if(strcmp(mots_arbre[cpt],b->c.mot)!=0){
            counted=1;
        }
    }
    if(counted==1{
        getNumberString(b->droite);
        getNumberString(b->gauche);
    }
    else{
        strcpy(mots_arbre[i++],b->c.mot);
        getNumberString(b->droite);
        getNumberString(b->gauche);
    }
    return (i-1);
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
