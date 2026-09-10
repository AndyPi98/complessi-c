#include <stdio.h>
#include <math.h>
#include "complessi.h"
#include "segnali.h"

int main(void){
    
    double campioni[100];

    double ampiezza = 2.0;
    double frequenza = 5.0;
    double frequenza_campionamento = 100.0;
    double pi = acos(-1.0);

    double ampiezza2 = 0.5;
    double frequenza2 = 15.0;

    FILE *file = fopen("segnale.csv", "w");

    if (file == NULL)
    {
        printf("errore: impossibile aprire il file\n");
        return 1;
    }

    fprintf(file, "tempo,segnale\n");   


    for (int k = 0; k < 100; k++)
    {
        double tempo = k / frequenza_campionamento;

        double segnale1 = ampiezza * sin(2*pi*frequenza*tempo);
        double segnale2 = ampiezza2 * sin(2*pi*frequenza2*tempo); 

        campioni[k] = segnale1 + segnale2;

        fprintf(file, "%.6f,%.6f\n", tempo, campioni[k]);

        //printf("t = %.2f s, x = %+.6f\n", tempo, campioni[k]);
    }

    if (fclose(file) != 0)
    {
        printf("Errore durante la chiusura dei file\n");
        return 1;
    }

    printf("Salvati 100 campioni in segnale.csv\n");


    Complesso spettro[100];

    if (calcola_dft(campioni, 100, spettro, 100) != 1)
    {
        printf("Errore: dimensioni non valide per la DFT\n");
        return 1;
    }
    
    
    FILE *file_spettro = fopen("spettro.csv", "w");

    if (file_spettro == NULL)
    {
        printf("Errore: impossibile aprire spettro.csv\n");
        return 1;
    }

    fprintf(file_spettro, "frequenza_hz,ampiezza\n");
    

    for (int m = 0; m <= 50; m++)
    {
        double frequenza_bin = m * frequenza_campionamento / 100.0;
        double ampiezza_bin = modulo_complesso(spettro[m]) / 100.0;

        if (m != 0 && m!= 50)
        {
            ampiezza_bin *= 2;
        }

        fprintf(file_spettro, "%.6f,%.6f\n", frequenza_bin, ampiezza_bin);

               
        if (ampiezza_bin > 1e-6)
        {
            printf("Frequenza: %.2f Hz, ampiezza: %.6f\n", frequenza_bin, ampiezza_bin);
        }
        
    }

    if (fclose(file_spettro) != 0)
    {
        printf("Errore durante la chiusura di spettro.csv\n");
        return 1;
    }

    printf("salvato lo spettro in spettro.csv\n");    
        
    return 0;
    
}