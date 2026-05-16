[cite_start]Nous allons maintenant configurer un hôte virtuel (VirtualHost) pour isoler la configuration de notre site local[cite: 101].

### Task 1 : Se déplacer dans le répertoire de configuration
[cite_start]Naviguez vers le dossier des sites disponibles d'Apache2[cite: 102]:
`cd /etc/apache2/sites-available`{{execute}}

### Task 2 : Créer le fichier de configuration
[cite_start]Créez et éditez un nouveau fichier nommé `mon-site.conf`[cite: 103, 104]:
`sudo nano mon-site.conf`{{execute}}

[cite_start]Ajoutez-y le contenu suivant, qui pointe vers le dossier absolu de notre site web[cite: 105, 110, 113, 115]:

```apache
<VirtualHost *:80>
    ServerName mon-site.local
    DocumentRoot /home/test/Desktop/Sites

    <Directory /home/test/Desktop/Sites>
        AllowOverride All
        Require all granted
    </Directory>
</VirtualHost>
