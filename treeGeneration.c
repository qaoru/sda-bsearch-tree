#include "treeGeneration.h"

void readTree(const char * path, char * buffer) {
    int fd, n;
    char *spec;
    if((spec = malloc(BUFFSIZE) == NULL) {
        error("malloc");
    }
    if((fd = open(path, O_RDONLY)) == -1) {
        error(1, "open");
    }

    while((n = read(fd, buffer, BUFFSIZE)) > 0) {

    }
    if(n == -1) {
        error("read");
    }
}

bTree *generateTree(const char *path) {
    char buf[BUFFSIZE];
    readTree(path, buf);
}