#include "binary_tree.h"

/*
 * Fonction qui créé un nouvel arbre binaire
 */
bTree* initBinarySearchTree(){
    bTree* newt=malloc(sizeof(struct s_bTree));
    if(newt==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newt->droite = NULL;
    newt->gauche = NULL;
    Couple newc;
    newc.mot = malloc(MAX_WORD_SIZE);
    if(newc.mot==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newc.positions = initOrderedSet();
    newt->c = newc;
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
    static int size_tab=TAB_SIZE;
    static char* mots_arbre[TAB_SIZE];
    if(i==(size_tab-1)){
        *mots_arbre = realloc(*mots_arbre,(size_tab+TAB_SIZE)*sizeof(char*));
        if(*mots_arbre==NULL){
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        size_tab+=TAB_SIZE;
    }
    int cpt;
    int counted=0;
    for(cpt=0;cpt<i;cpt++){
        if(strcmp(mots_arbre[cpt],b->c.mot)!=0){
            counted=1;
        }
    }
    if(counted==1){
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
    (void)b;
    return 0;
    //à implémenter
}

bTree* insert(Couple d, bTree *b){
    (void)d;
    (void)b;
    return NULL;
    //à implémenter
}

/*
 *Ajouter cooccurences ici
 */

ordSet* find(char* mot, bTree *b){
    (void)mot;
    (void)b;
    return NULL;
    // à implémenter
}

void printBinarySearchTree(bTree *b){
    (void)b;
    //à implémenter
}
