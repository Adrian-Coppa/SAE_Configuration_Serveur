Pour clore cette étude technique, nous allons reproduire la bascule vers l'environnement **Nginx** mentionnée dans la notice technique.

### Task 1 : Vérifier Apache2 avant d'arrêter
Vérifiez qu'Apache2 est bien en cours d'exécution sur le port 8080 :
`sudo ss -tuln | grep 8080`{{execute}}

### Task 2 : Arrêter Apache2 et démarrer Nginx
Libérons les ports en arrêtant complètement Apache2, puis démarrons Nginx :
`sudo systemctl stop apache2`{{execute}}

Vérifiez qu'Apache2 s'est bien arrêté :
`sudo systemctl status apache2`{{execute}}

Démarrez Nginx :
`sudo systemctl start nginx`{{execute}}

Vérifiez que Nginx est bien en cours d'exécution :
`sudo systemctl status nginx`{{execute}}

### Task 3 : Configuration du site sous Nginx
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

Sauvegardez et quittez (Ctrl+O, puis Ctrl+X).

### Task 4 : Vérifier la configuration Nginx et redémarrer
Vérifiez la syntaxe de configuration Nginx :
`sudo nginx -t`{{execute}}

Cela doit afficher : "nginx: configuration file test is successful"

Redémarrez Nginx pour appliquer la configuration :
`sudo systemctl restart nginx`{{execute}}

Vérifiez que Nginx écoute bien sur le port 8080 :
`sudo ss -tuln | grep 8080`{{execute}}

### Task 5 : Tester l'accès à Nginx
Vérifiez que Nginx répond correctement sur le port 8080 :
`curl http://mon-site.local:8080`{{execute}}

Si le code HTML de votre page sur les "cafés" s'affiche, votre bascule vers Nginx est réussie !

Cliquez sur **Verify** une fois Nginx configuré et fonctionnel sur le port 8080.
