# Étape 3 — Afficher et trier les clients

Le programme est interactif : il lit vos choix au clavier. Dans KillerCoda, vous allez le piloter en **redirigeant l'entrée standard** depuis un fichier texte (une séquence de choix simulant la saisie utilisateur).

## Afficher tous les clients sans tri

Créez un fichier de commandes simulant : date du jour → option 1 (afficher) → pas de tri (0) → quitter (0) :

```
cd /root/annuaire
printf "17/05/2026\n1\n0\n0\n" | ./annuaire | head -20
```{{exec}}

Le programme affiche les 100 clients chargés depuis le CSV. Chaque ligne contient : `nom, prenom, ville_cp, telephone, email, profession, age`.

## Afficher trié par nom

```
printf "17/05/2026\n1\n1\n0\n" | ./annuaire | grep -A 100 "Liste des clients" | head -15
```{{exec}}

Les critères de tri disponibles sont :
- `1` — Tri par **nom**
- `2` — Tri par **code postal**
- `3` — Tri par **profession**
- `4` — Tri par **date de naissance**
- `0` — Sans tri

## Afficher trié par profession

```
printf "17/05/2026\n1\n3\n0\n" | ./annuaire | grep -A 100 "Liste des clients" | head -15
```{{exec}}

## Comprendre le calcul d'âge

La date que vous saisissez en début de session sert de **date de référence** pour calculer l'âge de chaque client. La fonction `calculer_age()` dans `fonctions.c` effectue ce calcul à partir des champs `JJ/MM/AAAA`.

Regardez comment elle fonctionne :

```
grep -A 20 "int calculer_age" fonctions.c
```{{exec}}

## Vérification

Confirmez que l'affichage fonctionne :

```
printf "17/05/2026\n1\n0\n0\n" | ./annuaire | grep -c "," > /tmp/step3_result.txt
cat /tmp/step3_result.txt
```{{exec}}

> ✅ Si vous voyez un nombre supérieur à 90, cliquez sur **Check**.
