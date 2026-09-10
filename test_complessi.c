#include <stdio.h>
#include "complessi.h"

int main(void){
    Complesso a = {3.0, 2.0};
    Complesso b = {1.0, -5.0};
    Complesso atteso = {4.0, -3.0};
    Complesso ottenuto;
    
    //Test somma
    ottenuto = somma_complessi(a,b);

    if (complessi_vicini(ottenuto, atteso, 1e-6))
    {
        printf("OK: somma\n");
    }
    else
    {
        printf("ERRORE: somma\n");
        return 1;
    }

    //Test prodotto
    atteso.reale = 13.0;
    atteso.immaginaria = -13.0;

    ottenuto = prodotto_complessi(a,b);

    if (complessi_vicini(ottenuto, atteso, 1e-6))
    {
        printf("OK: prodotto\n");
    }
    else{
        printf("ERRORE: prodotto\n");
        return 1;
    }

    //Test divisione
    atteso.reale = -7.0 / 26.0;
    atteso.immaginaria = 17.0 / 26.0;

    int esito = divisione_complessi(a, b, &ottenuto);

    if (esito == 1 && complessi_vicini(ottenuto, atteso, 1e-6))
    {
        printf("OK: divisione\n");
    }
    else {
        printf("ERRORE: divisione\n");
        return 1;
    }

    Complesso zero = {0.0, 0.0};
    esito = divisione_complessi(a, zero, &ottenuto);

    if (esito == 0)
    {
        printf("OK: divisione per zero rifiutata\n");
    }   
    else{
        printf("ERRORE: divisione per zero accettata\n");
        return 1;
    }

    return 0;
}
