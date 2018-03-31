/**
 * \file orderedSet.h
 * \brief Opérations sur les ensembles ordonnées
 */

#ifndef ORDSET_H
#define ORDSET_H
#include <stdio.h>
#include <stdlib.h>

/**
 * \struct str_set
 * \brief Ensemble ordonné d'entiers
 *
 * Contient un entier et un pointeur vers l'élément suivant,
 * à la manière d'une liste chainée
 */
typedef struct str_set {
    int pos;
    struct str_set * next;
} ordSet;

typedef struct str_ordCouple {
    ordSet * start;
    ordSet * last;
} ordCouple;

void memerr();

/**
 * \fn ordSet *initOrderedSet()
 * \brief initialise un ensemble ordonné à NULL
 */
ordCouple initOrderedSet();
/**
 * \fn void freeOrderedSet(ordSet *s)
 * \brief libère un ensemble ordonné (ptr)
 * \param s un ensemble ordonné
 */
void freeOrderedSet(ordCouple *s);

/**
 * \fn int getNumberElt(orsSet *s)
 * \param s un ensemble ordonné
 * \return le nombre d'éléments contenus dans l'ensemble
 */
int getNumberElt(ordCouple c);

void printNbElt(ordCouple c);

/**
 * \fn contains(ordSet *s, int x)
 * \brief Teste si s contient x
 * \param s un ensemble ordonné (ptr)
 * \param x un entier
 * \return un booléen
 */
int contains(ordCouple c, int x);

void printContains(ordCouple c, int x);

/**
 * \fn ordSet *getInsertPosition(ordSet *s, int x)
 * \brief Fonction pour trouver l'emplacement où insérer x
 * On suppose s non vide, la valeur NULL étant renvoyée si x
 * est déjà présent dans s
 * \param s un emsemble ordonné > NON VIDE < (ptr)
 * \param x un entier
 * \return
 *     - le maillon après lequel l'élément doit être inséré
 *     - NULL si l'ensemble contient déjà l'élément
 */
ordSet *getInsertPosition(ordSet *s, int x);

/**
 * \fn ordSet *insertValue(ordSet *s, int x)
 * \brief Insère x dans s, de manière ordonnée croissante
 * \param s un ensemble ordonné (ptr)
 * \param x un entier
 * \return un pointeur vers l'ensemble
 */
void insertValue(ordCouple *s, int x);

/**
 * \fn void printOrderedSet(ordSet *s)
 * \brief Affiche l'ensemble ordonné s
 * \param s un ensemble ordonné (ptr)
 */
void printOrderedSet(ordCouple c);

/**
 * \fn ordSet *insertValueDumb(ordSet *s, int x)
 * \brief Insère la x à la suite du premier maillon de s
 * \param s un ensemble ordonné (ptr)
 * \param x un entier
 * \return un pointeur vers l'ensemble
 */
ordSet *insertValueDumb(ordSet *s, int x);

/**
 * \fn ordSet *copyOrderedSet(ordSet *s)
 * \brief Copie s et renvoie un pointeur vers sa copie
 * Ne pas oublier de libérer la mémoire nouvellement allouée !
 * \param s un ensemble ordonné (ptr)
 * \return un pointeur vers le nouvel ensemble
 */
ordCouple copyOrderedSet(ordCouple c);

/**
 * \fn ordSet *intersect(ordSet *s1, ordSet *s2)
 * \brief Renvoie un nouvel ensemble étant l'intersection de s1 et s2
 * Par soucis d'optimisation, passer l'emsemble le + grand en premier paramètre
 * \param s1 un ensemble ordonné (ptr)
 * \param s2 un ensemble ordonné (ptr)
 * \return un pointeur vers le nouvel ensemble
 */
ordSet *intersect(ordSet *s1, ordSet *s2);
#endif