#include <stdio.h>
// Inclusione della libreria di standard Input/Output
#include <conio.h> 
// For getch()


int main() {

    char nome_corso_laurea [12] = "Informatica" ;
    // Dichiarazione di un array di char (Una Stringa) con dimensione definita

    char nome_corso_laurea_UNDEF [] = "Informatica" ;
    // Dichiarazione di un array di char (Una Stringa) con dimensione NON definita

    printf("~[ Programma che tratta le stringhe ]~ \n\n\n");
    // Stampa Del messaggio di benvenuto.

   
    int i=0 ;

    while (getchar()!=EOF)
    {
        i++;
    }

    printf("OILLOC -> %d",i);
    


    printf("\n\nPer terminare l'esecuzione premere qualsiasi tasto... \n");  
    getchar(); 
    // Aspetta un keypress per l'uscita

    return 0;
    // Ritorno del programma 0 -> Esecuzione completata con successo !

}