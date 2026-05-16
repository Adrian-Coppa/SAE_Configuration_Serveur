Dans cette étape préliminaire, nous allons vérifier l'état des services web. Il est fréquent qu'un autre service (comme Nginx) soit actif par défaut et bloque le port 80.

### Tâche 0 : installation de Nginx et d'Apache2 
Il est nécessaire d'installer Nginx et Apache2 pour le déroulé de ce tutoriel
`apt-get update && apt-get install -y apache2 nginx curl nano`{{execute}}

### Task 1 : Vérifier le statut de Nginx
Exécutez la commande suivante pour constater que Nginx est actif:
`sudo systemctl status nginx.service`{{execute}}

### Task 2 : Arrêter Nginx
Afin de pouvoir lancer Apache2 librement, arrêtez le service Nginx:
`sudo systemctl stop nginx.service`{{execute}}

### Task 3 : Démarrer Apache2
Maintenant, démarrez le service Apache2 et assurez-vous qu'il tourne correctement:
`sudo systemctl start apache2`{{execute}}
`sudo systemctl status apache2`{{execute}}

Cliquez sur **Verify** une fois Apache2 démarré et Nginx arrêté.
