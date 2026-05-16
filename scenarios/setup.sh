#!/bin/bash
# Mise à jour et installation des serveurs web
apt-get update -y
apt-get install -y apache2 nginx curl nano

# Simulation de l'environnement utilisateur du document
mkdir -p /home/test/Desktop/Sites

# Création du site de démonstration sur le café (Page 7 du document)
cat << 'EOF' > /home/test/Desktop/Sites/index.html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Les différents types de café</title>
</head>
<body>
    <h1>Les différents types de café</h1>
    <h2>Accueil - Histoire du café</h2>
    <p>Le café est une boisson chaude obtenue par l'infusion de grains de café torréfiés...</p>
</body>
</html>
EOF

# S'assurer que Nginx est démarré par défaut comme stipulé dans le document (Page 2)
systemctl stop apache2
systemctl start nginx
