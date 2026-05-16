Pour pouvoir joindre votre site via l'URL `http://mon-site.local:8080` au lieu de l'adresse IP `127.0.0.1`, vous devez modifier le fichier d'adresse local (DNS local).

### Task 1 : Modifier le fichier hosts
Ouvrez le fichier `/etc/hosts`:
`sudo nano /etc/hosts`{{execute}}

Ajoutez la ligne suivante à la fin du fichier pour lier l'adresse de bouclage à votre nom de domaine personnalisé:
`127.0.0.1 mon-site.local`

### Task 2 : Tester le déploiement local
Vérifions si le serveur répond correctement et renvoie bien notre site sur le port 8080 avec le nom de domaine défini:
`curl http://mon-site.local:8080`{{execute}}

Si le code HTML de votre page sur les "cafés" s'affiche, votre déploiement Apache2 est une réussite totale!

Cliquez sur **Verify** une fois le DNS configuré et le test réussi.
