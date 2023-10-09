#include <stdio.h>
// Inclusione della libreria di standard Input/Output
#include <conio.h>
// For getch()

int main()
{

    int x;
    // Dichiarazione delle variabili utili al programma.

    printf("~[ Programma che seleziona i numeri >0 senno errore ]~ \n\n\n");
    // Stampa Del messaggio di benvenuto.

    do
    {
        printf("~[ Inserire numero > 0 ]~ \n\n");
        // Stampa Del messaggio di inserimento.

        scanf("%d", &x);
        // Aspetto dall'utente un valore di float inserito nella finestra di comando del CMD,
        // e alla pressione del tasto invio associo il valore inserito alla locazione di memoria della variabile base.

        if (x > 0)
        {
            printf("~[ Il numero %d e' > 0 , proseguo con il programma ]~ \n\n", x);
            // Stampa Del messaggio di inserimento corretto del numero.
        }
        else
        {
            printf("~[ Il numero %d NON e' > 0 , ripeti l'inserimento ]~ \n\n", x);
            // Stampa Del messaggio di inserimento NON corretto del numero.
        }

    } while (x <= 0);

    printf("\n\nPer terminare l'esecuzione premere qualsiasi tasto... \n");
    getchar();
    // Aspetta un keypress per l'uscita

    return 0;
    // Ritorno del programma 0 -> Esecuzione completata con successo !
}