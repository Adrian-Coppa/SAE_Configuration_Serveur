Dans cette étape préliminaire, nous allons vérifier l'état des services web. [cite_start]Il est fréquent qu'un autre service (comme Nginx) soit actif par défaut et bloque le port 80[cite: 28, 29].

### Task 1 : Vérifier le statut de Nginx
[cite_start]Exécutez la commande suivante pour constater que Nginx est actif[cite: 30]:
`sudo systemctl status nginx.service`{{execute}}

### Task 2 : Arrêter Nginx
[cite_start]Afin de pouvoir lancer Apache2 librement, arrêtez le service Nginx[cite: 34]:
`sudo systemctl stop nginx.service`{{execute}}

### Task 3 : Démarrer Apache2
[cite_start]Maintenant, démarrez le service Apache2 et assurez-vous qu'il tourne correctement[cite: 42, 47, 48]:
`sudo systemctl start apache2`{{execute}}
`sudo systemctl status apache2`{{execute}}

Cliquez sur **Verify** une fois Apache2 démarré et Nginx arrêté.
