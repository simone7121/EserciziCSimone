#include <stdio.h>
#include <string.h>

// Definizione delle costanti TRUE e FALSE
#define TRUE 1
#define FALSE 0

// Dichiarazione della funzione conta_tutto
void conta_tutto(char *, int *, int *, int *);

int main() {

    // Dichiarazione e inizializzazione di variabili
    char testo[100]; // Array che conterrà la stringa di testo
    char *token = NULL;
    char separatori[] = {' ', '\n', '\t' , '\0'}; // Array di caratteri che rappresentano i separatori

    // Dichiarazione e inizializzazione dei contatori
    printf("Inserisci il testo\n");
    int numero_caratteri, numero_parole, numero_linee;
    gets(testo);

    // Chiamata alla funzione conta_tutto per contare caratteri, parole e linee nel testo
    conta_tutto(testo, &numero_caratteri, &numero_parole, &numero_linee);
    printf("Conta_tutto: \n Numero di caratteri = %d\n Numero di parole = %d\n Numero di linee = %d\n", numero_caratteri, numero_parole, numero_linee);
    
    // Utilizzo di strtok per estrarre le parole dal testo
    printf("Elenco delle parole o token del testo estratti con strtok():\n");
    
    int j = 1; // Contatore per le parole

    // Estrazione e stampa della prima parola
    printf("1 parola = %s\n", strtok(testo, separatori));

    // Estrazione e stampa delle parole rimanenti con strtok
    while ((token = strtok('\0', separatori)) != '\0') {
        j++;
        printf("%d parola = %s\n", j, token);
    }

    return 0;
}

// Definizione della funzione conta_tutto
void conta_tutto(char *testo, int *conta_c, int *conta_p, int *conta_l) {
    
    int i, in_parola;

    // Inizializzazione dei contatori
    i = 0;
    *conta_c = 0; // Caratteri
    *conta_p = 0; // Parole
    *conta_l = 0; // Linee
    in_parola = FALSE; // Inizializzazione del flag in_parola = FALSE

    // Iterazione attraverso il testo
    while (testo[i] != '\0') {

        (*conta_c)++; // Incremento del contatore dei caratteri
        
        if (testo[i] == '\n') // Se il carattere corrente è una nuova riga
            (*conta_l)++; // Incremento del contatore delle linee
        
        if (testo[i] == ' ' || testo[i] == '\n' || testo[i] == '\t')
            in_parola = FALSE; // Il carattere corrente è un separatore, quindi non si è più in una parola
        else if (in_parola == FALSE) {
            in_parola = TRUE; // Inizio di una nuova parola
            (*conta_p)++; // Incremento del contatore delle parole
        }

        i++; // Avanzamento all'elemento successivo nel testo
    }

    (*conta_l)++; // Incremento finale del contatore delle linee

}
