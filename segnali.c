#include <math.h>
#include "segnali.h"

int calcola_dft(const double campioni[], int n, Complesso spettro[], int capacita)
{
    if (n < 1 || n > capacita)
    {
        return 0;
    }

    double pi = acos(-1.0);

    for (int m = 0; m < n; m++)
    {
        spettro[m].reale = 0.0;
        spettro[m].immaginaria = 0.0;

        for (int k = 0; k < n; k++)
        {
        double angolo = (2*pi*m*k) / n;

        spettro[m].reale += campioni[k] * cos(angolo);
        spettro[m].immaginaria -= campioni[k] * sin(angolo);
        }
    }
    

    return 1;
    
}