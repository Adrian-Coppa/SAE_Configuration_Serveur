#!/bin/bash
cd /root/annuaire
COUNT=$(printf "17/05/2026\n1\n0\n0\n" | ./annuaire 2>/dev/null | grep -c ",")
if [ "$COUNT" -gt 90 ]; then
    echo "Affichage validé : $COUNT lignes de clients détectées."
    exit 0
else
    echo "Résultat inattendu ($COUNT lignes). Avez-vous bien lancé le programme ?"
    exit 1
fi
