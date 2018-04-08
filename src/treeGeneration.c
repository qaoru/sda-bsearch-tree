#include "treeGeneration.h"

int readTree(const char * path, char **str) {
    int i, fd, n, offset = 0, size = BUFFSIZE;
    char buffer[BUFFSIZE];
    if((fd = open(path, O_RDONLY)) == -1) {
        error(1, "open");
    }

    while((n = read(fd, buffer, BUFFSIZE)) > 0) {
        for(i = 0; i < n; i++) {
            if(!ispunct(buffer[i])) {
                (*str)[offset++] = tolower(buffer[i]);
            } else {
                (*str)[offset++] = ' ';
            }
        }
        if(offset%BUFFSIZE == 0) {
            size += BUFFSIZE;
            if((*str = realloc(*str, size)) == NULL) {
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
    return offset;
}

bTree* generateTree(const char *path) {
    char *spec;
    bTree *res = NULL;
    int size;
    int phrase = 1;
    int i;
    int cpt = 0;
    int rflag = 0; //gestion des multiples sauts de lignes
    char tmp[PATH_MAX];
    if((spec = calloc(BUFFSIZE, 1)) == NULL) {
        error(1, "calloc");
    }
    size = readTree(path, &spec);
    for(i = 0; i < size; i++) {
        if(spec[i] != ' ' && spec[i] != '\0' && spec[i] != '\n')
		{
			tmp[cpt++] = spec[i];
            rflag = 1;
		} else {
            if(rflag) {    
                tmp[cpt] = '\0';    // fin de mot
                if(tmp[0] != '\0')
                    insert(tmp, phrase, &res);  // insertion du mot
                cpt = 0;    // reset du compteur
                tmp[0] = '\0';  // reset de la chaîne
                if(spec[i] == '\n') {
                    phrase++;   // phrase suivante
                    rflag = 0;
                }
            }
        }
    }
    free(spec);
    return res;

}