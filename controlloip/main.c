/*

    Esercizio:  Scrivi un programma in linguaggio C che chiede all'utente di inserire una serie di numeri interi.
                Gli utenti devono specificare quanti numeri vogliono inserire e quindi inserire ciascun numero uno alla volta.
                Il programma dovrebbe quindi calcolare la media di questi numeri e stamparla a schermo.
                Assicurati che il programma gestisca correttamente gli array per archiviare i numeri inseriti e calcolare la media.

*/

#include <stdio.h>
#include <stdlib.h>

// DICHIARAZIONE DELL FUNZIONI //

void inserimento_Array(int arrayRicev[], int dimensione)
{

    for (int i = 0; i < dimensione; i++)
    {
        printf("\nInserire il %d ^ numero: ", i + 1);
        scanf("%d", &arrayRicev[i]);
    }
}

float media(int array[], int dimensione)
{
    float appo = 0;

    for (int i = 0; i < dimensione; i++)
    {
        appo += array[i];
    }

    return appo / dimensione ;
}


// INIZIO DEL MAIN //

int main()
{

    int dim;

    printf("\nQuanti numeri vuoi inserire? : ");
    scanf("%d", &dim);

    int numeri[dim];

    inserimento_Array(numeri,dim);

    printf("\n La media dei numeri inseriti e': %f ", media(numeri,dim));

    return 0;

}