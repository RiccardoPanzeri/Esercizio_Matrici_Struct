#include <stdio.h>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include "prototipi.h"
using namespace std;
int main() {
    //parte 1: creo l'array di struct, lo carico e visualizzo i dati di ogni componente dell'array di struct;
    const int dim = 2;//dimensione dell'arrqay di struct;
    dipendente azienda[dim];
    caricaStruct(azienda, dim);
    visualizzaInfo(azienda, dim);

    //parte 2: creo una matrice, la riempio con i dati contenuti nella prima variabile dell'array di struct e visualizzo le stringhe;
    const int righe = 3;
    const int colonne = 26;
    char matrice1[righe] [colonne];
    caricaMatrice(matrice1, righe, colonne, azienda, dim);
    visualizzaMatrice(matrice1, righe, colonne);

    //parte 3: creo la stringa csv e la visualizzo:
  int const dimCSV = 81;//la dimensione deve essere una costante, quindi ho calcolato a mano la lunghezza sufficiente per contenere tutti i dati (25 x 3 , più 6 spazi extra per le virgole, spazi e il fine stringa)
  char csv[dimCSV] = "";
  strcat(csv, azienda[0].nome);
    strcat(csv, ", ");
    strcat(csv, azienda[0].cognome);
    strcat(csv, ", ");
    strcat(csv, azienda[0].stipendioS);
    printf("%s\n\n", csv);

    //parte 4: spacchetto la stringa e la inserisco in un'altra matrice:
    char matrice2[righe] [colonne];
    int cont = 0;//contatore per i caratteri della stringa csv;
    int j = 0;//contatore colonne;
    for(int i = 0; i < righe; i++) {
        while(csv[cont] != ',' && csv[cont] != '\0' && csv[cont] != ' ') {//finchè i caratteri di csv sono diversi dalle virgole o dagli spazi, e la stringa non è finita, copio il carattere nella colonna della riga i;
            matrice2[i][j] = csv[cont];
            cont++;//incremento entrambi i contatori;
            j++;
        }
        while(csv[cont] == ' ' || csv[cont] == ','){//se il carattere è una virgola o uno spazio, incremento il contatore;
            cont++;
        }

        matrice2[i] [j] = '\0';//inserisco il fine stringa;

        j = 0;//azzero il contatore della colonna;
        printf("%s\n", matrice2[i]);//stampo la stringa della matrice;
    }















    return 0;
}
