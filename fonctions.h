#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CLIENTS 5000 // a changer en fonction du nombre entr�es annuaire (100, 500, 1000, 5000...)
#define MAX_LENGTH 100
#define annuaire "annuaire_1000_entrees.csv"
// #define annuaire "annuaire_5000_entrees.csv"


typedef struct {
    char prenom[MAX_LENGTH];
    char nom[MAX_LENGTH];
    char ville_cp[MAX_LENGTH];   // Champ pour ville et code postal
    char telephone[MAX_LENGTH];   // Clef primaire
    char adresse_mel[MAX_LENGTH]; // Email
    char profession[MAX_LENGTH];
    char date_naissance[MAX_LENGTH];
} CLIENT;

/**
 *
 * @param clients: Tableau de CLIENT � remplir avec les donn�es du fichier.
 * @param nombre_clients: nombre actuel de clients.
 *
 * Pr�-condition: Le fichier des clients doit exister et �tre accessible.
 *
 * Sortie: Aucune
 *
 * Post-condition: Le tableau clients contient les informations des clients charg�s 
 * et nombre_clients est mis � jour avec le nombre de clients charg�s.
 *
 * Fait par : Kenzo
 */
void charger_clients(CLIENT clients[], int *nombre_clients);

/**
 *
 * @param clients: Tableau de CLIENT o� le nouveau client sera ajout�.
 * @param nombre_clients: Pointeur vers un entier qui contient le nombre actuel de clients.
 *
 * Pr�-condition: Le tableau clients doit avoir de la place pour un nouveau client.
 *
 * Sortie: Aucune
 *
 * Post-condition: Un nouveau client est ajout� � clients, et nombre_clients est incr�ment�.
 *
 * Fait par : Kenzo
 */
void ajouter_client(CLIENT clients[], int *nombre_clients);

/**
 *
 * @param clients: Tableau de CLIENT dont le client sera modifi�.
 * @param nombre_clients: Nombre actuel de clients, utilis� pour identifier le client � modifier.
 *
 * Pr�-condition: Le client � modifier doit exister dans le tableau.
 *
 * Sortie: Aucune
 *
 * Post-condition: Les informations du client choisi sont mises � jour.
 *
 * Fait par : Adrian
 */
void modifier_client(CLIENT clients[], int nombre_clients);

/**
 * supprimer_client - Supprime un client du tableau.
 *
 * @param clients: Tableau de CLIENT d'o� le client sera supprim�.
 * @param nombre_clients: Pointeur vers un entier qui contient le nombre actuel de clients.
 *
 * Pr�-condition: Le client � supprimer doit exister dans le tableau.
 *
 * Sortie: Aucune
 *
 * Post-condition: Le client est supprim� du tableau et nombre_clients est d�cr�ment�.
 *
 * Fait par : Kenzo
 */
void supprimer_client(CLIENT clients[], int *nombre_clients);

/**
 * afficher_clients - Affiche tous les clients dans le tableau.
 *
 * @param clients: Tableau de CLIENT � afficher.
 * @param nombre_clients: Nombre actuel de clients � afficher.
 * @param date_referente: Date de r�f�rence pour �ventuellement filtrer les affichages.
 *
 * Pr�-condition: Le tableau clients ne doit pas �tre vide.
 *
 * Sortie: Aucune
 *
 * Post-condition: Les informations des clients sont affich�es.
 *
 * Fait par : Adrian
 */
void afficher_clients(CLIENT clients[], int nombre_clients, const char *date_referente);

/**
 * rechercher_client - Recherche et affiche un client sp�cifique dans le tableau.
 *
 * @param clients: Tableau de CLIENT dans lequel la recherche sera effectu�e.
 * @param nombre_clients: Nombre actuel de clients � rechercher.
 * @param date_referente: Date de r�f�rence pour �ventuellement filtrer les crit�res de recherche.
 *
 * Pr�-condition: Le tableau clients ne doit pas �tre vide.
 *
 * Sortie: Aucune
 *
 * Post-condition: Le client correspondant aux crit�res est affich� si trouv�.
 *
 * Fait par : Kenzo
 */
void rechercher_client(CLIENT clients[], int nombre_clients, const char *date_referente);

/**
 * afficher_clients_manquants - Affiche les clients dont les informations sont incompl�tes.
 *
 * @param clients: Tableau de CLIENT � v�rifier pour les informations manquantes.
 * @param nombre_clients: Nombre actuel de clients � v�rifier.
 * @param date_referente: Date de r�f�rence utilis�e pour �ventuellement filtrer les crit�res.
 *
 * Pr�-condition: Le tableau clients ne doit pas �tre vide.
 *
 * Sortie: Aucune
 *
 * Post-condition: Les clients avec des informations manquantes sont affich�s.
 *
 * Fait par : Adrian
 */
void afficher_clients_manquants(CLIENT clients[], int nombre_clients, const char *date_referente);

/**
 * sauvegarder_clients - Enregistre les informations des clients dans un fichier.
 *
 * @param clients: Tableau de CLIENT contenant les informations � sauvegarder.
 * @param nombre_clients: Nombre actuel de clients � sauvegarder.
 * @param nom_fichier: Nom du fichier dans lequel les informations seront sauvegard�es.
 *
 * Pr�-condition: Le fichier doit �tre accessible en �criture.
 *
 * Sortie: Aucune
 *
 * Post-condition: Les informations des clients sont stock�es dans le fichier sp�cifi�.
 *
 * Fait par : Adrian
 */
void sauvegarder_clients(CLIENT clients[], int nombre_clients, const char *nom_fichier);

/**
 * calculer_age - Calcule l'�ge d'une personne � partir de sa date de naissance 
 * et d'une date de r�f�rence.
 *
 * @param date_naissance: Cha�ne repr�sentant la date de naissance
 * @param date_referente: Cha�ne repr�sentant la date de r�f�rence
 *
 * Pr�-condition: Les cha�nes doivent �tre au format correct.
 *
 * Sortie: Un entier repr�sentant l'�ge en ann�es.
 *
 * Post-condition: Retourne l'�ge calcul� � partir des dates fournies.
 *
 * Fait par : Adrian
 */
int calculer_age(const char *date_naissance, const char *date_referente);

/**
 * saisir_date_referente - Demande � l'utilisateur de saisir la date du jour.
 *
 * @param date_referente: Tableau de caract�res o� la date saisie sera stock�e.
 *
 * Pr�-condition: tableau date_referente doit avoir une taille suffisante pour stocker une date.
 *
 * Sortie: Aucune
 *
 * Post-condition: La variable date_referente contient la date d'aujourd'hui
 *
 * Fait par : Adrian
 */
void saisir_date_referente(char *date_referente);

/**
 *
 * @param clients Tableau de clients � trier.
 * @param nombre_clients Nombre de clients dans le tableau.
 * @param critere Crit�re de tri
 *
 * Fait par : Kenzo
 */
void trier_clients(CLIENT clients[], int nombre_clients, int critere);

/**
 *
 * @param clients Tableau de clients � filtrer.
 * @param nombre_clients Nombre de clients dans le tableau.
 * @param date_referente Date de r�f�rence pour le calcul des �ges des clients.
 *
 * Fait par : Kenzo
 */
void filtrer_clients(CLIENT clients[], int nombre_clients, const char *date_referente);

#endif // FONCTIONS_H_INCLUDED
