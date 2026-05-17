#!/bin/bash
# Vérifie la présence du DNS local dans /etc/hosts et la réponse du curl
grep -q "mon-site.local" /etc/hosts && curl -s http://mon-site.local:8080 | grep -q "Les différents types de café" && exit 0
exit 1
