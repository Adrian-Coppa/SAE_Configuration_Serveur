# Étape 1 — Découverte des fichiers sources

Les fichiers sources ont été automatiquement copiés dans `/root/annuaire/`. Commençons par les explorer.

## Accéder au répertoire de travail

```
cd /root/annuaire
ls -l
```{{exec}}

Vous devriez voir quatre fichiers :
- `fonctions.h` — les déclarations
- `fonctions.c` — les implémentations
- `main.c` — le programme principal
- `annuaire_100_entrees.csv` — les données

## Explorer le fichier CSV

Affichez les 5 premières lignes de l'annuaire :

```
head -5 annuaire_100_entrees.csv
```{{exec}}

Chaque ligne contient 7 champs séparés par des virgules :
`prenom,nom,ville_cp,telephone,email,profession,date_naissance`

Comptez le nombre de contacts dans l'annuaire :

```
wc -l annuaire_100_entrees.csv
```{{exec}}

## Lire le fichier d'en-tête

```
cat fonctions.h
```{{exec}}

Repérez la structure `CLIENT` qui modélise chaque contact, et les prototypes des fonctions disponibles.

## Lire le menu principal

```
cat main.c
```{{exec}}

Le programme propose 8 fonctionnalités accessibles via un menu numéroté.

> **Passez à l'étape suivante** pour compiler le programme.
