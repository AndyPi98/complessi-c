#include "complessi.h"
#include <math.h>

Complesso somma_complessi(Complesso a, Complesso b)
{
    Complesso risultato;

    risultato.reale = a.reale + b.reale;
    risultato.immaginaria = a.immaginaria + b.immaginaria;

    return risultato;
}

Complesso prodotto_complessi(Complesso a, Complesso b)
{
    Complesso prodotto;
    prodotto.reale = (a.reale * b.reale) - (a.immaginaria * b.immaginaria);
    prodotto.immaginaria = (a.reale * b.immaginaria) + (a.immaginaria * b.reale);
    
    return prodotto;
}

Complesso coniugato_complesso(Complesso z)
{
    z.immaginaria = - z.immaginaria;
    return z;
}

double modulo_complesso(Complesso z)
{
    double modulo;
    modulo = sqrt(z.reale*z.reale + z.immaginaria*z.immaginaria);

    return modulo;

}

double fase_complesso(Complesso z)
{
    double fase;
    fase = atan2(z.immaginaria,z.reale);

    return fase;
}

Complesso polare_to_cartesiano(double modulo, double fase)
{
    Complesso z;
    z.reale = modulo * cos(fase);
    z.immaginaria = modulo * sin(fase);

    return z;
}

Complesso potenza_complesso(Complesso z, unsigned int n)
{
    Complesso deMoivre;

    if (n==0)
    {
        deMoivre.reale = 1.0;
        deMoivre.immaginaria = 0.0;
    }
    else if (z.reale == 0 && z.immaginaria == 0 && n > 0)
    {
        deMoivre.reale = 0.0;
        deMoivre.immaginaria = 0.0;
    }
    else{

        double modulo_potenza = pow(modulo_complesso(z), n);
        double fase_potenza = n * fase_complesso(z);
        deMoivre = polare_to_cartesiano(modulo_potenza, fase_potenza);

    }

    return deMoivre;
    
}

int divisione_complessi(Complesso dividendo, Complesso divisore, Complesso *risultato)
{

    if (divisore.reale == 0 && divisore.immaginaria == 0)
    {
        return 0;
    }
    else
    {
        Complesso coniugato = coniugato_complesso(divisore);
        Complesso numeratore = prodotto_complessi(dividendo,coniugato);
        double denominatore = divisore.reale * divisore.reale
                    + divisore.immaginaria * divisore.immaginaria;

        risultato -> reale = numeratore.reale / denominatore;
        risultato -> immaginaria = numeratore.immaginaria / denominatore;
         
        //risultato.reale = numeratore.reale / denominatore;
        //risultato.immaginaria = numeratore.immaginaria / denominatore;
         
        return 1;
    }   

}
