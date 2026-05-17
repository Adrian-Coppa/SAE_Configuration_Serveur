#!/bin/bash
# Vérifie que nginx est arrêté et apache2 est démarré
systemctl is-active --quiet nginx && exit 1
systemctl is-active --quiet apache2 && exit 0
exit 1
