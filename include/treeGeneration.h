#ifndef TREEGEN_H
#define TREEGEN_H
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <ctype.h>
#include "binary_tree.h"

#define BUFFSIZE 4096
/**
 * \fn int readTree(const char * path, char **str)
 * \brief ouvre un fichier, place son contenu dans
 * une chaîne de caractères puis le ferme
 * \param path le chemin du fichier (char *)
 * \param str l'adresse la chaîne destination
 * \return la taille de la chaine destination
 * caractère de fin de chaîne inclus
 */
int readTree(const char * path, char **str);

/**
 * \fn bTree* generateTree(const char *path)
 * \brief génère un arbre binaire à partir
 * d'une spécification
 * \param path le chemin du fichier de spécification (char *)
 * \return un pointeur vers la racine de l'arbre binaire
 */
bTree* generateTree(const char *path);

#endif