### Tâche 1 : Configurer Apache2 pour le port 8080

Modifions le fichier de configuration des ports d'Apache2 :

`sudo nano /etc/apache2/ports.conf`{{execute}}

Ajoutez la ligne `Listen 8080` juste en dessous de `Listen 80`.

Mettez également à jour votre fichier `mon-site.conf` pour écouter sur ce nouveau port :

`sudo nano /etc/apache2/sites-available/mon-site.conf`{{execute}}

Modifiez la première ligne : `<VirtualHost *:80>` devient `<VirtualHost *:8080>`.

Appuyez sur **Ctrl+O** pour enregistrer, puis **Ctrl+X** pour quitter nano.

### Tâche 2 : Vérifier la configuration et redémarrer Apache2

Vérifiez la syntaxe de configuration :

`sudo apache2ctl configtest`{{execute}}

Redémarrez Apache2 pour appliquer les changements :

`sudo systemctl restart apache2`{{execute}}

Vérifiez l'état d'Apache2 et qu'il écoute bien sur le port 8080 :

`sudo systemctl status apache2`{{execute}}

`sudo ss -tuln | grep LISTEN | grep -E ':8080'`{{execute}}

### Tâche 3 : Configurer les permissions

Pour éviter les erreurs de type *Permission Denied* (403 Forbidden), attribuez la propriété du dossier à l'utilisateur web `www-data` :

`sudo chmod -R 755 /home/test/Desktop/Sites`{{execute}}

`sudo chown -R www-data:www-data /home/test/Desktop/Sites`{{execute}}

`sudo chmod +x /home/test`{{execute}}

Cliquez sur **Verify** une fois le port 8080 configuré et les permissions définies.
