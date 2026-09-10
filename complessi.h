#ifndef COMPLESSI_H
#define COMPLESSI_H

typedef struct
{
    double reale;
    double immaginaria;
} Complesso;

Complesso somma_complessi(Complesso a, Complesso b);
Complesso prodotto_complessi(Complesso a, Complesso b);
Complesso coniugato_complesso(Complesso z);

double modulo_complesso(Complesso z);
double fase_complesso(Complesso z);

Complesso polare_to_cartesiano(double modulo, double fase);
Complesso potenza_complesso(Complesso z, unsigned int n);

int divisione_complessi(Complesso dividendo,
                       Complesso divisore,
                       Complesso *risultato);

int radici_complesse(Complesso z,int n, Complesso radici[], int capacità);

int complessi_vicini(Complesso a, Complesso b, double tolleranza);

#endif