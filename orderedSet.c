#include "orderedSet.h"

void memerr() {
    fprintf(stderr, "oh snap ! cannot malloc ..");
    perror("malloc");
    exit(EXIT_FAILURE);
}

ordSet *initOrderedSet() {
    return NULL;
}

void freeOrderedSet(ordSet *s) {
    ordSet * tmp;
    while(s != NULL) {
        tmp = s;
        s = tmp->next;
        free(tmp);
    }
}

int getNumberElt(ordSet *s) {
    int cnt = 0;
    while(s != NULL) {
        cnt++;
        s = s->next;
    }
    return cnt;
}

int contains(ordSet *s, int x) {
    while(s != NULL) {
        if(s->pos == x) {
            return 1;
        }
        s = s->next;
    }
    return 0;
}

/**
  * fonction getInsertPosition
  * Pré-condition : l'ensemble s n'est pas vide
  * Retourne :
  *     - le maillon après lequel l'élément doit être inséré
  *     - NULL si l'ensemble contient déjà l'élément
  */

ordSet *getInsertPosition(ordSet *s, int x) {
    ordSet * old = s;
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

ordSet *insertValue(ordSet *s, int x) {
    ordSet *before;
    if(s != NULL) {
        before = getInsertPosition(s, x);
        if(before == NULL) {    //s contient déjà x
            return s;
        }
    }
    ordSet *start = s;
    ordSet *newElt = initOrderedSet();
    if((newElt = malloc(sizeof(struct str_set))) == NULL) {
        memerr();
    }
    newElt->pos = x;

    // Cas : s est vide
    if(s == NULL) {
        newElt->next = NULL;
        return newElt;
    }

    // Cas : insérer en tête
    if(before == start) {
        newElt->next = before;
        return newElt;
    }

    newElt->next = before->next;
    before->next = newElt;
    return start;
}

void printOrderedSet(ordSet *s) {
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

ordSet *copyOrderedSet(ordSet *s) {
    ordSet *res = initOrderedSet();
    while(s != NULL) {
        insertValue(res, s->pos);
        s = s->next;
    }
    return res;
}

ordSet *intersect(ordSet *s1, ordSet *s2) {
    ordSet *res = copyOrderedSet(s1);
    while(s2 != NULL) {
        insertValue(res, s2->pos);
        s2 = s2->next;
    }
    return res;
}
