#include "binary_tree.h"

/*
 * Fonction qui créé un nouvel arbre binaire
 */
bTree* initBinarySearchTree(){
    bTree* newt=malloc(sizeof(struct s_bTree));
    if(newt==NULL){
        error(1, "malloc");
    }
    newt->droite = NULL;
    newt->gauche = NULL;
    newt->c.mot=malloc(MAX_WORD_SIZE);
    if(newt->c.mot==NULL){
        error(1,"malloc");
    }
    newt->c.positions = initOrderedSet();
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
        if((words[i]=malloc(50)) == NULL) {
            error(1, "malloc");
        }
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

void exist(char* mot, bTree *b, int* ex){
    if(b!=NULL){
        if(strcmp(mot,b->c.mot)==0){
            (*ex)=0;
        }
        else{
            exist(mot,b->droite,ex);
            exist(mot,b->gauche,ex);
        }
    }
}

void insert(char* mot, int position, bTree** b){
    if((*b)==NULL){
        (*b)=initBinarySearchTree();
        strcpy((*b)->c.mot,mot);
        insertValue(&((*b)->c.positions),position);
    }
    else{
        if(strcmp(mot,(*b)->c.mot)==0){
            insertValue(&(*b)->c.positions,position);
        }
        else if(strcmp(mot,(*b)->c.mot)>0){
            insert(mot,position,&((*b)->droite));
        }
        else if(strcmp(mot,(*b)->c.mot)<0){
            insert(mot,position,&((*b)->gauche));
        }
    }
}

/*
 *Ajouter cooccurences ici
 */

void findAux(char* mot, bTree *b, ordSet* allindices){
    if(b!=NULL){
        if(strcmp(b->c.mot,mot)==0){
            if(allindices->start==NULL&&allindices->last==NULL){
                (*allindices)=b->c.positions;
            }
            else{
                (*allindices)=intersect(*allindices,b->c.positions);
            }
            findAux(mot,b->droite,allindices);
            findAux(mot,b->gauche,allindices);
        }
        findAux(mot,b->droite,allindices);
        findAux(mot,b->gauche,allindices);
    }
}

ordSet find(char* mot, bTree *b){
    ordSet all=initOrderedSet();
    findAux(mot,b,&all);
    return all;
}

void printBinarySearchTree(bTree *b, int prof){
    if(b!=NULL){
        int i;
        printf("|");
        for(i=0;i<prof-1;i++){
            printf(" ");
        }
        printf("|->%s ",b->c.mot);
        printf("(");
        printOrderedSet(b->c.positions);
        printf(" )\n");
        printBinarySearchTree(b->gauche,prof+1);
        printBinarySearchTree(b->droite,prof+1);
    }
}
