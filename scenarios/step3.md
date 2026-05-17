### Task 1 : Changement de port pour Apache2 (Port 8080)
Parfois, on souhaite écouter sur un autre port que le port 80. Modifions le fichier de configuration des ports d'Apache2 :
`sudo nano /etc/apache2/ports.conf`{{execute}}

Ajoutez la ligne `Listen 8080` juste en dessous de `Listen 80`.

Mettez également à jour votre fichier `mon-site.conf` pour écouter sur ce nouveau port :
`sudo nano /etc/apache2/sites-available/mon-site.conf`{{execute}}

Modifiez la première ligne : `<VirtualHost *:80>` devient `<VirtualHost *:8080>`.

### Task 2 : Vérifier la configuration et redémarrer Apache2
Vérifiez la syntaxe de configuration pour détecter les erreurs :
`sudo apache2ctl configtest`{{execute}}

Cette commande doit afficher **"Syntax OK"**. Si vous voyez une erreur, vérifiez vos modifications.

Redémarrez complètement Apache2 (pas seulement reload) pour appliquer les changements :
`sudo systemctl restart apache2`{{execute}}

Vérifiez que Apache2 est bien en cours d'exécution :
`sudo systemctl status apache2`{{execute}}

Vérifiez que Apache2 écoute bien sur le port 8080 :
`sudo ss -tuln | grep LISTEN | grep -E ':8080'`{{execute}}

Ou utilisez netstat si disponible :
`sudo netstat -tuln 2>/dev/null | grep 8080`{{execute}}

### Task 3 : Alignement des permissions (Droits d'accès)
Pour éviter les erreurs de type *Permission Denied* (403 Forbidden), attribuez la propriété du dossier à l'utilisateur web `www-data` et configurez les droits d'accès requis :

`sudo chmod -R 755 /home/test/Desktop/Sites`{{execute}}

`sudo chown -R www-data:www-data /home/test/Desktop/Sites`{{execute}}

`sudo chmod +x /home/test`{{execute}}

Cliquez sur **Verify** une fois le port 8080 configuré, Apache2 redémarré et les permissions définies.
