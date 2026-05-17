# Félicitations ! 🎉

Vous avez terminé le scénario **Gestion d'annuaire en C** avec succès.

## Ce que vous avez accompli

✅ **Exploré** un projet C multi-fichiers (`.h`, `.c`, `main.c`)  
✅ **Compilé** le programme avec `gcc` et les options recommandées  
✅ **Affiché et trié** une liste de 100 clients selon plusieurs critères  
✅ **Recherché et filtré** des contacts par nom, profession, ville ou âge  
✅ **Ajouté, modifié et supprimé** des clients en mémoire  
✅ **Sauvegardé** les modifications dans le fichier CSV  

## Concepts clés revus

| Concept C | Utilisé dans |
|---|---|
| `struct` | Type `CLIENT` dans `fonctions.h` |
| Allocation dynamique (`malloc`) | `main.c` |
| Pointeurs (`*nombre_clients`) | `ajouter_client`, `supprimer_client` |
| Tri à bulles | `trier_clients` dans `fonctions.c` |
| Lecture/écriture fichier (`fopen`, `fgets`, `fprintf`) | `charger_clients`, `sauvegarder_clients` |
| `sscanf` | `calculer_age` |

## Pour aller plus loin

- Remplacez le tri à bulles par un **tri rapide** (`qsort`) pour de meilleures performances sur 5000 entrées
- Ajoutez une **recherche binaire** après tri pour accélérer les lookups
- Séparez la lecture CSV dans une fonction dédiée avec `strtok`
- Testez avec `annuaire_5000_entrees.csv` en modifiant `MAX_CLIENTS` et la macro `annuaire` dans `fonctions.h`

Bonne continuation !
