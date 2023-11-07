/*


    ~ FILE:                 main.c

    ~ DESCRIZIONE:          Scrivi un programma in linguaggio C che verifichi se una stringa rappresenta un indirizzo IP valido o meno.
                            Un indirizzo IP è considerato valido se soddisfa le seguenti condizioni:

                            x- È composto da 3 numeri interi separati da punti.
                            x- Ogni numero intero deve essere compreso tra 0 e 255.
                            x- Non può iniziare con il numero 0.
                            x- Non può essere uguale a '0.0.0.0'.
                            x- Non può essere uguale all'indirizzo di loopback, cioè '127.0.0.1'.
                            x- Non può essere uguale a un indirizzo privato, ovvero iniziare con '10.', '172.16.' o '192.168.'.
                            x- Non può essere uguale a un indirizzo di rete, ovvero avere l'ultimo numero intero uguale a 0 o 255."
    
    ~ Data Modifica:        07/11/2023

    ~ Versione Rilasciata:  V 2.0

    ~ Powered By:           Simone D'Anna

             _            _        
           / /\         /\ \       
          / /  \       /  \ \____  
         / / /\ \__   / /\ \_____\ 
        / / /\ \___\ / / /\/___  / 
        \ \ \ \/___// / /   / / /  
         \ \ \     / / /   / / /   
     _    \ \ \   / / /   / / /    
    /_/\__/ / / _ \ \ \__/ / / _   
    \ \/___/ //\_\ \ \___\/ //\_\  
     \_____\/ \/_/  \/_____/ \/_/  
                                     

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_DIM_IP 16
#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef struct
{
    int cella[4];    // Struttura per memorizzare l'indirizzo IP suddiviso in 4 numeri interi
    boolean corretto; // Flag per indicare se l'indirizzo IP è valido o meno
} IP_Scomposto;

char indirizzo_ip_originale[MAX_DIM_IP]; // Variabile globale per memorizzare l'indirizzo IP originale

// Funzione per verificare che ogni componente dell'indirizzo IP sia compreso tra 0 e 255
IP_Scomposto check_255(char ip_address[])
{
    char *appo = strtok(ip_address, "."); // Tokenizza la stringa in base ai punti
    IP_Scomposto indirizzo_ip_scomposto;

    indirizzo_ip_scomposto.corretto = TRUE; // Imposta il flag corretto a TRUE

    for (int i = 0; i < 4; i++)
    {
        int appo_cella = atoi(appo); // Converte il token in un numero intero

        if (appo_cella >= 0 && appo_cella <= 255)
        {
            indirizzo_ip_scomposto.cella[i] = appo_cella; // Salva il numero nella struttura
            appo = strtok(NULL, "."); // Passa al prossimo token
        }
        else
        {
            printf("ERRORE NEL PARSING DI [%s] in %s\n", appo, indirizzo_ip_originale);
            indirizzo_ip_scomposto.corretto = FALSE; // Imposta il flag corretto a FALSE se il token non è valido
            break;
        }
    }

    return indirizzo_ip_scomposto;
}

// Funzione per verificare se l'indirizzo IP è conforme alle specifiche
boolean check_ip(IP_Scomposto ip_address)
{
    boolean correttezza;

    if (ip_address.cella[0] == 0 || ip_address.cella[0] == 10)
    {
        correttezza = FALSE;
        printf("\tERRORE: L'indirizzo IP inizia con 0 o è un indirizzo privato (10.x.x.x).\n");
    }
    else if (ip_address.cella[0] == 0 && ip_address.cella[1] == 0 && ip_address.cella[2] == 0 && ip_address.cella[3] == 0)
    {
        correttezza = FALSE;
        printf("\tERRORE: L'indirizzo IP è uguale a '0.0.0.0'.\n");
    }
    else if (ip_address.cella[0] == 127 && ip_address.cella[1] == 0 && ip_address.cella[2] == 0 && ip_address.cella[3] == 1)
    {
        correttezza = FALSE;
        printf("\tERRORE: L'indirizzo IP è uguale all'indirizzo di loopback (127.0.0.1).\n");
    }
    else if ((ip_address.cella[0] == 192 && ip_address.cella[1] == 168) || (ip_address.cella[0] == 172 && ip_address.cella[1] == 16))
    {
        correttezza = FALSE;
        printf("\tERRORE: L'indirizzo IP è un indirizzo privato (192.168.x.x o 172.16.x.x).\n");
    }
    else if (ip_address.cella[3] == 0 || ip_address.cella[3] == 255)
    {
        correttezza = FALSE;
        printf("\tERRORE: L'ultimo numero dell'indirizzo IP è uguale a 0 o 255.\n");
    }
    else
    {
        correttezza = TRUE;
    }

    return correttezza;
}

int main()
{
    char indirizzo_ip_raw[MAX_DIM_IP];
    boolean check_input = FALSE;
    IP_Scomposto indirizzo_ip_scomposto;

    while (check_input != TRUE)
    {
        printf("Inserisci un indirizzo IP\ndel tipo xxx.xxx.xxx.xxx: ");
        gets(indirizzo_ip_raw);
        strcpy(indirizzo_ip_originale, indirizzo_ip_raw); // Copia l'indirizzo IP originale

        indirizzo_ip_scomposto = check_255(indirizzo_ip_raw);

        if (indirizzo_ip_scomposto.corretto == TRUE)
        {
            if (check_ip(indirizzo_ip_scomposto) == TRUE)
            {
                printf("\tIP: %s [CONFORME!]\n", indirizzo_ip_originale);
                check_input = TRUE;
            }
            else
            {
                printf("\tIP: %s [NON CONFORME!]\n", indirizzo_ip_originale);
                check_input = FALSE;
            }
        }
        else
        {
            printf("\tIP: %s [NON VALIDATO!]\n", indirizzo_ip_originale);
            check_input = FALSE;
        }
    }

    return 0;
}
