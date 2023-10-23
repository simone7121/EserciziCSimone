#include <stdio.h>
#include <string.h>
#define TRUE 1 // gestione variabile boleana con #define
#define FALSE 0
void conta_tutto(char *testo, int *conta_c, int *conta_p, int *conta_l) // procedura che conteggia il numero di caratteri, linee e parole in un testo
{
    int i = 0, in_parola;
    // inizializzazione dei contatori

    *conta_c = 0;
    *conta_p = 0;
    *conta_l = 0;
    in_parola = FALSE;       // settaggio flag in_parola
    while (testo[i] != '\0') // while (*(testo+i)!= '\0')
    {
        (*conta_c)++;
        if (testo[i] == '\n') // if(*(testo+i)== '\n')
            (*conta_l)++;
            
        if (testo[i] == ' ' || testo[i] == '\n' || testo[i] == '\t') // if (*(testo+i) == ' ' || *(testo+i)== '\n' || *(testo+i)== '\t')
            in_parola = FALSE;
        else if (in_parola == FALSE)
        {
            in_parola = TRUE;
            (*conta_p)++;
        }
        i++;
    }
    (*conta_l)++;
}

int string_matching(char chiave[], char testo[]) // calcola il numero di occorrenze della stringa chiave nella stringa testo
{
    int n, m, i, conta_chiave; // contatori funzione
    n = strlen(chiave);        // uso la funzione della libreria string.h per calcolare la lunghezza della stringa chiave
    m = strlen(testo);         // m dimensione della stringa testo
    conta_chiave = 0;
    for (i = 0; i < m - n; i++)
        if (strncmp(chiave, &testo[i], n) == 0)
            conta_chiave++;
    return conta_chiave;
}

int punteggio_matching(char *a, char *b, int n) // funzione che restituisce il numero di caratteri uguali
{
    int i, n_caratteri_uguali; // contatori funzione
    n_caratteri_uguali = 0;
    for (i = 0; i < n; i++)
        if (a[i] == b[i])
            n_caratteri_uguali++;
    return n_caratteri_uguali;
}

int best_matching(char *chiave, char *testo) // funzione che restituisce il best matching
{
    int i, n, m, punteggio_max, punteggio, indice; // contatori funzione
    n = strlen(chiave);                            // uso la funzione della libreria string.h per calcolare la lunghezza della stringa chiave
    m = strlen(testo);                             // m dimensione della stringa testo
    indice = 0;
    punteggio_max = 0;

    for (i = 0; i < m - n; i++)
    {
        punteggio = punteggio_matching(chiave, &testo[i], n);
        if (punteggio > punteggio_max)
        {
            punteggio_max = punteggio;
            indice = i;
        } 
    }

    return indice;
}