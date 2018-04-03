#ifndef TREEGEN_H
#define TREEGEN_H
#include <fcntl.h>
#include <unistd.h>
#include "binary_tree.h"

#define BUFFSIZE 4096

void readTree(const char * path, char **str);
void generateTree(const char *path);

#endif