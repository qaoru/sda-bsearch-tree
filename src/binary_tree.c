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

int getNumberString(bTree *b){
    static int count = 0;
    //int cpt;
    //int in=0;
    if(b!=NULL){
        count++;
        getNumberString(b->droite);
        getNumberString(b->gauche);
    }

    return count;
}

/*
 * ATTENTION: pas généralisé pour une chaine de caractère de taille aléatoire
 * (ici 50 caractères au max) et pour un nombre de mots aléatoire (ici TAB_SIZE
 * mots).
 */
/*
int getNumberString(bTree *b){
    //int count=0;
    getNumberStringAux(b);
    return count;
}*/

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
        if(isBalanced(*b)!=0){
            (*b)=equilibrer(*b);
        }
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

bTree* equilibrer(bTree* b){
    if(getHeight(b->gauche)-getHeight(b->droite)==2){
        if(getHeight(b->gauche->gauche)<getHeight(b->gauche->droite)){
            b->gauche=rotateLeft(b->gauche);
        }
        return rotateRight(b);
    } //else version symétrique
    else if(getHeight(b->gauche)-getHeight(b->droite)==-2){
        if(getHeight(b->droite->droite)<getHeight(b->droite->gauche)){
            b->droite=rotateRight(b->droite);
        }
        return rotateLeft(b);

    }
    else{
        return b;
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
                    (*indices)= intersect((*indices),b->c.positions);
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
    if(b!=NULL){
        if(abs(getHeight(b->droite)-getHeight(b->gauche))<=1){
            if((isBalanced(b->droite)==0)&&(isBalanced(b->gauche)==0)){
                return 0;
            }
            else{
                return 1;
            }
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int getHeight(bTree* b){
    if(b==NULL){
        return 0;
    }
    int hg=getHeight(b->gauche);
    int hd=getHeight(b->droite);
    return 1+(hg>hd?hg:hd);
}

int getTotalDepth(bTree* b){
    int som=0;
    if(b==NULL){
        return 0;
    }
    som=som+getHeight(b)+getTotalDepth(b->droite)+getTotalDepth(b->gauche);
    return som;
}

double getAverageDepth(bTree* b){
    return (double)getTotalDepth(b)/(double)getNumberString(b);
}

bTree* rotateLeft(bTree* b){
    if((b!=NULL)&&(b->droite!=NULL)){
        bTree* new_racine=b->droite;
        b->droite=new_racine->gauche;
        new_racine->gauche=b;
        return new_racine;
    }
    else{
        return NULL;
    }
}

bTree* rotateRight(bTree* b){
    if((b!=NULL)&&(b->gauche!=NULL)){
        bTree* new_racine=b->gauche;
        b->gauche=new_racine->droite;
        new_racine->droite=b;
        return new_racine;
    }
    else{
        return NULL;
    }
}

bTree* rotateDoubleRightLeft(bTree* b){
    if(b!=NULL&&b->droite!=NULL&&b->droite->gauche!=NULL){
        bTree* new_racine=b->droite->gauche;
        bTree* beta=b->droite->gauche->gauche;
        bTree* nu=b->droite->gauche->droite;
        new_racine->gauche=b;
        new_racine->droite=b->droite;
        new_racine->gauche->droite=beta;
        new_racine->droite->gauche=nu;
        return new_racine;
    }
    else{
        return NULL;
    }
}

bTree* rotateDoubleLeftRight(bTree *b){
    if(b!=NULL&&b->gauche!=NULL&&b->gauche->droite!=NULL){
        bTree* new_racine=b->gauche->droite;
        bTree* beta=b->gauche->droite->droite;
        bTree* nu=b->gauche->droite->gauche;
        new_racine->droite=b;
        new_racine->gauche=b->gauche;
        new_racine->droite->gauche=beta;
        new_racine->gauche->droite=nu;
        return new_racine;
    }
    else{
        return NULL;
    }
}
