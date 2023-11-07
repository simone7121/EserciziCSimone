#include <stdio.h>
// Inclusione della libreria di standard Input/Output
#include <conio.h> 
// For getch()
#include <string.h>

typedef struct 
{
    char titolo[30];
    int anno_publicazione;
    char editore[20];
    float costo;
    
} Libro;

void find_libro_costoso (Libro *libreria_ing);
void stampa_dettagli_libro(Libro libro_da_stamp);
void stampa_libreria_(Libro *libreria_ing);

int main() {

    Libro libreria [10];

    for (int i = 0; i < 10; i++)
    {
        printf("\nInserire Titolo libro %i:", i+1);
        gets(libreria[i].titolo);

        printf("\nInserire Anno Publicazione libro %i:", i+1);
        scanf("%d", &libreria[i].anno_publicazione);

        printf("\nInserire Editore libro %i:", i+1);
        gets(libreria[i].editore);

        printf("\nInserire Costo libro %i:", i+1);
        scanf("%d", &libreria[i].anno_publicazione);
    }

    find_libro_costoso(&libreria);
    

    printf("~[ Programma che gestisce una libreria ]~ \n\n\n");
    // Stampa Del messaggio di benvenuto.
    
    

    return 0;
    // Ritorno del programma 0 -> Esecuzione completata con successo !

}

// Funzione che individua il libro con il prezzo più alto e ne stampa tutti i valori della struct

void find_libro_costoso (Libro *libreria_ing){
    
    int index_max_libro = 0;

    for (int i = 1; i < 3; i++)
    {
        if (libreria_ing[i].costo > libreria_ing[index_max_libro].costo )
        {
            index_max_libro = i;
        }
        
    }

    stampa_dettagli_libro(libreria_ing[index_max_libro]);
    
}

// Funzione che stampa il libro con il prezzo più alto e ne stampa tutti i valori della struct

void stampa_dettagli_libro(Libro libro_da_stamp){

    printf("\tTitolo libro %s:",libro_da_stamp.titolo);
    printf("\tAnno Publicazione libro %i:", libro_da_stamp.anno_publicazione);
    printf("\tEditore libro %i:", libro_da_stamp.editore);
    printf("\tCosto libro %i:", libro_da_stamp.anno_publicazione);

}

void stampa_libreria_(Libro *libreria_ing){
    for (int i = 0; i < 3; i++)
    {
        printf("\n (%i) Libro della Libreria:", i+1 );
        stampa_dettagli_libro(libreria_ing[i]);
    }
}