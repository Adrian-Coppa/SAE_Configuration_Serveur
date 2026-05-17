## Etape 0 : Configuration initiale du serveur

Dans cette étape préliminaire, nous allons exécuter toutes les configurations initiales nécessaires pour préparer votre serveur avant de commencer les étapes suivantes.

## Tâche 1 : Mise à jour du système et installation des outils requis

Mettez à jour le système et installez Apache2, Nginx et les outils essentiels :

`apt-get update -y`{{execute}}

`apt-get install -y apache2 nginx curl nano`{{execute}}

## Tâche 2 : Création de l'arborescence des sites

Créez le dossier de destination pour les sites web :

`mkdir -p /home/test/Desktop/Sites`{{execute}}

## Tâche 3 : Création du site web Apache2

Créez le dossier pour Apache2 :

`mkdir -p /var/www/mon-site.local`{{execute}}

Créez le fichier index.html pour Apache2 :

`nano /var/www/mon-site.local/index.html`{{execute}}

Tapez le contenu suivant dans l'éditeur nano (vous pouvez copier-coller) :

```html
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
```

Appuyez sur **Ctrl+O** pour enregistrer, puis **Ctrl+X** pour quitter nano.

Définissez les permissions correctes pour le répertoire Apache2 :

`sudo chown -R www-data:www-data /var/www/mon-site.local`{{execute}}

`sudo chmod -R 755 /var/www/mon-site.local`{{execute}}

## Tâche 4 : Création du site web Nginx

Créez le fichier index.html pour Nginx :

`nano /home/test/Desktop/Sites/index.html`{{execute}}

Tapez le contenu suivant dans l'éditeur nano (vous pouvez copier-coller) :

```html
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
```

Appuyez sur **Ctrl+O** pour enregistrer, puis **Ctrl+X** pour quitter nano.

## Tâche 5 : Préparation de la configuration Nginx

Préparez l'arborescence Nginx :

`mkdir -p /etc/nginx/sites-available`{{execute}}

`mkdir -p /etc/nginx/sites-enabled`{{execute}}

## Tâche 6 : Configuration des services

Arrêtez Apache2 et démarrez Nginx :

`sudo systemctl stop apache2 || true`{{execute}}

`sudo systemctl start nginx`{{execute}}

Vérifiez l'état de Nginx :

`sudo systemctl status nginx`{{execute}}

Cliquez sur **Verify** une fois toutes les configurations initiales terminées.
