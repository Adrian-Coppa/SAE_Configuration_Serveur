Pour clore cette étude technique, nous allons reproduire la bascule vers l'environnement **Nginx** mentionnée dans la notice technique.

### Task 1 : Arrêter Apache2 et démarrer Nginx
Libérons les ports en coupant Apache2, puis démarrons Nginx :
`sudo systemctl stop apache2`{{execute}}
`sudo systemctl start nginx`{{execute}}

### Task 2 : Configuration du site sous Nginx
Créons le fichier de configuration pour notre site internet dans le répertoire de Nginx :
`sudo nano /etc/nginx/sites-enabled/mon-site`{{execute}}

Insérez la configuration correspondante pour Nginx :
```nginx
server {
    listen 8080;
    server_name mon-site.local;
    root /home/test/Desktop/Sites;
    index index.html;

    location / {
        try_files $uri $uri/ =404;
    }
}
```

### Task 3 : Redémarrer Nginx et tester l'accès
Appliquez la configuration en redémarrant le serveur Nginx :
`sudo systemctl restart nginx`{{execute}}
Vérifiez que Nginx répond correctement sur le port 8080 :
`curl http://mon-site.local:8080`{{execute}}

Cliquez sur **Verify** une fois Nginx configuré et fonctionnel sur le port 8080.
