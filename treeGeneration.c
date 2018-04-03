#include "treeGeneration.h"

void readTree(const char * path, char **str) {
    int fd, n, offset = 0;
    if((fd = open(path, O_RDONLY)) == -1) {
        error(1, "open");
    }

    while((n = read(fd, (*str)+offset, BUFFSIZE)) > 0) {
        if(n == BUFFSIZE) {
            offset += BUFFSIZE - 1;
            if((*str = realloc(*str, BUFFSIZE + offset + 1)) == NULL) {
                error(1, "realloc");
            }
        }
    }
    if(n == -1) {
        error(1, "read");
    }
}

void generateTree(const char *path) {
    char *spec;
    if((spec = malloc(BUFFSIZE)) == NULL) {
        error(1, "malloc");
    }
    readTree(path, &spec);
    printf("%s", spec);
    free(spec);

}