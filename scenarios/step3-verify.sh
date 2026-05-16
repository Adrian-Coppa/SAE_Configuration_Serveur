#!/bin/bash
# Vérifie que le port 8080 est bien configuré et ouvert par apache
grep -q "Listen 8080" /etc/apache2/ports.conf && grep -q "<VirtualHost \*:8080>" /etc/apache2/sites-available/mon-site.conf && exit 0
exit 1
