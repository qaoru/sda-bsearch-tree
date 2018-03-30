/*
 * Projet SDA2 2018
 * LAJARGE Cyril & HENG Paul
 * L2 CMI IIRVIJ
 */

#include <string.h>
<<<<<<< HEAD
#include "binary_tree.h"

void memerr() {
    fprintf(stderr, "oh snap ! cannot malloc ..");
    perror("malloc");
    exit(EXIT_FAILURE);
}
=======
#include "orderedSet.h"
>>>>>>> cb2e6c0464555b820411e793d75eceecc84f5c1a

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
