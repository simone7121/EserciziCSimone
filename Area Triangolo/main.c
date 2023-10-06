#include <stdio.h>
// Inclusione della libreria di standard Input/Output

#include <conio.h> 
// For getch()


int main() {

    float base, altezza, area;
    // Dichiarazione delle variabili utili al programma.

    printf("~[ Programma che calcola l'area del triangolo ]~ \n\n\n");
    // Stampa Del messaggio di benvenuto.

    printf("Immettere [la base] (float): ");                            
    // Stampa messaggio di inserimento della base.
    scanf("%f", &base);                                                 
    // Aspetto dall'utente un valore di float inserito nella finestra di comando del CMD, 
    // e alla pressione del tasto invio associo il valore inserito alla locazione di memoria della variabile base.

    printf("\nImmettere [l'altezza] (float): ");                        
    // Stampa messaggio di inserimento dell'altezza
    scanf("%f", &altezza);                                              
    // Aspetto dall'utente un valore di float inserito nella finestra di comando del CMD, 
    // e alla pressione del tasto invio associo il valore inserito alla locazione di memoria della variabile altezza.

    area = (base * altezza)/2;
    // Calcolo matematico  dell'area e successiva assegnazione alla variabile

    printf("\n\n[Area] del triangolo di \n[base] = (%f) \n[altezza] = (%f) equivale a  {%f.2} ", base, altezza, area );
    // Stampa Del messaggio finale.

    printf("\n\nPer terminare l'esecuzione premere qualsiasi tasto... \n");  
    getch(); 
    // Aspetta un keypress per l'uscita

    return 0;
    // Ritorno del programma 0 -> Esecuzione completata con successo !

}