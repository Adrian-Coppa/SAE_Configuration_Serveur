[cite_start]Pour clore cette étude technique, nous allons reproduire la bascule vers l'environnement **Nginx** mentionnée en seconde partie du document[cite: 280].

### Task 1 : Arrêter Apache2 et démarrer Nginx
[cite_start]Libérons les ports en coupant Apache2, puis démarrons Nginx[cite: 282, 283, 284]:
`sudo systemctl stop apache2`{{execute}}
`sudo systemctl start nginx`{{execute}}

### Task 2 : Configuration du site sous Nginx
[cite_start]Créons un fichier de bloc serveur propre à Nginx pour pointer vers notre site[cite: 289, 290]:
`sudo nano /etc/nginx/sites-enabled/mon-site`{{execute}}

[cite_start]Insérez la configuration équivalente pour Nginx[cite: 291]:
```nginx
server {
    listen 81;
    server_name mon-site.local;
    root /home/test/Desktop/Sites;
    index index.html;

    location / {
        try_files $uri $uri/ =404;
    }
}
