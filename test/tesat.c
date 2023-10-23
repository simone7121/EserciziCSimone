#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_ip(char *ip);

int main()
{
    char ip[16];
    printf("Inserisci un indirizzo IP: ");
    fgets(ip, 16, stdin);
    if (is_valid_ip(ip))
    {
        printf("Indirizzo IP valido.\n");
    }
    else
    {
        printf("Indirizzo IP non valido.\n");
    }
    return 0;
}

int is_valid_ip(char *ip)
{
    char *tok;
    int count = 0;
    int num;
    char delimiters[] = ".";
    char copy[16];
    strcpy(copy, ip);
    // Verifica se l'indirizzo IP non è "0.0.0.0"
    if (strcmp(copy, "0.0.0.0\n") == 0)
    {
        return 0;
    }
    // Verifica se l'indirizzo IP non è loopback "127.0.0.1"
    if (strcmp(copy, "127.0.0.1\n") == 0)
    {
        return 0;
    }
    // Verifica se l'indirizzo IP non è privato
    if (strstr(copy, "10.") == copy || strstr(copy, "172.16.") == copy || strstr(copy, "192.168.") == copy)
    {
        return 0;
    }
    tok = strtok(copy, delimiters);
    while (tok != NULL && count < 4)
    {
        int i;
        for (i = 0; i < strlen(tok); i++)
        {
            if (tok[i] < '0' || tok[i] > '9')
            {
                return 0;
            }
        }
        num = atoi(tok);
        if (num < 0 || num > 255)
        {
            return 0;
        }
        if (count == 0 && num == 0)
        {
            return 0;
        }
        if (count == 3 && (num == 0 || num == 255))
        {
            return 0;
        }
        count++;
        tok = strtok(NULL, delimiters);
    }
    if (count != 4)
    {
        return 0;
    }
    return 1;
}s