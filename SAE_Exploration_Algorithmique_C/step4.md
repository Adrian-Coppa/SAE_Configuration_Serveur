# Étape 4 — Rechercher et filtrer

## Rechercher un client (option 5)

La recherche accepte un **nom, prénom, téléphone ou email** et est insensible à la casse.

Recherchez le client nommé "Gomez" :

```
cd /root/annuaire
printf "17/05/2026\n5\nGomez\n0\n" | ./annuaire
```{{exec}}

Recherchez par numéro de téléphone :

```
printf "17/05/2026\n5\n01.32.55.94.04\n0\n" | ./annuaire
```{{exec}}

> La clé primaire du programme est le **numéro de téléphone** : c'est lui qui identifie chaque client de façon unique dans les opérations de modification et suppression.

## Filtrer les clients (option 6)

Le filtre cherche une **sous-chaîne** dans le nom, prénom, profession ou ville/code postal. Il peut être combiné avec un filtre par âge.

Filtrer tous les clients habitant à Paris :

```
printf "17/05/2026\n6\nPARIS\nN\n0\n" | ./annuaire
```{{exec}}

Filtrer les médecins :

```
printf "17/05/2026\n6\nmedecin\nN\n0\n" | ./annuaire
```{{exec}}

Filtrer les médecins âgés de 34 ans :

```
printf "17/05/2026\n6\nmedecin\nO\n34\n0\n" | ./annuaire
```{{exec}}

## Afficher les clients avec informations manquantes (option 7)

Certains contacts du CSV ont des champs vides. Cette option les liste :

```
printf "17/05/2026\n7\n0\n" | ./annuaire
```{{exec}}

Observez dans `fonctions.c` comment la détection des champs vides est réalisée :

```
grep -A 10 "afficher_clients_manquants" fonctions.c | head -12
```{{exec}}

## Vérification

Vérifiez que la recherche de "Gomez" retourne bien un résultat :

```
RESULT=$(printf "17/05/2026\n5\nGomez\n0\n" | ./annuaire | grep -i "gomez")
echo "$RESULT"
echo "$RESULT" > /tmp/step4_result.txt
```{{exec}}

> ✅ Si "Gomez" apparaît dans la sortie, cliquez sur **Check**.
