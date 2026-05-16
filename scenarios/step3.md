### Task 1 : Option de changement de port (Port 8080)
Parfois, on souhaite écouter sur un autre port que le port 80. Modifions le fichier de configuration des ports d'Apache2:
`sudo nano /etc/apache2/ports.conf`{{execute}}

Ajoutez la ligne `Listen 8080` juste en dessous de `Listen 80`.

Mettez également à jour votre fichier `mon-site.conf` pour écouter sur ce nouveau port:
`sudo nano /etc/apache2/sites-available/mon-site.conf`{{execute}}
Modifiez la première ligne : `<VirtualHost *:80>` devient `<VirtualHost *:8080>`.

Rechargez Apache2 pour appliquer les changements:
`sudo systemctl reload apache2`{{execute}}

### Task 2 : Alignement des permissions (Droits d'accès)
Pour éviter les erreurs de type *Permission Denied* (403 Forbidden), attribuez la propriété du dossier à l'utilisateur web `www-data` et configurez les droits d'accès requis:

`sudo chmod -R 755 /home/test/Desktop/Sites`{{execute}}
`sudo chown -R www-data:www-data /home/test/Desktop/Sites`{{execute}}
`sudo chmod +x /home/test`{{execute}}

Cliquez sur **Verify** une fois le port 8080 configuré et les permissions définies.
