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

<<<<<<< HEAD
    // Tests orderedSet

=======
>>>>>>> 284cc61ac1739265d8bad163cafa437b90f40d02
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
<<<<<<< HEAD
    printf("\ns1 : \n");
    printOrderedSet(s1);
    printf("\ns2 : \n");
    printOrderedSet(s2);
    printf("\n");

    /******************************/
    printf("\n\n ===================$$$$$$===================\n\n");

    // Tests binary_tree

    bTree* t1 = initBinarySearchTree();
    strcpy(t1->c.mot,"lili");
    t1->c.positions=s1;
    addNodeLeft(t1,"lili",s1);
    addNodeRight(t1,"lolo",s2);
    printf("%d\n",getNumberString(t1));
    printBinarySearchTree(t1,1);
    printOrderedSet(find("lili",t1));
    ordSet test=intersect(s1,s1);
    printf("\n");
    printOrderedSet(test);
    freeBinarySearchTree(t1);


=======
>>>>>>> 284cc61ac1739265d8bad163cafa437b90f40d02
    freeOrderedSet(&s1);
    freeOrderedSet(&s2);
    freeOrderedSet(&s3);
    (void)generateTree(argv[1]);
    return 0;
}
