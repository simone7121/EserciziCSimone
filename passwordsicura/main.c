#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char password[MAX], speciali[] = {'!', '@', '#', '$', '%', '&', '*'}, c;
    int lung, check = 0;

    printf("inserisci una password che abbia \n\t- Una lunghezza compresa tra 10 e 15 \n\t- Contenga almeno una lettera MAIUSCOLA, una minuscola, un carattere speciale e un numero: ");
    gets(password);

    lung = strlen(password);

    if (lung >= 10 && lung <= 15)
    {
        for (int i = 0; i < lung; i++)
        {
            if (password[i] >= 'a' && password[i] <= 'z')
            {
                check = 1;
                break;
            }
        }

        if (check == 1)
        {
            for (int i = 0; i < lung; i++)
            {
                if (password[i] >= 'A' && password[i] <= 'Z')
                {
                    check = 2;
                    break;
                }
            }
        }

        if (check == 2)
        {
            for (int i = 0; i < lung; i++)
            {
                if (password[i] >= '0' && password[i] <= '9')
                {
                    check = 3;
                    break;
                }
            }
        }

        if (check == 3)
        {
            for (int i = 0; i < strlen(speciali); i++)
            {
                if (strchr(password, speciali[i]) != NULL)
                {
                    check = 4;
                    break;
                }
            }
        }

        if (check == 4)
        {
            printf("la password e' inserita bene\n");
        }

    }
    else
    {

        printf("La password non rispetta i criteri definiti");

    }

    return 0;
    
}