Pour commencer, nous allons vérifier l'état des services web. Il est fréquent qu'un autre service (comme Nginx) soit actif par défaut et bloque le port 80.

### Tâche 1 : Vérifier l'état de Nginx

Exécutez la commande suivante pour constater si Nginx est actif :

`sudo systemctl status nginx.service`{{execute}}

### Tâche 2 : Arrêter Nginx

Afin de pouvoir lancer Apache2 librement, arrêtez le service Nginx et désactivez-le au démarrage :

`sudo systemctl stop nginx.service`{{execute}}

`sudo systemctl disable nginx.service`{{execute}}

### Tâche 3 : Activer et démarrer Apache2

Activez Apache2 au démarrage et démarrez-le :

`sudo systemctl enable apache2`{{execute}}

`sudo systemctl start apache2`{{execute}}

### Tâche 4 : Vérifier les services

Vérifiez que Apache2 est en cours d'exécution :

`sudo systemctl status apache2`{{execute}}

Vérifiez qu'Apache2 écoute bien sur le port 80 :

`sudo ss -tuln | grep LISTEN | grep -E ':80'`{{execute}}

Cliquez sur **Verify** une fois Apache2 démarré et Nginx arrêté.
