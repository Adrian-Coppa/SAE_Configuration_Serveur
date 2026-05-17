[cite_start]Pour pouvoir joindre votre site via l'URL `http://mon-site.local:8080` au lieu de l'adresse IP `127.0.0.1`, vous devez modifier le fichier d'adresse local (DNS local)[cite: 142, 155].

### Task 1 : Modifier le fichier hosts
[cite_start]Ouvrez le fichier `/etc/hosts`[cite: 144, 145]:
`sudo nano /etc/hosts`{{execute}}

[cite_start]Ajoutez la ligne suivante à la fin du fichier pour lier l'adresse de bouclage à votre nom de domaine personnalisé[cite: 149, 152]:
`127.0.0.1 mon-site.local`

### Task 2 : Tester le déploiement local
[cite_start]Vérifions si le serveur répond correctement et renvoie bien notre site sur le port 8080 avec le nom de domaine défini[cite: 155]:
`curl http://mon-site.local:8080`{{execute}}

[cite_start]Si le code HTML de votre page sur les "cafés" s'affiche, votre déploiement Apache2 est une réussite totale!
