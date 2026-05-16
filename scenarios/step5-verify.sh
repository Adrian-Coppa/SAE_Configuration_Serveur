### `step5-verify.sh`
```bash
#!/bin/bash
# Vérifie que Nginx répond correctement sur le port 81
curl -s http://mon-site.local:81 | grep -q "Les différents types de café" && exit 0
exit 1
