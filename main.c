/*
 * Projet SDA2 2018
 * LAJARGE Cyril & HENG Paul
 * L2 CMI IIRVIJ
 */

#include <string.h>
#include "orderedSet.h"
#include "binary_tree.h"

int main() {
    ordSet *s1 = initOrderedSet();
    s1 = insertValue(s1, 2);
    s1 = insertValue(s1, 1);
    s1 = insertValue(s1, 5);
    s1 = insertValue(s1, 4);
    printOrderedSet(s1);
    printf("Nb d'elt : %d\n", getNumberElt(s1));
    printf("s1 contient 2 : %d\n", contains(s1, 2));
    printf("s1 contient 3 : %d\n", contains(s1, 3));
    freeOrderedSet(s1);

    ordSet *s2 = initOrderedSet();
    printOrderedSet(s2);
    return 0;
}
