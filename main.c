/*
 * Projet SDA2 2018
 * LAJARGE Cyril & HENG Paul
 * L2 CMI IIRVIJ
 */

#include <string.h>
#include "orderedSet.h"
#include "binary_tree.h"

int main() {
    /* Tests orderedSet */
    ordSet *s1 = initOrderedSet();
    s1 = insertValue(s1, 2);
    s1 = insertValue(s1, 1);
    s1 = insertValue(s1, 5);
    s1 = insertValue(s1, 4);
    printOrderedSet(s1);
    printf("\n");
    printf("Nb d'elt : %d\n", getNumberElt(s1));
    printf("s1 contient 2 : %d\n", contains(s1, 2));
    printf("s1 contient 3 : %d\n", contains(s1, 3));

    ordSet *s2 = initOrderedSet();
    printOrderedSet(s2);
    /******************************/
    /* Tests binary_tree */
    bTree* t1 = initBinarySearchTree();
    strcpy(t1->c.mot,"lili");
    t1->c.positions=s1;
    addNodeLeft(t1,"lala",s1);
    addNodeRight(t1,"lolo",s1),
    //printf("%d\n",getNumberString(t1));
    printBinarySearchTree(t1,1);
    freeBinarySearchTree(t1);
    /******************************/
    freeOrderedSet(s1);
    return 0;
}
