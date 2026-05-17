## Etape 0 : Configuration initiale du serveur

Dans cette étape préliminaire, nous allons exécuter toutes les configurations initiales nécessaires pour préparer votre serveur avant de commencer les étapes suivantes.

## Task 1 : Mise à jour du système et installation des outils requis

Mettez à jour le système et installez Apache2, Nginx et les outils essentiels :

`apt-get update -y`{{execute}}

`apt-get install -y apache2 nginx curl nano`{{execute}}

## Task 2 : Création de l'arborescence des sites

Créez le dossier de destination pour les sites web :

`mkdir -p /home/test/Desktop/Sites`{{execute}}

## Task 3 : Création du site web Apache2

Créez le dossier et le fichier index.html pour Apache2 :

`mkdir -p /var/www/mon-site.local`{{execute}}



Définissez les permissions correctes pour le répertoire Apache2 :

`chown -R www-data:www-data /var/www/mon-site.local`{{execute}}

`chmod -R 755 /var/www/mon-site.local`{{execute}}

## Task 4 : Création du site web Nginx

Créez le fichier index.html pour Nginx :



## Task 5 : Préparation de la configuration Nginx

Préparez l'arborescence Nginx :

`mkdir -p /etc/nginx/sites-available`{{execute}}

`mkdir -p /etc/nginx/sites-enabled`{{execute}}

## Task 6 : Configuration des services

Arrêtez Apache2 et démarrez Nginx :

`systemctl stop apache2 || true`{{execute}}

`systemctl start nginx`{{execute}}

Vérifiez l'état de Nginx :

`sudo systemctl status nginx`{{execute}}

Cliquez sur **Verify** une fois toutes les configurations initiales terminées.
