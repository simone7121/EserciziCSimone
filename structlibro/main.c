#include <stdio.h>
#include <string.h>

typedef struct
{
    char titolo[30];
    int anno_publicazione;
    char editore[20];
    float costo;

} Libro;

void find_libro_costoso(Libro *libreria_ing);
void stampa_dettagli_libro(Libro libro_da_stamp);
void stampa_libreria(Libro *libreria_ing);

int main()
{
    Libro libreria[3];

    for (int i = 0; i < 3; i++)
    {
        printf("\nInserire Titolo libro %i:", i + 1);
        fgets(libreria[i].titolo, sizeof(libreria[i].titolo), stdin);

        printf("\nInserire Anno Publicazione libro %i:", i + 1);
        scanf("%d", &libreria[i].anno_publicazione);
        // Clear the input buffer
        while (getchar() != '\n');

        printf("\nInserire Editore libro %i:", i + 1);
        fgets(libreria[i].editore, sizeof(libreria[i].editore), stdin);

        printf("\nInserire Costo libro %i:", i + 1);
        scanf("%f", &libreria[i].costo);
        // Clear the input buffer
        while (getchar() != '\n');
    }

    find_libro_costoso(libreria);
    stampa_libreria(libreria);

    printf("~[ Programma che gestisce una libreria ]~ \n\n\n");
    return 0;
}

void find_libro_costoso(Libro *libreria_ing)
{
    int index_max_libro = 0;

    for (int i = 1; i < 3; i++)
    {
        if (libreria_ing[i].costo > libreria_ing[index_max_libro].costo)
        {
            index_max_libro = i;
        }
    }

    stampa_dettagli_libro(libreria_ing[index_max_libro]);
}

void stampa_dettagli_libro(Libro libro_da_stamp)
{
    printf("\tTitolo libro: %s\n", libro_da_stamp.titolo);
    printf("\tAnno Publicazione libro: %i\n", libro_da_stamp.anno_publicazione);
    printf("\tEditore libro: %s\n", libro_da_stamp.editore);
    printf("\tCosto libro: %.2f\n", libro_da_stamp.costo);
}

void stampa_libreria(Libro *libreria_ing)
{
    for (int i = 0; i < 3; i++)
    {
        printf("\n (%i) Libro della Libreria:\n", i + 1);
        stampa_dettagli_libro(libreria_ing[i]);
    }
}
