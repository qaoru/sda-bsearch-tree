#include "utils.h"

void error(int syserr, char *msg) {
    fprintf(stderr, "%s\n", msg);
    if(syserr) {
        perror("");
    }
    exit(EXIT_FAILURE);
}