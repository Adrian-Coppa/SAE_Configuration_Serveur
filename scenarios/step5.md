Pour clore cette étude technique, nous allons reproduire la bascule vers l'environnement **Nginx** mentionnée dans la notice technique.

### Tâche 1 : Arrêter Apache2 et démarrer Nginx

Vérifiez qu'Apache2 est bien en cours d'exécution sur le port 8080 :

`sudo ss -tuln | grep 8080`{{execute}}

Arrêtez Apache2 et démarrez Nginx :

`sudo systemctl stop apache2`{{execute}}

`sudo systemctl start nginx`{{execute}}

Vérifiez l'état des services :

`sudo systemctl status nginx`{{execute}}

### Tâche 2 : Configurer Nginx

Créez le fichier de configuration pour notre site :

`sudo nano /etc/nginx/sites-enabled/mon-site`{{execute}}

Insérez la configuration correspondante :

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

Appuyez sur **Ctrl+O** pour enregistrer, puis **Ctrl+X** pour quitter nano.

### Tâche 3 : Vérifier la configuration et redémarrer Nginx

Vérifiez la syntaxe de configuration Nginx :

`sudo nginx -t`{{execute}}

Redémarrez Nginx :

`sudo systemctl restart nginx`{{execute}}

Vérifiez que Nginx écoute bien sur le port 8080 :

`sudo ss -tuln | grep 8080`{{execute}}

### Tâche 4 : Tester l'accès à Nginx

Testez l'accès à votre site via Nginx :

`curl http://mon-site.local:8080`{{execute}}

Si le code HTML de votre page sur les "cafés" s'affiche, votre bascule vers Nginx est réussie !

Cliquez sur **Verify** une fois Nginx configuré et fonctionnel.
