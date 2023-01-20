#include <stdio.h>
#include <cctype>
#include <cstring>
#include <stdlib.h>
#include "prototipi.h"
using namespace std;

void caricaStruct(dipendente azienda[], int dim) {
    char nome[25] = "";
    char cognome[25] = "";
    char stipendioS[25] = "";//Variabile che conterrà lo stipendio sotto forma di stringa;
    bool numerico = true;//variabile booleana che stabilisce se la variabile stipendio è composta solo da caratteri numerici;
    int  n;//contatore per il controllo della variabile stipendio;
    for (int i = 0; i < dim; i++) {
        n = 0;//azzero il contatore
        printf("Inserisci il nome del %d° impiegato: \n", i + 1);
        scanf("%s", nome);//richiedo l'input dell'utente;
        strcpy(azienda[i].nome, nome);//Copio la stringa contente il nome inserito dall'utente;
        printf("Inserisci il cognome del %d° impiegato: \n", i + 1);
        scanf("%s", cognome);
        strcpy(azienda[i].cognome, cognome);//stessa cosa per il cognome;
        do {//controllo che l'utente non abbia inserito lettere nel campo ''stipendio'';
            n = 0;//azzero il contatore;
            numerico = true;//riposiziono il valore booleano su ''true'' per permettere al ciclo di controllo di ripartire per ogni dipendente;
            printf("Inserisci lo stipendio mensile del %d° impiegato: \n", i + 1);
            scanf(" %s", stipendioS);//richiedo l'input dell'utente;
            strcpy(azienda[i].stipendioS, stipendioS);
            //analizzo la stringa
            while (azienda[i].stipendioS[n] != '\0' && numerico == true) {//finche la stringa non termina e nessun carattere non numerico viene trovato, il ciclo continua;
                if(isdigit(azienda[i].stipendioS[n]) == 0){//se lo stipendio contiene caratteri non numerici, la variabile booleana viene settata su false;
                    numerico = false;//il ciclo in questo caso termina, perchè sono presenti dei caratteri non numerici;

                }
                n++;//passo al carattere successivo;
            }
            if (numerico == true) {//se terminato il ciclo while il valore booleano risulta vero, converto la stringa in numero e la assegno alla variabile della struct;
                azienda[i].stipendio = atoi(azienda[i].stipendioS);
            } else {
                printf("Input errato!\n");//altrimenti, mostro un messaggio di errore;
                strcpy(stipendioS, "");//e svuoto la stringa stipendio iniziale;

            }
        } while (!numerico);//se alla fine del controllo risultano presenti valori non numerici, si riparte dall'inserimento dell'input dell'utente
    }
}

void visualizzaInfo(dipendente azienda[], int dim){
    for(int i = 0; i < dim; i++){
        printf("\nNome: %s\n", azienda[i].nome);
        printf("Cognome: %s\n", azienda[i].cognome);
        printf("Stipendio mensile: %s\n\n\n", azienda[i].stipendioS);
    }
}

void caricaMatrice(char matrice[] [26], int righe, int colonne, dipendente azienda[], int dim){
    strcpy(matrice[0], azienda[0].nome);
    strcpy(matrice[1], azienda[0].cognome);
    strcpy(matrice[2], azienda[0].stipendioS);

}

void visualizzaMatrice(char matrice[] [26], int righe, int colonne){
    for(int i = 0; i <= righe; i++){
        printf("%s\n", matrice[i]);
    }
}
