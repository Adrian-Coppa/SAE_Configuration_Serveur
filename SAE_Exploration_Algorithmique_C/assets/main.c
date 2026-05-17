#include "fonctions.h"
#include <locale.h>

int main() {
    // rendre affichable les caract�res accentu�s
    setlocale(LC_ALL, "");

    // allocation m�moire dynamique n�cessaire pour un fonctionnement avec 5000 entrees
    CLIENT *clients = malloc(MAX_CLIENTS * sizeof(CLIENT));
    if (clients == NULL) {
        printf("Erreur d'allocation m�moire.\n");
        return EXIT_FAILURE;
    }

    int nombre_clients = 0; // initialisation du nb clients � 0, avant qu'ils soient compt�s
    int choix;

    // Saisie d'une date r�f�rente pour calculer les ages
    char date_referente[11];
    saisir_date_referente(date_referente);

    // Charger les clients � partir du fichier
    charger_clients(clients, &nombre_clients);

    do {
        // Affichage du menu
        printf("\nMenu:\n");
        printf("1. Afficher tous les clients\n");
        printf("2. Ajouter un client\n");
        printf("3. Modifier un client\n");
        printf("4. Supprimer un client\n");
        printf("5. Rechercher un client\n");
        printf("6. Filtrer clients\n");
        printf("7. Afficher les clients avec informations manquantes\n");
        printf("8. Sauvegarder\n");
        printf("0. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                afficher_clients(clients, nombre_clients, date_referente);
                break;
            case 2:
                ajouter_client(clients, &nombre_clients);
                break;
            case 3:
                modifier_client(clients, nombre_clients);
                break;
            case 4:
                supprimer_client(clients, &nombre_clients);
                break;
            case 5:
                rechercher_client(clients, nombre_clients, date_referente);
                break;
            case 6:
                filtrer_clients(clients, nombre_clients, date_referente);
                break;
            case 7:
                afficher_clients_manquants(clients, nombre_clients, date_referente);
                break;
            case 8:
                sauvegarder_clients(clients, nombre_clients, annuaire);
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choix != 0);

    free(clients);
    return 0;
}
