# Gestion d'annuaire en C

Bienvenue dans ce scénario ! Vous allez compiler et utiliser un programme C complet de gestion d'annuaire.

## Objectifs pédagogiques

À la fin de ce scénario, vous saurez :

- Compiler un projet C multi-fichiers avec `gcc`
- Lire et interpréter un fichier CSV en C
- Utiliser un programme interactif en ligne de commande
- Comprendre la structure d'un projet C : fichier d'en-tête `.h`, implémentation `.c`, point d'entrée `main.c`

## Architecture du programme

Le projet est composé de trois fichiers :

| Fichier | Rôle |
|---|---|
| `fonctions.h` | Déclarations des types et fonctions |
| `fonctions.c` | Implémentation des fonctions |
| `main.c` | Point d'entrée, menu interactif |

Les données sont chargées depuis `annuaire_100_entrees.csv`, un fichier de 100 contacts au format :

```
prenom,nom,ville_cp,telephone,email,profession,date_naissance
```

> Le numéro de téléphone est la **clé primaire** : il identifie chaque contact de façon unique.

Cliquez sur **START** pour commencer !
