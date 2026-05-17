#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define MAX_CLIENTS 100
#define MAX_LENGTH 100
#define annuaire "annuaire_100_entrees.csv"

typedef struct {
    char prenom[MAX_LENGTH];
    char nom[MAX_LENGTH];
    char ville_cp[MAX_LENGTH];
    char telephone[MAX_LENGTH];
    char adresse_mel[MAX_LENGTH];
    char profession[MAX_LENGTH];
    char date_naissance[MAX_LENGTH];
} CLIENT;

void charger_clients(CLIENT clients[], int *nombre_clients);
void ajouter_client(CLIENT clients[], int *nombre_clients);
void modifier_client(CLIENT clients[], int nombre_clients);
void supprimer_client(CLIENT clients[], int *nombre_clients);
void afficher_clients(CLIENT clients[], int nombre_clients, const char *date_referente);
void rechercher_client(CLIENT clients[], int nombre_clients, const char *date_referente);
void afficher_clients_manquants(CLIENT clients[], int nombre_clients, const char *date_referente);
void sauvegarder_clients(CLIENT clients[], int nombre_clients, const char *nom_fichier);
int calculer_age(const char *date_naissance, const char *date_referente);
void saisir_date_referente(char *date_referente);
void trier_clients(CLIENT clients[], int nombre_clients, int critere);
void filtrer_clients(CLIENT clients[], int nombre_clients, const char *date_referente);

#endif
