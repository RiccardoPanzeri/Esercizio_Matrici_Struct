#include "struct.h"
//Funzione che carica tramite input dell'utente l'array di struct, controllando anche l'input per lo stipendio.
void caricaStruct(dipendente azienda[], int dim);
//Funzione che stampa a console le info di ogni dipendente;
void visualizzaInfo(dipendente azienda[], int dim);
//Funzione che carica la matrice di char con i dati contenuti nella struct;
void caricaMatrice(char matrice[] [26], int righe, int colonne, dipendente azienda[], int dim);
//Funzione che visualizza le stringhe contenute nella matrice;
void visualizzaMatrice(char matrice[] [26], int righe, int colonne);
