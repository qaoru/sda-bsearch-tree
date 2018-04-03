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
    if(close(fd) == -1) {
        error(1, "close");
    }
}

bTree* generateTree(const char *path) {
    char *spec;
    bTree *res = NULL;
    int size;
    int phrase = 1;
    int i;
    int cpt = 0;
    char tmp[PATH_MAX];
    if((spec = malloc(BUFFSIZE)) == NULL) {
        error(1, "malloc");
    }
    readTree(path, &spec);
    size = strlen(spec);
    for(i = 0; i < (size + 1); i++) {
        if(spec[i] != ' ' && spec[i] != '\0' && spec[i] != '\n')
		{
			tmp[cpt++] = spec[i];
		} else {
            tmp[cpt] = '\0';    // fin de mot
            insert(tmp, phrase, &res);  // insertion du mot
            cpt = 0;    // reset du compteur
            tmp[0] = '\0';  // reset de la chaîne
            if(spec[i] == '\n') {
                phrase++;   // phrase suivante
            }
        }
    }
    free(spec);
    return res;

}