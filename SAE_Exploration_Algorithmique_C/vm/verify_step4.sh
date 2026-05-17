#!/bin/bash
cd /root/annuaire
RESULT=$(printf "17/05/2026\n5\nGomez\n0\n" | ./annuaire 2>/dev/null | grep -i "gomez")
if [ -n "$RESULT" ]; then
    echo "Recherche validée : client Gomez trouvé."
    exit 0
else
    echo "Aucun résultat pour 'Gomez'. Avez-vous bien exécuté la recherche ?"
    exit 1
fi
