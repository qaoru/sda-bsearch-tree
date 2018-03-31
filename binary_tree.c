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
        return;
    }
    freeBinarySearchTree(b->droite);
    freeBinarySearchTree(b->gauche);
    free(b->c.mot);
    free(b);
}

/*
 * Fonction qui ajoute un noued à gauche de l'enfantb
 */
void addNodeLeft(bTree* b, char* word, ordSet* l){
    bTree* node=initBinarySearchTree();
    Couple addc;
    addc.mot=malloc(MAX_WORD_SIZE);
    if(addc.mot==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(addc.mot,word);
    addc.positions=l;
    strcpy(node->c.mot,addc.mot);
    node->c.positions=addc.positions;
    b->gauche=node;
    free(addc.mot);
}

/*
 * Fonction qui ajoute un noeud à droite de l'enfant b
 */
void addNodeRight(bTree* b, char* word, ordSet* l){
    bTree* node=initBinarySearchTree();
    Couple addc;
    addc.mot=malloc(MAX_WORD_SIZE);
    if(addc.mot==NULL){
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    strcpy(addc.mot,word);
    addc.positions=l;
    strcpy(node->c.mot,addc.mot);
    node->c.positions=addc.positions;
    b->droite=node;
    free(addc.mot);
}

/*
 * Fonction qui modifie words et count par effet de bord
 * Met dans word, les mots de l'arbre sans répétition
 * Met dans count le nombre de mot différent dans l'arbre
 */
void getNumberStringAux(bTree *b, char** words, int* count){
    static int i=0;
    int cpt;
    int in=0;
    if(b!=NULL){
        if(i==0){
            strcpy(words[i++],b->c.mot);
            (*count)++;
            getNumberStringAux(b->droite,words,count);
            getNumberStringAux(b->gauche,words,count);
        }
        else{
            for(cpt=0;cpt<i;cpt++){
                if(strcmp(words[cpt],b->c.mot)==0){
                    in=1;
                }
            }
            if(in==1){
                getNumberStringAux(b->droite,words,count);
                getNumberStringAux(b->gauche,words,count);
            }
            else{
                strcpy(words[i++],b->c.mot);
                (*count)++;
                getNumberStringAux(b->droite,words,count);
                getNumberStringAux(b->gauche,words,count);
            }
        }
    }
}

/*
 * Fonction qui renvoie le nombre de mots différents dans un arbre
 * ATTENTION: pas généralisé pour une chaine de caractère de taille aléatoire
 * (ici 50 caractères au max) et pour un nombre de mots aléatoire (ici TAB_SIZE
 * mots).
 */
int getNumberString(bTree *b){
    char* words[TAB_SIZE];
    for(int i=0;i<TAB_SIZE;i++){
        words[i]=malloc(50*sizeof(char));
    }
    int count=0;
    getNumberStringAux(b,words,&count);
    for(int i=0;i<TAB_SIZE;i++){
        free(words[i]);
    }
    return count;
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

void printBinarySearchTree(bTree *b, int prof){
    if(b==NULL){
        return;
    }
    else{
        int i;
        printf("|");
        for(i=0;i<prof-1;i++){
            printf(" ");
        }
        printf("|->%s ",b->c.mot);
        printf("(");
        printOrderedSet(b->c.positions);
        printf(")\n");
        printBinarySearchTree(b->droite,prof+1);
        printBinarySearchTree(b->gauche,prof+1);
    }
}
