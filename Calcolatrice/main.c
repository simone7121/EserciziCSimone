#include <stdio.h>
// Inclusione della libreria di standard Input/Output
#include <conio.h>
// For getch()

int main()
{

    char selezione;

    int error = 0, counter = 0;
    const int dimensioneStorico = 10;

    float ultimoRisultato = 0, storicoRisultati[dimensioneStorico];
    // Dichiarazione delle variabili utili al programma.

    printf("~[ Calcolatrice digitale ]~ \n\n\n");
    // Stampa Del messaggio di benvenuto.

    if (selezione != NULL)
    {
        printf("Ultimo Risultato: %.4f", ultimoRisultato);
    }
    // Se la selezione non è nulla, ritorna l'ultimo risulatato

    do
    {
        error = 0;

        printf("Seleziona un operazione:\n  1) Somma (+)\n  2) Sottrazione (-)\n  3) Divisione (/)\n  4) Moltiplicazione (*)\n");
        scanf("%c", &selezione);

        switch (selezione)
        {
        case 1:
        case '+':
            ultimoRisultato = somma();
            break;
        case 2:
        case '-':
            ultimoRisultato = sottrazione();
            break;
        case 3:
        case '/':
            ultimoRisultato = divisione();
            break;
        case 4:
        case '*':
            ultimoRisultato = moltiplicazione();
            break;

        default:
            error = 1;
            break;
        }

        assegnaUltimoRisultato(ultimoRisultato, &storicoRisultati, &counter, dimensioneStorico);

    } while (error == 0);

    printf("\n\nPer terminare l'esecuzione premere qualsiasi tasto... \n");
    getchar();
    // Aspetta un keypress per l'uscita

    return 0;
    // Ritorno del programma 0 -> Esecuzione completata con successo !
}

int ultimoRisultato(float ultimoRisultatoR, float storicoRisultati[], int counter, int dim_array)
{

    storicoRisultati[counter] = ultimoRisultatoR;

    if (counter < dim_array - 1)
    {
        counter++;
    }
    else
    {
        counter = 0;
    }
}
}