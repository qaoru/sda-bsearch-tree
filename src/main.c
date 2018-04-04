/*
 * Projet SDA2 2018
 * LAJARGE Cyril & HENG Paul
 * L2 CMI IIRVIJ
 */

#include <string.h>
#include "orderedSet.h"
#include "binary_tree.h"
#include "treeGeneration.h"

int main(const int argc, const char* argv[]) {
    if(argc != 2) {
        error(0, "usage : ./main <fichier>");
    }

    // Tests orderedSet

    ordSet s1 = initOrderedSet();
    insertValue(&s1, 2);
    insertValue(&s1, 2);
    insertValue(&s1, 7);
    insertValue(&s1, 5);

    ordSet s2 = initOrderedSet();
    insertValue(&s2, 1);
    insertValue(&s2, 2);
    insertValue(&s2, 5);
    insertValue(&s2, 7);

    ordSet s3 = intersect(s1, s2);
    printOrderedSet(s3);
    printf("\ns1 : \n");
    printOrderedSet(s1);
    printf("\ns2 : \n");
    printOrderedSet(s2);
    printf("\n");

    /******************************/
    printf("\n\n ===================$$$$$$===================\n\n");

    // Tests binary_tree

    bTree* t1=NULL;
    insert("foo",1,&t1);
    insert("foo",2,&t1);
    insert("foo",3,&t1);
    insert("qux",2,&t1); // <- ici si on intervertit celui et celui d'après on
    insert("qux",3,&t1); // a pas la même chose
    insert("corge",3,&t1);
    insert("foo",4,&t1);

    printBinarySearchTree(t1,1);
    printf("\nTest find:\n");
    printOrderedSet(find("lili",t1));
    printf("\n");
    printf("TotalNumberString: %d\n",getTotalNumberString(t1));

    /*------Test Coocurrences-----*/
    char* mots[2];
    int i;
    for(i=0;i<2;i++){
        mots[i]=malloc(50);//50 à mettre en define
        if(mots[i]==NULL){
            error(1,"malloc");
        }
    }
    strcpy(mots[0],"foo");
    strcpy(mots[1],"qux");
    printf("Coocurrences foo qux:\n");
    printOrderedSet(findCooccurences(t1,mots,2));
    printf("\n");
    for(i=0;i<2;i++){
        free(mots[i]);
    }
    /*--------------------*/
    printf("Height t1: %d\n",getHeight(t1));
    printf("Equilibré t1: %d\n",isBalanced(t1));
    printf("Average Depth t1: %f\n",getAverageDepth(t1));
    freeBinarySearchTree(t1);

    bTree *test = generateTree(argv[1]);
    printBinarySearchTree(test,1);
    printf("\nHauteur test: %d.\n",getHeight(test));
    printf("Equilibré test: %d\n",isBalanced(test));
    printf("Average depth test: %f\n",getAverageDepth(test));
    freeBinarySearchTree(test);


    freeOrderedSet(&s1);
    freeOrderedSet(&s2);
    freeOrderedSet(&s3);
    //(void)generateTree(argv[1]);
    return 0;
}
