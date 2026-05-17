# Étape 2 — Compilation du programme

## Compiler avec gcc

La commande suivante compile les deux fichiers source et produit un exécutable nommé `annuaire` :

```
cd /root/annuaire && gcc -o annuaire main.c fonctions.c -Wall
```{{exec}}

L'option `-Wall` active tous les avertissements : utile pour repérer des problèmes dès la compilation.

Si la compilation réussit, aucun message d'erreur n'apparaît. Vérifiez que l'exécutable a bien été créé :

```
ls -lh annuaire
```{{exec}}

## Comprendre la structure multi-fichiers

Le projet utilise une organisation classique en C :

```
fonctions.h  ←  inclus par main.c et fonctions.c
    │
    ├── fonctions.c  (implémentation)
    └── main.c       (programme principal)
          │
          └── gcc compile les deux → annuaire (exécutable)
```

`main.c` et `fonctions.c` incluent tous deux `fonctions.h` via `#include "fonctions.h"`. Cela garantit que les deux fichiers utilisent les mêmes déclarations de types et de fonctions.

## Vérification

Exécutez cette commande pour confirmer que l'exécutable existe :

```
test -f /root/annuaire/annuaire && echo "OK : exécutable trouvé !"
```{{exec}}

> ✅ Si vous voyez `OK : exécutable trouvé !`, cliquez sur **Check** pour valider cette étape.
