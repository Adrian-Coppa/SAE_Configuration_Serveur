#include "fonctions.h"

void charger_clients(CLIENT clients[], int *nombre_clients) {
    FILE *fichier = fopen(annuaire, "r"); // ouvrir le fichier annuaire
    if (fichier == NULL) {
        printf("Echec ouverture fichier\n");
        exit(EXIT_FAILURE);
    }

    char ligne[500];
    *nombre_clients = 0;

    while (*nombre_clients < MAX_CLIENTS && fgets(ligne, sizeof(ligne), fichier)) {
        // Enl�ve le caract�re de nouvelle ligne
        int len = strlen(ligne);
        if (ligne[len - 1] == '\n') {
            ligne[len - 1] = '\0';
        }

        // initialisation  d'un tableau de client
        CLIENT client = {"", "", "", "", "", "", ""};
        int i = 0, champ = 0, j = 0;

        while (ligne[i] != '\0') {
            if (ligne[i] == ',') {
                switch (champ) {
                    case 0: client.prenom[j] = '\0'; break;
                    case 1: client.nom[j] = '\0'; break;
                    case 2: client.ville_cp[j] = '\0'; break;
                    case 3: client.telephone[j] = '\0'; break;
                    case 4: client.adresse_mel[j] = '\0'; break;
                    case 5: client.profession[j] = '\0'; break;
                    case 6: client.date_naissance[j] = '\0'; break;
                }
                champ++;
                j = 0;
            } else {
                switch (champ) {
                    case 0: client.prenom[j++] = ligne[i]; break;
                    case 1: client.nom[j++] = ligne[i]; break;
                    case 2: client.ville_cp[j++] = ligne[i]; break;
                    case 3: client.telephone[j++] = ligne[i]; break;
                    case 4: client.adresse_mel[j++] = ligne[i]; break;
                    case 5: client.profession[j++] = ligne[i]; break;
                    case 6: client.date_naissance[j++] = ligne[i]; break;
                }
            }
            i++;
        }
        // G�rer le dernier champ
        if (champ <= 6) {
            switch (champ) {
                case 0: client.prenom[j] = '\0'; break;
                case 1: client.nom[j] = '\0'; break;
                case 2: client.ville_cp[j] = '\0'; break;
                case 3: client.telephone[j] = '\0'; break;
                case 4: client.adresse_mel[j] = '\0'; break;
                case 5: client.profession[j] = '\0'; break;
                case 6: client.date_naissance[j] = '\0'; break;
            }
        }

        if (strlen(client.telephone) > 0) {
            clients[*nombre_clients] = client;
            (*nombre_clients)++; // on compte le nombre de clients en fonction de la cl� primaire
        }
    }

    fclose(fichier);
}

void ajouter_client(CLIENT clients[], int *nombre_clients) {
    if (*nombre_clients >= MAX_CLIENTS) {
        printf("Limite de clients atteinte.\n");
        return;
    }

    printf("Ajouter un nouveau client:\n");
    printf("Pr�nom: ");
    scanf("%99s", clients[*nombre_clients].prenom); //format: limite a 99 carac : �vite d�passement buffer
    printf("Nom: ");
    scanf(" %[^\n]s", clients[*nombre_clients].nom); //lit jusqu'au saut de ligne
    printf("Ville et Code Postal: ");
    scanf(" %[^\n]s", clients[*nombre_clients].ville_cp);
    printf("Num�ro de t�l�phone: ");
    scanf("%99s", clients[*nombre_clients].telephone);
    printf("Adresse e-mail: ");
    scanf("%99s", clients[*nombre_clients].adresse_mel);
    printf("Profession: ");
    scanf("%99s", clients[*nombre_clients].profession);
    printf("Date de naissance (DD/MM/YYYY): ");
    scanf("%99s", clients[*nombre_clients].date_naissance);

    (*nombre_clients)++;
}

void modifier_client(CLIENT clients[], int nombre_clients) {
    char telephone[MAX_LENGTH];
    int i;

    printf("Entrez le num�ro de t�l�phone du client � modifier: ");
    scanf("%99s", telephone);

    for (i = 0; i < nombre_clients; i++) {
        if (strcmp(clients[i].telephone, telephone) == 0) {
            printf("Modifier le client: %s, %s, %s, %s, %s, %s, %s\n",
               clients[i].nom, clients[i].prenom,
               clients[i].ville_cp, clients[i].telephone,
               clients[i].adresse_mel, clients[i].profession,
               clients[i].date_naissance
               );

            printf("Selectionner champ � modifier : Nom: 1, Pr�nom: 2, Ville et CP: 3, Mel: 4, Profession: 5, Date naissance: 6, Annuler: 7\n");
            int champ;
            scanf("%d", &champ);

            switch(champ) {
                case 1:
                    printf("Nouveau nom: ");
                    scanf("%[^\n]s", clients[i].nom);
                    while (getchar() != '\n'); // nettoyer le buffer pour continuer
                    break;
                case 2:
                    printf("Nouveau pr�nom: ");
                    scanf("%99s", clients[i].prenom);
                    while (getchar() != '\n');
                    break;
                case 3:
                    printf("Nouvelle ville et CP: ");
                    scanf("%[^\n]s", clients[i].ville_cp);
                    while (getchar() != '\n');
                    break;
                case 4:
                    printf("Nouveau mel: ");
                    scanf("%99s", clients[i].adresse_mel);
                    while (getchar() != '\n');
                    break;
                case 5:
                    printf("Nouvelle profession: ");
                    scanf("%99s", clients[i].profession);
                    while (getchar() != '\n');
                    break;
                case 6:
                    printf("Nouvelle date naissance: ");
                    scanf("%99s", clients[i].date_naissance);
                    while (getchar() != '\n');
                    break;
                case 7:
                    return;
                default:
                    printf("Choix invalide. Veuillez r�essayer.\n");
            }
            printf("Client modifi�!\n");
            return;
        }
    }
    printf("Client non trouv�.\n");
}

