#!/bin/bash

# Debug - Afficher où on est et ce qui existe
echo "=== DEBUG ==="
echo "Current directory: $(pwd)"
echo "Listing root directory:"
ls -la /
echo "Listing current directory:"
ls -la
echo "=============="

# Killer Coda clone votre repo dans /workspace (généralement)
# Ou les fichiers sont dans le répertoire courant
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TUTORIAL_DIR="$(dirname "$SCRIPT_DIR")"

echo "Script directory: $SCRIPT_DIR"
echo "Tutorial directory: $TUTORIAL_DIR"

# Créer le répertoire cible
mkdir -p /root/annuaire

# Chercher les fichiers - essayer plusieurs emplacements possibles
if [ -d "$TUTORIAL_DIR/assets" ]; then
    echo "Found assets at: $TUTORIAL_DIR/assets"
    cp "$TUTORIAL_DIR/assets/"* /root/annuaire/
elif [ -d "./assets" ]; then
    echo "Found assets in current directory"
    cp ./assets/* /root/annuaire/
elif [ -d "/workspace/assets" ]; then
    echo "Found assets in /workspace"
    cp /workspace/assets/* /root/annuaire/
elif [ -d "/root/assets" ]; then
    echo "Found assets in /root"
    cp /root/assets/* /root/annuaire/
else
    echo "ERROR: Cannot find assets directory"
    echo "Searching for assets directory..."
    find / -name "assets" -type d 2>/dev/null
fi

# Vérifier le résultat
echo "=== Files copied to /root/annuaire/ ==="
ls -la /root/annuaire/
echo "========================================"
