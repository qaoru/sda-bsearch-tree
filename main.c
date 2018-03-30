/*
 * Projet SDA2 2018
 * LAJARGE Cyril & HENG PAUL
 * L2 CMI IIRVIJ
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"

void memerr() {
    fprintf(stderr, "oh snap ! cannot malloc ..");
    perror("malloc");
    exit(EXIT_FAILURE);
}

int main() {
    printf("Coucou\n");
    return 0;
}