void supprimer_client(CLIENT clients[], int *nombre_clients) {
    char telephone[MAX_LENGTH];
    printf("Entrez le num�ro de t�l�phone du client � supprimer: ");
    scanf("%99s", telephone);

    for (int i = 0; i < *nombre_clients; i++) {
        if (strcmp(clients[i].telephone, telephone) == 0) {
            for (int j = i; j < *nombre_clients - 1; j++) {
                clients[j] = clients[j + 1]; // D�calage vers la gauche
            }
            (*nombre_clients)--; // R�duire le nombre de clients en cons�quence
            printf("Client supprim�.\n");
            return;
        }
    }

    printf("Client non trouv�.\n");
}

void afficher_clients(CLIENT clients[], int nombre_clients, const char *date_referente) {
    if (nombre_clients == 0) {
        printf("Aucun client � afficher.\n");
        return;
    }

    int critere;
    printf("Choisissez un crit�re de tri:\n");
    printf("1. Nom\n");
    printf("2. Code Postal\n");
    printf("3. Profession\n");
    printf("4. Date de Naissance\n");
    printf("0. Sans tri\n");
    printf("Choix: ");
    scanf("%d", &critere);

    if (critere >= 1 && critere <= 4) {
        trier_clients(clients, nombre_clients, critere);
    } else if (critere != 0) {
        printf("Choix invalide. Aucun tri appliqu�.\n");
    }

    printf("\nListe des clients:\n");
    for (int i = 0; i < nombre_clients; i++) {
        int age = calculer_age(clients[i].date_naissance, date_referente);
        printf("%s, %s, %s, %s, %s, %s",
               clients[i].nom, clients[i].prenom,
               clients[i].ville_cp, clients[i].telephone,
               clients[i].adresse_mel, clients[i].profession
               );
            if (strlen(clients[i].date_naissance) > 0 && age > 0) {
                printf(", %d ans\n", age); // n'affiche l'�ge que s'il existe
            } else {
                printf("\n");
        }
    }
}

void rechercher_client(CLIENT clients[], int nombre_clients, const char *date_referente) {
    char recherche[MAX_LENGTH];
    printf("Entrez le crit�re de recherche (nom, pr�nom, t�l�phone ou email) : ");
    scanf(" %[^\n]s", recherche); // Permet de lire des entr�es avec espaces

    int trouve = 0; // Pour suivre si un client a �t� trouv�

    for (int i = 0; i < nombre_clients; i++) {
        if (stricmp(clients[i].nom, recherche) == 0 ||
            stricmp(clients[i].prenom, recherche) == 0 ||
            stricmp(clients[i].telephone, recherche) == 0 ||
            stricmp(clients[i].adresse_mel, recherche) == 0) {

            int age = calculer_age(clients[i].date_naissance, date_referente);
            printf("%s, %s, %s, %s, %s, %s",
                   clients[i].nom, clients[i].prenom,
                   clients[i].ville_cp, clients[i].telephone,
                   clients[i].adresse_mel, clients[i].profession);

            if (age > 0) {
                printf(", %d ans\n", age); // n'affiche l'�ge que s'il existe
            } else {
                printf("\n");
            }
            trouve = 1; // Un client a �t� trouv�
        }
    }

    if (!trouve) {
        printf("Aucun client trouv� avec le crit�re '%s'.\n", recherche);
    }
}

void trier_clients(CLIENT clients[], int nombre_clients, int critere) {
    for (int i = 0; i < nombre_clients - 1; i++) {
        for (int j = 0; j < nombre_clients - i - 1; j++) {
            int comparaison = 0;

            switch (critere) {
                case 1: // Tri par nom
                    comparaison = strcmp(clients[j].nom, clients[j + 1].nom);
                    break;
                case 2: // Tri par code postal
                    comparaison = strcmp(clients[j].ville_cp, clients[j + 1].ville_cp);
                    break;
                case 3: // Tri par profession
                    comparaison = strcmp(clients[j].profession, clients[j + 1].profession);
                    break;
                case 4: // Tri par date de naissance
                    comparaison = strcmp(clients[j].date_naissance, clients[j + 1].date_naissance);
                    break;
                default:
                    break;
            }

            if (comparaison > 0) {
                CLIENT temp = clients[j];
                clients[j] = clients[j + 1];
                clients[j + 1] = temp;
            }
        }
    }
}

