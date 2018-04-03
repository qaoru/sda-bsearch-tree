#ifndef TREEGEN_H
#define TREEGEN_H
#include <fcntl.h>
#include "binary_tree.h"

#define BUFFSIZE 4096

void readTree(const char * path, char *buffer);
bTree *generateTree(const char *path);

#endif