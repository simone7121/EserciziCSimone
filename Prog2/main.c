#include "mioheader.h"
// Inclusione della libreria di HEADER


int main() {

    float raggio, circon;
    // Dichiarazione delle variabili utili al programma.

    printf("~[ Programma che Calcola La Circonferenza ]~ \n\n\n");
    // Stampa Del messaggio di benvenuto.

    printf("Immettere [Il Raggio] (float): ");                            
    // Stampa messaggio di inserimento della base.
    scanf("%f", &raggio);                                                 
    // Aspetto dall'utente un valore di float inserito nella finestra di comando del CMD, 
    // e alla pressione del tasto invio associo il valore inserito alla locazione di memoria della variabile base.

    circonferenza(raggio, &circon);

    printf("La circonferenza e : %.2f ", circon);

    printf("\n\nPer terminare l'esecuzione premere qualsiasi tasto... \n");  
    getch(); 
    // Aspetta un keypress per l'uscita


    return 0;
    // Ritorno del programma 0 -> Esecuzione completata con successo !

}

float circonferenzar(float raggio){
    return (2*raggio)*3.14;
}

void circonferenza (float raggio, float *pointerCirconf){
    *pointerCirconf = (2*raggio)*3.14;
}