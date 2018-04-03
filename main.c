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
    insert("qux",6,&t1);
    insert("corge",3,&t1);
    printBinarySearchTree(t1,1);
    printf("\nTest find:\n");
    printOrderedSet(find("lili",t1));
    printf("\n");
    printf("TotalNumberString: %d\n",getTotalNumberString(t1));
    freeBinarySearchTree(t1);


    freeOrderedSet(&s1);
    freeOrderedSet(&s2);
    freeOrderedSet(&s3);
    (void)generateTree(argv[1]);
    return 0;
}
