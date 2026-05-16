#!/bin/bash
# Vérifie que Nginx répond correctement sur le port 8080
curl -s http://mon-site.local:8080 | grep -q "Les différents types de café" && exit 0
exit 1
