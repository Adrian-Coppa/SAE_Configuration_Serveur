Nous allons maintenant configurer un hôte virtuel (VirtualHost) pour isoler la configuration de notre site local.

### Task 1 : Se déplacer dans le répertoire de configuration
Naviguez vers le dossier des sites disponibles d'Apache2 :
`cd /etc/apache2/sites-available`{{execute}}

### Task 2 : Créer le fichier de configuration
Créez et éditez un nouveau fichier nommé `mon-site.conf` :
`sudo nano mon-site.conf`{{execute}}

Ajoutez-y le contenu exact suivant :
```apache
<VirtualHost *:80>
    ServerName mon-site.local
    DocumentRoot /home/test/Desktop/Sites

    <Directory /home/test/Desktop/Sites>
        Options Indexes FollowSymLinks
        AllowOverride All
        Require all granted
    </Directory>
    
    ErrorLog ${APACHE_LOG_DIR}/error.log
    CustomLog ${APACHE_LOG_DIR}/access.log combined
</VirtualHost>
```

### Task 3 : Activer le site et redémarrer Apache2
Activez le site grâce aux outils d'Apache (a2ensite) et redémarrez complètement le service :
`sudo a2ensite mon-site.conf`{{execute}}

Vérifiez la syntaxe de configuration :
`sudo apache2ctl configtest`{{execute}}

Redémarrez Apache2 pour appliquer les changements :
`sudo systemctl restart apache2`{{execute}}

Vérifiez que Apache2 est bien en cours d'exécution :
`sudo systemctl status apache2`{{execute}}

Cliquez sur **Verify** une fois le VirtualHost configuré, activé et Apache2 redémarré.
