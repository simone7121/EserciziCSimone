#include <stdio.h>
#include <string.h>

#define MAX 100

int are(char testo[MAX])
{
    gets(testo); // Legge una riga di testo dalla console e la memorizza nella variabile 'testo'.

    int conteggio = 0; // Variabile per tenere traccia del conteggio delle parole che terminano con "are".
    int j = 0; // Variabile per tenere traccia della lunghezza della parola corrente.
    int lung = strlen(testo); // Calcola la lunghezza della stringa 'testo' (la riga di testo inserita).

    for (int i = 0; i <= lung; i++) // Iteriamo attraverso la stringa di input, incluso il carattere nullo '\0' alla fine.
    {
        if (testo[i] == ' ' || testo[i] == '\0') // Controlliamo se il carattere corrente è uno spazio o la fine della stringa.
        {
            char appo[MAX]; // Variabile temporanea per memorizzare la parola corrente.
            for (int k = 0; k < j; k++) // Copia la parola corrente in 'appo'.
            {
                appo[k] = testo[i - j + k];
            }
            appo[j] = '\0'; // Aggiunge un terminatore di stringa alla fine di 'appo' per creare una stringa valida.

            if (j >= 3 && strcmp(appo + j - 3, "are") == 0) // Verifica se la parola corrente ha almeno 3 caratteri e termina con "are".
            {
                conteggio++; // Se la parola soddisfa le condizioni, incrementa il conteggio.
            }
            j = 0; // Resetta 'j' per iniziare a conteggiare la prossima parola.
        }
        else
        {
            j++; // Incrementa 'j' per tenere traccia della lunghezza della parola corrente.
        }
    }

    return conteggio; // Restituisce il conteggio delle parole che terminano con "are".
}

int main()
{
    char text[MAX]; // Dichiarazione di una variabile 'text' per memorizzare la riga di testo.
    int co = 0; // Variabile per memorizzare il conteggio di parole che terminano con "are".
    co = are(text); // Chiama la funzione 'are' per elaborare la riga di testo e memorizzare il conteggio in 'co'.
    printf("%d\n", co); // Stampa il conteggio delle parole che terminano con "are".
    return 0;
}
