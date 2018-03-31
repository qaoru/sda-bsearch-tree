#include "orderedSet.h"

void memerr() {
    fprintf(stderr, "oh snap ! cannot malloc ..");
    perror("malloc");
    exit(EXIT_FAILURE);
}

ordSet initOrderedSet() {
    ordSet res;
    res.start = NULL;
    res.last = NULL;
    return res;
}

void freeOrderedSet(ordSet *s) {
     ordSetElt * tmp;
    while(s->start != NULL) {
        tmp = s->start;
        s->start = tmp->next;
        free(tmp);
    }
}

int getNumberElt(ordSet c) {
     ordSetElt *s = c.start;
    int cnt = 0;
    while(s != NULL) {
        cnt++;
        s = s->next;
    }
    return cnt;
}

void printNbElt(ordSet c) {
    printf("L'ensemble contient %d éléments.\n", getNumberElt(c));
    printf("Le premier élément est %d et le dernier est %d.\n", c.start->pos, c.last->pos);
}

int contains(ordSet c, int x) {
     ordSetElt *s = c.start;
    while(s != NULL) {
        if(s->pos == x) {
            return 1;
        }
        s = s->next;
    }
    return 0;
}

void printContains(ordSet c, int x) {
    if(contains(c, x)) {
        printf("L'ensemble contient %d.\n", x);
    } else {
        printf("L'ensemble ne contient pas %d.\n", x);
    }
}

/**
  * fonction getInsertPosition
  * Pré-condition : l'ensemble s n'est pas vide
  * Retourne :
  *     - le maillon après lequel l'élément doit être inséré
  *     - NULL si l'ensemble contient déjà l'élément
  * Attention :
  *     - si le maillon renvoyé correspond au premier, il faut tester
  *       si il faut insérer avant ou après
  */

 ordSetElt *getInsertPosition( ordSetElt *s, int x) {
    printf("insert passage pour x = %d\n", x);
     ordSetElt * old = s;
    while(s != NULL) {
        if(s->pos == x) {
            return NULL;
        }
        if(s->pos < x) {
            old = s;
            s = s->next;
        } else {
            return old;
        }
    }
    return old;
}

void insertValue(ordSet *s, int x) {
     ordSetElt *before;
    if(s->start != NULL && x < s->last->pos) {
        before = getInsertPosition(s->start, x);
        if(before == NULL) {    //s contient déjà x
            return;
        }
    }
     ordSetElt *newElt = NULL;
    if((newElt = malloc(sizeof(struct str_set))) == NULL) {
        memerr();
    }
    newElt->pos = x;

    // Cas : s est vide
    if(s->start == NULL) {
        newElt->next = NULL;
        s->start = newElt;
        s->last = newElt;
        return;
    }

    // Cas : insérer en fin
    if(s->last->pos < x) {
        newElt->next = NULL;
        s->last->next = newElt;
        s->last = newElt;
        return;
    }
    
    // Cas : insérer en tête
    if(before->pos > x) {
        newElt->next = before;
        s->start = newElt;
        return;
    }

    newElt->next = before->next;
    before->next = newElt;
    //return start;
}

void printOrderedSet(ordSet c) {
     ordSetElt *s = c.start;
    if(s == NULL) {
        printf("L'ensemble est vide.\n");
        return;
    }
    while(s->next != NULL) {
        printf(" %d |", s->pos);
        s = s->next;
    }
    printf(" %d", s->pos);
}


ordSet copyOrderedSet(ordSet c) {
    ordSet res = initOrderedSet();
    ordSetElt *s = c.start;
    ordSet * tmp = &res;
    while(s != NULL) {
        insertValue(tmp,s->pos);
        s = s->next;
    }
    return res;
}
/*
ordSetElt *intersect(ordSetElt *s1, ordSetElt *s2) {
    ordSetElt *res = NULL;
    res = copyOrderedSet(s1);
    while(s2 != NULL) {
        res = insertValue(res, s2->pos);
        s2 = s2->next;
    }
    return res;
}*/
