# Étape 5 — Ajouter, modifier, supprimer et sauvegarder

## Ajouter un client (option 2)

Ajoutez un nouveau contact. Le programme demande successivement chaque champ :

```
cd /root/annuaire
printf "17/05/2026\n2\nJean\nDupont\nLYON 69001\n06.12.34.56.78\njean.dupont@email.fr\ningenieur\n15/03/1990\n0\n" | ./annuaire
```{{exec}}

Vérifiez que Jean Dupont a bien été ajouté en le recherchant :

```
printf "17/05/2026\n5\nDupont\n0\n" | ./annuaire
```{{exec}}

## Modifier un client (option 3)

La modification s'effectue en fournissant le **numéro de téléphone** du client à modifier, puis en choisissant le champ à changer.

Codes des champs modifiables :
- `1` Nom · `2` Prénom · `3` Ville et CP · `4` Email · `5` Profession · `6` Date de naissance · `7` Annuler

Modifions la profession de Gabriel Gomez (tél. `01.32.55.94.04`) :

```
printf "17/05/2026\n3\n01.32.55.94.04\n5\nchirurgien\n0\n" | ./annuaire
```{{exec}}

Vérifiez la modification :

```
printf "17/05/2026\n5\nGomez\n0\n" | ./annuaire
```{{exec}}

## Supprimer un client (option 4)

La suppression décale tous les enregistrements suivants d'une position vers la gauche. Supprimons un client de test :

```
printf "17/05/2026\n4\n06.12.34.56.78\n0\n" | ./annuaire
```{{exec}}

## Sauvegarder (option 8)

La sauvegarde **réécrit le fichier CSV** avec l'état actuel du tableau en mémoire :

```
printf "17/05/2026\n8\n0\n" | ./annuaire
```{{exec}}

Vérifiez le contenu du fichier sauvegardé :

```
head -5 annuaire_100_entrees.csv
```{{exec}}

> ⚠️ La sauvegarde écrase le fichier original. Pour préserver les données originales, faites d'abord une copie :
> ```
> cp annuaire_100_entrees.csv annuaire_backup.csv
> ```{{exec}}

## Vérification finale

Exécutez le test complet : ajout → vérification → sauvegarde :

```
printf "17/05/2026\n2\nTest\nKillercoda\nPARIS 75001\n09.99.99.99.99\ntest@kc.fr\netudiant\n01/01/2000\n8\n0\n" | ./annuaire
grep "09.99.99.99.99" annuaire_100_entrees.csv && echo "SAUVEGARDE OK"
```{{exec}}

> ✅ Si vous voyez `SAUVEGARDE OK`, cliquez sur **Check** pour terminer !
