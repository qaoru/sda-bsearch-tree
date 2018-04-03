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

bTree* generateTree(const char *path) {
    char *spec;
    bTree *res = NULL;
    int size;
    //int offset_old = 0;
    int phrase = 1;
    int i;
    int cpt = 0;
    char tmp[PATH_MAX];
    if((spec = malloc(BUFFSIZE)) == NULL) {
        error(1, "malloc");
    }
    readTree(path, &spec);
    size = strlen(spec);
    for(i = 0; i < size; i++) {
        if(spec[i] != ' ' && spec[i] != '\0' && spec[i] != '\n')
		{
			tmp[cpt++] = spec[i];
		} else {
            tmp[cpt] = '\0';
            insert(tmp, phrase, &res);
            cpt = 0;
            tmp[0] = '\0';
            if(spec[i] == '\n') {
                phrase++;
            }
        }
    }
    
    free(spec);
    return res;

}