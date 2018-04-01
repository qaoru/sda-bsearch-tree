#include "orderedSet.h"

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
    if(s != NULL) {
        // Cas : x égal au premier ou dernier élément
        if(s->pos == x || (c.last)->pos == x) {
            return 1;
        }
        // Cas : x hors des bornes de l'ensemble
        if(s->pos > x || (c.last)->pos < x) {
            return 0;
        }
        s = s->next;    //premier élément déjà testé
        while(s != NULL) {
            if(s->pos == x) {
                return 1;
            }
            if(s->pos > x) {
                return 0;
            }
            s = s->next;
        }
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

ordSetElt *getInsertPosition(ordSetElt *s, int x) {
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
        error(1, "oh snap ! cannot malloc ...");
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

// Complexité max : O(n+m)
ordSet intersect(ordSet c1, ordSet c2) {
    ordSet res = initOrderedSet();

    // Cas : les 2 ensembles sont vides
    if(c1.start == NULL || c2.start == NULL) {
        return res;
    }

    // Cas : l'un des ensemble est strictement plus grand que l'autre
    if(c1.last->pos < c2.start->pos || c1.start->pos > c2.last->pos) {
        return res;
    }

    ordSetElt *e1 = c1.start;
    ordSetElt *e2 = c2.start;
    while(e1->next != NULL && e2->next != NULL && e1->pos <= (c1.last)->pos && e2->pos <= (c2.last)->pos) {
        if(e1->pos == e2->pos) {
            insertValue(&res, e1->pos);
            e1 = e1->next;
            e2 = e2->next;
        } else if(e1->pos < e2->pos) {
            e1 = e1->next;
        } else {
            e2 = e2->next;
        }
    }
    return res;    
}
