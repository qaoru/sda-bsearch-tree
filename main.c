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

    ordSet s1 = initOrderedSet();
    insertValue(&s1, 2);
    insertValue(&s1, 1);
    insertValue(&s1, 7);
    insertValue(&s1, 5);

    ordSet s2 = initOrderedSet();
    insertValue(&s2, 1);
    insertValue(&s2, 2);
    insertValue(&s2, 5);
    insertValue(&s2, 7);

    ordSet s3 = intersect(s1, s2);
    printOrderedSet(s3);
    freeOrderedSet(&s1);
    freeOrderedSet(&s2);
    freeOrderedSet(&s3);
    (void)generateTree(argv[1]);
    return 0;
}
