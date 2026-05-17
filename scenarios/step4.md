Pour pouvoir joindre votre site via l'URL `http://mon-site.local:8080` au lieu de l'adresse IP `127.0.0.1`, vous devez modifier le fichier d'adresse local (DNS local).

### Tâche 1 : Modifier le fichier hosts

Ouvrez le fichier `/etc/hosts` :

`sudo nano /etc/hosts`{{execute}}

Ajoutez la ligne suivante à la fin du fichier :

`127.0.0.1 mon-site.local`

Appuyez sur **Ctrl+O** pour enregistrer, puis **Ctrl+X** pour quitter nano.

### Tâche 2 : Vérifier le DNS et l'état d'Apache2

Vérifiez que la résolution DNS est bien configurée :

`cat /etc/hosts | grep mon-site.local`{{execute}}

`ping -c 1 mon-site.local`{{execute}}

Vérifiez qu'Apache2 écoute toujours sur le port 8080 :

`sudo ss -tuln | grep 8080`{{execute}}

### Tâche 3 : Tester le déploiement

Testez l'accès à votre site via le nom de domaine :

`curl http://mon-site.local:8080`{{execute}}

Si le code HTML de votre page sur les "cafés" s'affiche, votre déploiement Apache2 est réussi !

Cliquez sur **Verify** une fois le DNS configuré et le test réussi.
