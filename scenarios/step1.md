Dans cette étape préliminaire, nous allons vérifier l'état des services web. Il est fréquent qu'un autre service (comme Nginx) soit actif par défaut et bloque le port 80.

### Task 0 : Vérifier et installer les services nécessaires
Vérifiez si Apache2 et Nginx sont installés, sinon installez-les :
`sudo apt-get update`{{execute}}

`sudo apt-get install -y apache2 nginx curl nano`{{execute}}

### Task 1 : Vérifier l'état de Nginx
Exécutez la commande suivante pour constater si Nginx est actif :
`sudo systemctl status nginx.service`{{execute}}

### Task 2 : Arrêter Nginx et activer Apache2
Afin de pouvoir lancer Apache2 librement, arrêtez le service Nginx :
`sudo systemctl stop nginx.service`{{execute}}

Désactivez Nginx au démarrage (optionnel mais recommandé) :
`sudo systemctl disable nginx.service`{{execute}}

Activez Apache2 au démarrage :
`sudo systemctl enable apache2`{{execute}}

### Task 3 : Démarrer Apache2
Maintenant, démarrez le service Apache2 et assurez-vous qu'il tourne correctement :
`sudo systemctl start apache2`{{execute}}

`sudo systemctl status apache2`{{execute}}

### Task 4 : Vérifier que les ports sont libérés correctement
Vérifiez qu'Apache2 écoute bien sur le port 80 :
`sudo ss -tuln | grep LISTEN | grep -E ':80 '