void filtrer_clients(CLIENT clients[], int nombre_clients, const char *date_referente) {
    char critere[MAX_LENGTH];
    printf("Entrez le crit�re de filtrage (nom, pr�nom, profession ou code postal) : ");
    scanf(" %[^\n]s", critere); // Permet de lire des entr�es avec espaces

    int age_critere = -1; // Utilis� pour filtrer par l'�ge, par d�faut � -1 si non sp�cifi�
    char choix;

    printf("Souhaitez-vous filtrer aussi par �ge (O/N) ? ");
    scanf(" %c", &choix);

    if (choix == 'O' || choix == 'o') {
        printf("Entrez l'�ge : ");
        scanf("%d", &age_critere);
    }

    printf("\nClients correspondants au crit�re '%s':\n", critere);
    int trouve = 0;

    for (int i = 0; i < nombre_clients; i++) {
        int age = calculer_age(clients[i].date_naissance, date_referente);
        if ((strstr(clients[i].nom, critere) != NULL || // strstr permet de v�rifier la pr�sence d'une chaine dans une sous-chaine
             strstr(clients[i].prenom, critere) != NULL ||
             strstr(clients[i].profession, critere) != NULL ||
             strstr(clients[i].ville_cp, critere) != NULL) &&
             (age_critere == -1 || age == age_critere)) {
            printf("%s %s, %s, %s, %s, %s",
                   clients[i].nom, clients[i].prenom,
                   clients[i].ville_cp, clients[i].telephone,
                   clients[i].adresse_mel, clients[i].profession
                );
            if (strlen(clients[i].date_naissance) > 0 && age > 0) {
                printf(", %d ans\n", age); // n'affiche l'�ge que s'il existe
            } else {
                printf("\n");
            }
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun client trouv� correspondant au crit�re.\n");
    }
}

void afficher_clients_manquants(CLIENT clients[], int nombre_clients, const char *date_referente) {
    printf("Clients avec des informations manquantes :\n");
    for (int i = 0; i < nombre_clients; i++) {
        if (strlen(clients[i].nom) == 0 || strlen(clients[i].prenom) == 0 ||
            strlen(clients[i].ville_cp) == 0 || strlen(clients[i].adresse_mel) == 0 ||
            strlen(clients[i].profession) == 0 || strlen(clients[i].date_naissance) == 0) {
            int age = calculer_age(clients[i].date_naissance, date_referente);
        printf("%s, %s, %s, %s, %s, %s",
               clients[i].nom, clients[i].prenom,
               clients[i].ville_cp, clients[i].telephone,
               clients[i].adresse_mel, clients[i].profession
               );
            if (strlen(clients[i].date_naissance) > 0 && age > 0) {
                printf(", %d ans\n", age); // n'affiche l'�ge que s'il existe
            } else {
                printf("\n"); // Ligne vide si la date de naissance est non renseign�e
            }
        }
    }
}


// Pour la d�mo :
void saisir_date_referente(char *date_referente) {
    printf("Entrez la date d'aujourd'hui (JJ/MM/AAAA): ");
    scanf("%10s", date_referente);
}

int calculer_age(const char *date_naissance, const char *date_referente) {
    if (strlen(date_naissance) == 0) { // V�rifier si la date de naissance est vide
        return -1; // Indique que l'�ge est inconnu
    }

    int jour_naissance = 0, mois_naissance = 0, annee_naissance = 0;
    int jour_reference = 0, mois_reference = 0, annee_reference = 0;

    sscanf(date_naissance, "%d/%d/%d", &jour_naissance, &mois_naissance, &annee_naissance);
    sscanf(date_referente, "%d/%d/%d", &jour_reference, &mois_reference, &annee_reference);

    int age = annee_reference - annee_naissance;

    if (mois_reference < mois_naissance || (mois_reference == mois_naissance && jour_reference < jour_naissance)) {
        age--;
    }

    return age;
}

void sauvegarder_clients(CLIENT clients[], int nombre_clients, const char *nom_fichier) {
    FILE *fichier = fopen(nom_fichier, "w");
    if (fichier == NULL) {
        printf("Erreur: impossible d'ouvrir le fichier pour sauvegarde.\n");
        return;
    }

    for (int i = 0; i < nombre_clients; i++) {
        fprintf(fichier, "%s,%s,%s,%s,%s,%s,%s\n",
                clients[i].prenom, clients[i].nom,
                clients[i].ville_cp, clients[i].telephone,
                clients[i].adresse_mel, clients[i].profession,
                clients[i].date_naissance);
    }

    fclose(fichier);
    printf("Sauvegarde termin�e.\n");
}
