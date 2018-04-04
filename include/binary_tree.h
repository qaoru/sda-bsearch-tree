#ifndef BINTREE_H
#define BINTREE_H
#include "orderedSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WORD_SIZE 256
#define TAB_SIZE 50

/**
 * \struct Couple
 * \brief Un couple composé d'un string et d'un str_ordSet.
 */
typedef struct {
    char* mot;
    struct str_ordSet positions;
} Couple;

/**
 * \struct s_bTree
 * \brief Noeud d'un arbre
 * Contient un couple et deux pointeurs sur des s_bTree.
 */
typedef struct s_bTree{
    Couple c;
    struct s_bTree* droite;
    struct s_bTree* gauche;
} bTree;

/**
 * \fn initBinarySearchTree()
 * \brief Créé un arbre.
 * \return un pointeur sur un bTree
 */
bTree* initBinarySearchTree();

/**
 * \fn freeBinarySearchTree(bTree *b)
 * \brief Libère la mémoire allouée à un ensemble donné.
 * \param b un pointeur sur un bTree
 */
void freeBinarySearchTree(bTree* b);

/**
 * \fn getNumberStringAux(bTree *b, char** words, int* count)
 * \brief Calcul le nombre de mots différents d'un arbre donné en utilisant
 * un tableau de string pour stocker les mots par passage par adresse et un
 * pointeur sur un entier pour stocker le nombre de mots différents par
 * passage par adresse également.
 * \param b un pointeur sur un arbre
 * \param words un tableau de string
 * \param count un pointeur sur un entier
 */
void getNumberStringAux(bTree *b, char** words, int* count);

/**
 * \fn getNumberString(bTree *b)
 * \brief Calcul le nombre de mot différents contenu dans un arbre donné.
 * \param b un pointeur sur un bTree
 * \return un entier
 */
int getNumberString(bTree *b);


/**
 * \fn getTotalNumberStringAux(bTree *b, int* count)
 * \brief Calcul le nombre de paires mot/phrase différents contenu dans un arbre
 * donné en utilisant un pointeur sur un entier pour stocker le nombre par
 * passage par adresse.
 * \param b un pointeur sur un bTree
 * \param count un pointeur sur un entier
 */
void getTotalNumberStringAux(bTree *b, int* count);

/**
 * \fn getTotalNumberString(bTree *b)
 * \brief Calcul le nombre de mot différents contenu dans un arbre donné
 * \param b un pointeur sur un bTree
 * \return un entier
 */
int getTotalNumberString(bTree *b);

/**
 * \fn exist(char* mot, bTree *b, int* ex)
 * \brief Teste si un mot donné est dans un arbre donné en stockant le résultat
 * dans un entier par passage par adresse.
 * \param mot un string
 * \param b un pointeur sur un bTree
 * \param ex un pointeur sur un entier
 */
void exist(char* mot, bTree *b, int* ex);

/**
 * \fn insert(char* mot, int position, bTree *b)
 * \brief Insère un mot donné et une position donnée dans un arbre donné par
 * passage par adresse.
 * \param mot un string
 * \param position un entier
 * \param b un pointeur sur un bTree*
 */
void insert(char* mot, int position, bTree **b);

/**
 * \fn findCooccurencesAux(bTree *b, char** mots, int nb_mots, ordSet* indices)
 * \brief Met dans indices grâce au passage par adresse les indices de
 * cooccurences de mots donnés un arbre donné.
 * \param b un pointeur sur un bTree
 * \param mot un tableau de String
 * \param nb_mots un entier, la taille de mots
 * \param indices un pointeur sur un ordSet
 */
void findCooccurencesAux(bTree* b, char** mots, int nb_mots, ordSet* indices);

/**
 * \fn findCooccurences(bTree *b, char** mots, int nb_mots)
 * \brief Trouve les indices de coocurrences de mots donnés dans un arbre donné.
 * \param b un pointeur sur un bTree
 * \param mot un tableau de String
 * \param nb_mots un entier, la taille de mots
 * \return un ordSet
 */
ordSet findCooccurences(bTree* b, char** mots, int nb_mots);

/**
 * \fn findAux(char *mot, bTree *b, ordSet* allindices)
 * \brief Met dans allindices grâce au passage par adresse les indices d'un mot
 * donné dans un arbre donné.
 * \param mot un string
 * \param b un pointeur sur un bTree
 * \param allindices un pointeur sur un ordSet
 * \return un entier
 */
void findAux(char* mot, bTree *b, ordSet* allindices);

/**
 * \fn find(char *mot, bTree *b)
 * \brief Trouve les indices d'un mot donné dans un arbre donné.
 * \param mot un string
 * \param b un pointeur sur un bTree
 * \return un entier
 */
ordSet find(char *mot, bTree *b);

/**
 * \fn printBinarySearchTree(bTree *b, int prof)
 * \brief Affiche un arbre donné
 * \param b un pointeur sur un bTree
 * \param prof la profondeur de départ
 */
void printBinarySearchTree(bTree *b, int prof);

int isBalanced(bTree* b);
int getHeight(bTree* b);
int getTotalDepth(bTree* b);
double getAverageDepth(bTree* b);
void rotateLeft(bTree* b);
void rotateRight(bTree* b);
void rotateRightLeft(bTree* b);
void rotateLeftRight(bTree *b);
#endif
