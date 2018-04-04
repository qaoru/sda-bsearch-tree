#include "binary_tree.h"

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

void freeBinarySearchTree(bTree* b){
    if(b==NULL){
        return;
    }
    freeBinarySearchTree(b->droite);
    freeBinarySearchTree(b->gauche);
    free(b->c.mot);
    freeOrderedSet(&(b->c.positions));
    free(b);
}

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

void getTotalNumberStringAux(bTree *b, int* count){
    if(b==NULL){
        (*count)+=0;
    }
    else{
        (*count)+=getNumberElt(b->c.positions);
        getTotalNumberStringAux(b->droite,count);
        getTotalNumberStringAux(b->gauche,count);
    }
}

int getTotalNumberString(bTree *b){
    int count=0;
    getTotalNumberStringAux(b,&count);
    return count;
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

void findCooccurencesAux(bTree* b, char** mots, int nb_mots, ordSet* indices){
    int i;
    if(b!=NULL){
        for(i=0;i<nb_mots;i++){
            if(strcmp(b->c.mot,mots[i])==0){
                if(indices->start==NULL&&indices->last==NULL){
                    (*indices)=b->c.positions;
                }
                else{
                    (*indices)=intersect((*indices),b->c.positions);
                    if(indices->start==NULL&&indices->last==NULL){
                        exit(0);
                    }
                }
            }
        }
        findCooccurencesAux(b->droite,mots,nb_mots,indices);
        findCooccurencesAux(b->gauche,mots,nb_mots,indices);
    }
}

ordSet findCooccurences(bTree *b, char** mots, int nb_mots){
    int i;
    int ex=0;
    ordSet indices=initOrderedSet();
    for(i=0;i<nb_mots;i++){
        exist(mots[i],b,&ex);
        if(ex!=0){
            return indices;
        }
    }
    findCooccurencesAux(b,mots,nb_mots,&indices);
    return indices;
}

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
            printf(".");
        }
        printf("|->%s ",b->c.mot);
        printf("(");
        printOrderedSet(b->c.positions);
        printf(" )\n");
        printBinarySearchTree(b->gauche,prof+1);
        printBinarySearchTree(b->droite,prof+1);
    }
}

int isBalanced(bTree* b){
    (void)b;
    return 0;
}

int getHeight(bTree* b){
    if(b==NULL){
        return 0;
    }
    int hg=getHeight(b->gauche);
    int hd=getHeight(b->droite);
    return 1+(hg>hd?hg:hd);
}

int getAverageDepth(bTree* b){
    (void)b;
    return 0;
}

void rotateLeft(bTree* b){
    (void)b;
}

void rotateRight(bTree* b){
    (void)b;
}

void rotateRightLeft(bTree* b){
    (void)b;
}

void rotateLeftRight(bTree *b){
    (void)b;
}
