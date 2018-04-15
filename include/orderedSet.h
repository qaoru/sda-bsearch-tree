/**
 * \file orderedSet.h
 * \brief Opérations sur les ensembles ordonnées
 */

#ifndef ORDSET_H
#define ORDSET_H
#include "utils.h"

/**
 * \struct str_set
 * \brief Elément d'un ensemble ordonné 'entiers
 *
 * Contient un entier et un pointeur vers l'élément suivant,
 * à la manière d'une liste chainée
 */
typedef struct str_set {
    int pos;
    struct str_set * next;
}  ordSetElt;

/**
 * \struct str_ordSet
 * \brief Ensemble ordonné d'entiers
 *
 * Contient un pointeur vers le premier élément
 * et le dernier
 */
typedef struct str_ordSet {
    ordSetElt * start;
    ordSetElt * last;
    int size;
} ordSet;


/**
 * \fn ordSet initOrderedSet()
 * \brief Initialise un ensemble ordonné
 */
ordSet initOrderedSet();

/**
 * \fn void freeOrderedSet(ordSet *s)
 * \brief Libère un ensemble ordonné
 * \param s l'adresse d'un ensemble ordonné
 */
void freeOrderedSet(ordSet *s);

/**
 * \fn int getNumberElt(ordSet c)
 * \param c un ensemble ordonné
 * \return le nombre d'éléments contenus dans l'ensemble
 */
int getNumberElt(ordSet c);

void printNbElt(ordSet c);

/**
 * \fn contains(ordSet c, int x)
 * \brief Teste si c contient x
 * \param c un ensemble ordonné
 * \param x un entier
 * \return un booléen
 */
int contains(ordSet c, int x);

void printContains(ordSet c, int x);

/**
 * \fn ordSetElt *getInsertPosition(ordSetElt *s, int x)
 * \brief Fonction pour trouver l'emplacement où insérer x
 * On suppose s non vide, la valeur NULL étant renvoyée si x
 * est déjà présent dans s
 * \param s un pointeur vers un élément d'ensemble ordonné
 * \param x un entier
 * \return
 *     - le maillon après lequel l'élément doit être inséré
 *     - NULL si l'ensemble contient déjà l'élément
 */
ordSetElt *getInsertPosition(ordSetElt *s, int x);

/**
 * \fn void insertValue(ordSet *s, int x)
 * \brief Insère x dans s, de manière ordonnée croissante
 * \param s l'adresse d'un ensemble ordonné
 * \param x un entier
 */
void insertValue(ordSet *s, int x);

/**
 * \fn void printOrderedSet(ordSet c)
 * \brief Affiche l'ensemble ordonné s
 * \param c un ensemble ordonné
 */
void printOrderedSet(ordSet c);


/**
 * \fn ordSet copyOrderedSet(ordSet c)
 * \brief Copie s et renvoie un pointeur vers sa copie
 * Ne pas oublier de libérer la mémoire nouvellement allouée !
 * \param c un ensemble ordonné
 * \return un nouvel ensemble
 */
 ordSet copyOrderedSet(ordSet c);

/**
 * \fn ordSet intersect(ordSet c1, ordSet c2)
 * \brief Renvoie un nouvel ensemble étant l'intersection de s1 et s2
 * \param c1 un ensemble ordonné
 * \param c2 un ensemble ordonné
 * \return un nouvel ensemble
 */
ordSet intersect(ordSet c1, ordSet c2);
#endif
