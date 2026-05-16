### `step2-verify.sh`
```bash
#!/bin/bash
# Vérifie si le fichier de conf existe et si le lien symbolique d'activation est présent
[ -f /etc/apache2/sites-available/mon-site.conf ] && [ -f /etc/apache2/sites-enabled/mon-site.conf ] && exit 0
exit 1
