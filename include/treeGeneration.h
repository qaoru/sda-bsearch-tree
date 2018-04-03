#ifndef TREEGEN_H
#define TREEGEN_H
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "binary_tree.h"

#define BUFFSIZE 4096

void readTree(const char * path, char **str);
bTree* generateTree(const char *path);

#endif