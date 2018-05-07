/*
 * Projet SDA2 2018
 * LAJARGE Cyril & HENG Paul
 * L2 CMI IIRVIJ
 */

#include <string.h>
#include "orderedSet.h"
#include "binary_tree.h"
#include "treeGeneration.h"

#define N 50

int main(const int argc, const char* argv[]) {
    if(argc != 2) {
        error(0, "usage : ./main <fichier>");
    }

    printf("\n\n===================$$$$$$===================\n");
    printf("             Tests orderedSet               \n");
    printf("===================$$$$$$===================\n\n");

    printf("\n\n===================$$$$$$===================\n");
    printf("        Test insertValue & printOrderedSet         \n\n");

    ordSet s1 = initOrderedSet();
    insertValue(&s1, 2);
    insertValue(&s1, 2);
    insertValue(&s1, 7);
    insertValue(&s1, 5);
    printf("\ns1 : \n");
    printOrderedSet(s1);
    printf("\n");

    ordSet s2 = initOrderedSet();
    insertValue(&s2, 1);
    insertValue(&s2, 2);
    insertValue(&s2, 5);
    insertValue(&s2, 7);
    printf("\ns2 : \n");
    printOrderedSet(s2);
    printf("\n");

    printf("\n\n===================$$$$$$===================\n");
    printf("             Test intersect               \n\n");

    ordSet s3 = intersect(s1, s2);
    printf("\ns3 (intersection s1 et s2) : \n");
    printOrderedSet(s3);
    printf("\n");

    printf("\n\n===================$$$$$$===================\n");
    printf("             Test getNumberElt               \n\n");

    printf("Taille s1 = %d\n", getNumberElt(s1));
    printf("Taille s2 = %d\n", getNumberElt(s2));
    printf("Taille s3 = %d\n", getNumberElt(s3));

    /******************************/
    printf("\n\n ===================$$$$$$===================\n");
    printf("             Tests binary_tree               \n");
    printf("===================$$$$$$===================\n\n");

    printf("\n\n===================$$$$$$===================\n");
    printf("       Test insert & printBinarySearchTree       \n\n");

    bTree* t1=NULL;
    insert("foo",1,&t1);
    insert("bar",1,&t1);
    insert("baz",1,&t1);
    insert("grault",1,&t1);
    insert("qux",2,&t1);
    insert("foo",2,&t1);
    insert("bar",2,&t1);
    insert("corge",2,&t1);
    insert("waldo",3,&t1);
    insert("grault",3,&t1);
    insert("foo",3,&t1);
    insert("foo",4,&t1);
    printf("T1:\n");
    printBinarySearchTree(t1,1);

    printf("\n\n===================$$$$$$===================\n");
    printf("                  Test find                  \n\n");

    printf("\nFind lili in T1:\n");
    printOrderedSet(find("lili",t1));
    printf("\n");
    printf("\nFind foo in T1:\n");
    printOrderedSet(find("foo",t1));
    printf("\n");

    printf("\n\n===================$$$$$$===================\n");
    printf("         Test getTotalNumberString             \n\n");

    printf("TotalNumberString T1: %d\n",getTotalNumberString(t1));

    printf("\n\n===================$$$$$$===================\n");
    printf("             Test getNumberString               \n\n");

    printf("NumberString T1: %d\n",getNumberString(t1));

    printf("\n\n===================$$$$$$===================\n");
    printf("              Test Coocurrences               \n\n");

    char* mots[2];
    int i;
    for(i=0;i<2;i++){
        mots[i]=malloc(N);
        if(mots[i]==NULL){
            error(1,"malloc");
        }
    }
    strcpy(mots[0],"foo");
    strcpy(mots[1],"bar");
    printf("Coocurrences foo bar T1:\n");
    ordSet cooc = findCooccurences(t1,mots,2);
    printOrderedSet(cooc);
    freeOrderedSet(&cooc);
    printf("\n");
    for(i=0;i<2;i++){
        free(mots[i]);
    }

    printf("\n\n===================$$$$$$===================\n");
    printf("              Test getHeight               \n\n");

    printf("Height T1: %d\n",getHeight(t1));

    printf("\n\n===================$$$$$$===================\n");
    printf("              Test isBalanced               \n\n");

    printf("Equilibré T1: %d\n",isBalanced(t1));

    printf("\n\n===================$$$$$$===================\n");
    printf("              Test getAverageDepth               \n\n");

    printf("Average Depth T1: %f\n",getAverageDepth(t1));
    freeBinarySearchTree(t1);

    printf("\n\n ===================$$$$$$===================\n");
    printf("       Tests Rotations Gauche et Droite        \n\n");

    bTree* r=NULL;
    insert("e",1,&r);
    insert("f",1,&r);
    insert("c",1,&r);
    insert("a",1,&r);
    insert("d",1,&r);
    printBinarySearchTree(r,1);
    r=rotateRight(r);
    printf("\nRotation droite:\n");
    printBinarySearchTree(r,1);
    r=rotateLeft(r);
    printf("\nRotation gauche:\n");
    printBinarySearchTree(r,1);
    freeBinarySearchTree(r);

    printf("\n\n ===================$$$$$$===================\n");
    printf("     Tests Rotation Double DroiteGauche     \n\n");

    bTree* rdg=NULL;
    insert("m",1,&rdg);
    insert("s",1,&rdg);
    insert("a",1,&rdg);
    insert("p",1,&rdg);
    insert("t",1,&rdg);
    insert("o",1,&rdg);
    insert("q",1,&rdg);
    printBinarySearchTree(rdg,1);
    rdg=rotateDoubleRightLeft(rdg);
    printf("\nRotation double DroiteGauche:\n");
    printBinarySearchTree(rdg,1);
    freeBinarySearchTree(rdg);

    printf("\n\n ===================$$$$$$===================\n");
    printf("     Tests Rotation Double GaucheDroite     \n\n");

    bTree* rgd=NULL;
    insert("m",1,&rgd);
    insert("o",1,&rgd);
    insert("d",1,&rgd);
    insert("a",1,&rgd);
    insert("g",1,&rgd);
    insert("f",1,&rgd);
    insert("i",1,&rgd);
    printBinarySearchTree(rgd,1);
    rgd=rotateDoubleLeftRight(rgd);
    printf("\nRotation double GaucheDroite:\n");
    printBinarySearchTree(rgd,1);
    freeBinarySearchTree(rgd);

    printf("\n\n ===================$$$$$$===================\n");
    printf("        Resultat avec argument du programme         \n");
    printf("===================$$$$$$===================\n\n");

    bTree *test = generateTree(argv[1]);
    printf("Arbre généré à partir du fichier %s:\n",argv[1]);
    printBinarySearchTree(test,1);
    printf("\nHauteur %s: %d.\n",argv[1],getHeight(test));
    printf("Equilibre %s: %d.\n",argv[1],isBalanced(test));
    printf("Average Depth %s: %f.\n",argv[1],getAverageDepth(test));
    freeBinarySearchTree(test);


    freeOrderedSet(&s1);
    freeOrderedSet(&s2);
    freeOrderedSet(&s3);

    return 0;
}
