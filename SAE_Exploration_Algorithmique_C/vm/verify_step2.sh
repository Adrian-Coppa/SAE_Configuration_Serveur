#!/bin/bash
if [ -f /root/annuaire/annuaire ]; then
    echo "Compilation réussie !"
    exit 0
else
    echo "L'exécutable /root/annuaire/annuaire est introuvable. Avez-vous bien exécuté gcc ?"
    exit 1
fi
