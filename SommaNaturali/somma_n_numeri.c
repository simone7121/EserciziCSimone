#include "header.h"
//Include dell'header


int somma_naturali(int inizio, int fine)
{
    int i, sommatoria = 0;

    for (i = inizio; i < fine; i++)
    {
        sommatoria += i;
    }

    return sommatoria;

}