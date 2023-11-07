#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UTENTE "vincenzinotufino"
#define PASSWORD "tufino23"

void accesso(char USER[], char PASS[])
{

    if (strcmp(UTENTE, USER) == 0 && strcmp(PASSWORD, PASS) == 0)
    {
        printf("password e nome utente sono giusti, puoi accedere -->\n");
    }
    else
    {
        printf("le credenziali non sono corrette\n");
    }
}

int main()
{
    char nomeUtente[20], pass[20];
    
    printf("inserisci il nome utente: ");
    gets(nomeUtente);
    
    printf("inserisci la password: ");
    gets(pass);

    accesso(nomeUtente, pass);

    return 0;
}