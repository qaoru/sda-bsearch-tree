---
title: Rapport de projet (SDA 2)
author:
    - Paul HENG
    - Cyril LAJARGE
date: Mai 2018
---

# Ensemble ordonné

## Implémentation

Notre ensemble de données est constitué de 2 parties. A la manière d'une liste chaînée, nous utilisons un système de maillons contenant un élément (ici un entier) et un pointeur vers l'élément suivant. Après réflexion, nous avons également choisi d'utiliser un couple de pointeurs : l'un vers le début de l'ensemble, et l'autre vers sa fin. Ce choix a été motivé par la nécessité d'optimiser la complexité de certaines opérations. En effet, avoir un accès direct au dernier élément permet d'éviter de faire un parcours entier de l'ensemble quand on souahite effectuer une insertion à la fin de l'ensemble, et cela permet également de faire des tests préliminaires en cas d'intersection nulle entre 2 ensembles.

## La fonction intersection

L'implémentation de cette fonction commence par des tests préliminaires, retournant immédiatement un ensemble vide si une des conditions suivantes est remplie :

* les 2 ensembles entrés en arguments sont vides
* l'un des deux ensemble est strictement plus grand que l'autre ($\Rightarrow$ le dernier élément d'un ensemble est strictement plus petit que le premier élément de l'autre)

Si aucune des conditions n'est vérifiée, on effectue le parcous simultané des 2 ensembles en commençant au premier élément de chacun. A chaque fois, un test est effectué pour comparer les 2 éléments courants, soient $e_1$ et $e_2$ des éléments respectivement du premier et du second ensemble :

* si $e_1 < e_2$, on passe à l'élément suivant pour le premier ensemble
* si $e_1 > e_2$, on passe à l'élément suivant pour le second ensemble
* si $e_1 = e_2$, on ajoute cet élément à l'ensemble de retour de la fonction, et on passe à l'élément suivant pour les deux ensembles

L'intération s'arrête quand on arrive à la fin d'un des deux ensembles.

## Pire cas et complexité

### Insertion en fonction de $n$

Le pire cas serait l'insertion d'un élément à la l'avant-dernière place, forçant à effectuer un parcours quasi complet de l'ensemble. L'insertion en fin d'ensemble ne pose aucun problème étant donné que l'accès est immédiat grâce au pointeur en fin d'ensemble.

La complexité est en $\theta(n)$

### Appartenance d'un élément en fonction de $n$

Le pire cas possible est que l'élément soit compris entre l'avant dernier élément (inclus) et le dernier élément (exclus) de l'ensemble ordonné, soit pour un ensemble $e_1, e_2, .., e_n$ et un élément $x$

$$ e_{n-1} \leq x < e_n$$

La complexité est en $\theta(n)$

### Intersection de deux ensembles

Le pire cas possible est que les deux ensembles soient de même taille et qu'une des conditions soit remplie :

* leur dernier élément soit identique
* le dernier élément de l'un est le seul strictement supérieur au dernier élément de l'autre


La complexité est en $\theta(m)$
