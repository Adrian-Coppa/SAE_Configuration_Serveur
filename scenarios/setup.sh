#!/bin/bash
# 1. Forcer la mise à jour et installer immédiatement tous les outils requis
apt-get update -y
apt-get install -y apache2 nginx curl nano

# 2. Créer l'arborescence complète pour le site web (Éviter le dossier manquant)
mkdir -p /home/test/Desktop/Sites

# 3. Créer le site web de démonstration pour Apache2 (Step 4)
mkdir -p /var/www/mon-site.local
cat << 'EOF' > /var/www/mon-site.local/index.html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Les différents types de café</title>
</head>
<body>
    <h1>Les différents types de café</h1>
    <h2>Accueil - Histoire du café</h2>
    <p>Le café est une boisson chaude obtenue par l'infusion de grains de café torréfiés et moulus, puis versée dans l'eau bouillante. Son histoire remonte au 15ème siècle en Éthiopie.</p>
</body>
</html>
EOF

# Définir les permissions correctes pour le répertoire
chown -R www-data:www-data /var/www/mon-site.local
chmod -R 755 /var/www/mon-site.local

# 4. Créer le site web de démonstration pour Nginx (Page 7 du document)
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

# 5. Préparer proprement l'arborescence Nginx pour éviter le bug de l'étape 5
mkdir -p /etc/nginx/sites-available
mkdir -p /etc/nginx/sites-enabled

# 6. Configurer l'état initial des services conformes au début du TP (Nginx actif, Apache2 coupé)
systemctl stop apache2
systemctl start nginx
