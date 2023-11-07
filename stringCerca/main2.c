#include <stdio.h>
#include <string.h>

#define MAX 100

// La funzione 'controll_are' prende una stringa 'testo' come input e conta le parole che terminano con "are".
int controll_are(char testo[MAX])
{
    printf("Inserisci la frase di partenza : "); // Stampa un messaggio per l'utente che richiede di inserire una frase di partenza.
    gets(testo);                                 // Legge la frase di input dall'utente e la memorizza nella variabile 'testo'.

    char *parola = strtok(testo, " "); // Estrae la prima parola dalla stringa utilizzando spazi come delimitatori e memorizza un puntatore ad essa.
    int conteggio = 0;                 // Variabile per tenere traccia del conteggio delle parole che terminano con "are".

    while (parola != NULL) // Continua finché ci sono parole nella stringa.
    {
        int lunghezza = strlen(parola); // Calcola la lunghezza della parola corrente.

        printf("\nSTART ->\t %d | %p | [%s] \n", parola, parola, parola); // Stampa informazioni sulla parola corrente (indirizzo, puntatore, contenuto).

        printf("INCR. MEM ->\t %d | %p | [%s] \n", parola + lunghezza, parola + lunghezza, parola + lunghezza); // Stampa informazioni sulla memoria successiva alla parola (indirizzo, puntatore, contenuto).

        printf("ULTIMI 3 ->\t %d | %p | [%s] \n", parola + lunghezza - 3, parola + lunghezza - 3, parola + lunghezza - 3); // Stampa le ultime 3 lettere della parola (indirizzo, puntatore, contenuto).

        if (lunghezza >= 3 && strcmp(parola + lunghezza - 3, "are") == 0) // Verifica se la parola corrente ha almeno 3 caratteri e termina con "are".
        {
            conteggio++; // Se la parola soddisfa le condizioni, incrementa il conteggio.

            printf("\t\t{MATCH IS FOUND ! +1}\n\n"); // Stampa un messaggio di corrispondenza trovata.
        }

        parola = strtok(NULL, " "); // Estrae la prossima parola dalla stringa utilizzando spazi come delimitatori.
    }

    return conteggio; // Restituisce il conteggio delle parole che terminano con "are".
}

int main()
{
    char text[MAX]; // Dichiarazione di una variabile 'text' per memorizzare la frase di input.

    printf("Totale parole in ARE: %d\n", controll_are(text)); // Stampa un messaggio per indicare che stiamo controllando le parole che terminano con "are, chiama la funzione 'controll_are' per il conteggio e stampa il risultato.

    return 0;
}
