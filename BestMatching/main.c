#include <stdio.h>
#include <string.h>
#define TRUE 1 // gestione variabile boleana con #define
#define FALSE 0
void conta_tutto(char *testo, int *numero_caratteri, int *numero_parole, int *numero_righe);
// Programma che conteggia il numero di
// caratteri, numero di parole e numero di linee
// in un testo

int main()
{
    char testo[100];                                   // allocazione array caratteri per stringa input
    int numero_caratteri, numero_parole, numero_linee; // contatori restituiti dalla procedura void
    printf("Programma che conteggia il numero di caratteri, parole, linee di un testo\n");
    printf("Inserire il testo\n");
    gets(testo); // riceve la stringa di testo in input
    conta_tutto(testo, &numero_caratteri, &numero_parole, &numero_linee);
    printf("risultato procedura conta_tutto:\n numero di caratteri= %d\nnumero di parole= %d\nnumero di linee= %d\n", numero_caratteri, numero_parole, numero_linee);
    return 0;
}