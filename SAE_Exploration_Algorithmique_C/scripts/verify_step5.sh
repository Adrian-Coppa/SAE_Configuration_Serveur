#!/bin/bash
cd /root/annuaire
# Run: add a test client, save, then check it's in the CSV
printf "17/05/2026\n2\nTest\nKillercoda\nPARIS 75001\n09.99.99.99.99\ntest@kc.fr\netudiant\n01/01/2000\n8\n0\n" | ./annuaire > /dev/null 2>&1
if grep -q "09.99.99.99.99" annuaire_100_entrees.csv; then
    echo "Sauvegarde validée : le nouveau client est présent dans le fichier CSV."
    exit 0
else
    echo "Le client de test n'a pas été trouvé dans le fichier CSV. Avez-vous bien sauvegardé (option 8) ?"
    exit 1
fi
