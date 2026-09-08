#include <stdio.h>
#include "complessi.h"

int leggi_complesso(Complesso *z)
{
     if (scanf("%lf %lf", &z->reale, &z->immaginaria) != 2)
    {
        return 0;
    }
    else
    {        
        return 1;
    }
    
}


int main(void)
{
   Complesso z1;
   Complesso z2;
   int scelta;
   Complesso risultato;
   
    printf("Inserisci parte reale e immaginaria di z1: ");

    if (leggi_complesso(&z1) != 1)
    {
        printf("Errore: devi inserire due numeri.\n");
        return 1;
    }

    printf("Inserisci parte reale e immaginaria di z2: ");

    if (leggi_complesso(&z2) != 1)
    {
        printf("Errore: devi inserire due numeri.\n");
        return 1;
    }
   
   do
   {
    printf("\n0. Esci\n");
    printf("1. Somma\n");
    printf("2. Prodotto\n");
    printf("3. Divisione\n");
    printf("4. Cambia i numeri complessi\n");
    printf("5. Modulo di z1\n");
    printf("6. Fase di z1\n");
    printf("7. Coniugato di z1\n");
    printf("8. Potenza di z1\n");
    printf("Scegli un'operazione: ");

    if (scanf("%d", &scelta) != 1)
    {
            printf("Errore devi inserire un numero intero\n");
            return 1;
    }

    switch (scelta)
    {
    case 0:
            printf("Chiusura del programma\n");
            break;

    case 1:
            risultato = somma_complessi(z1,z2);
            printf("Somma: %.2f %+.2fi\n", risultato.reale, risultato.immaginaria);       
            break;

    case 2:
            risultato = prodotto_complessi(z1,z2);
            printf("Prodotto: %.2f %+.2fi\n", risultato.reale,risultato.immaginaria);
            break;
        
    case 3:{
            int esito = divisione_complessi(z1,z2, &risultato);

            if (esito==1)
            {
                printf("Quoziente: %.6f %+.6fi\n", risultato.reale, risultato.immaginaria);
            }
            else
            {
                printf("Errore: divisione per zero\n");
            }
            break;
        }
    case 4:
            printf("Inserisci parte reale e immaginaria di z1: ");

            if (leggi_complesso(&z1) != 1)
            {
                printf("Errore: devi inserire due numeri.\n");
                return 1;
            }

            printf("Inserisci parte reale e immaginaria di z2: ");

            if (leggi_complesso(&z2) != 1)
            {
                printf("Errore: devi inserire due numeri.\n");
                return 1;
            }

            printf("Numeri aggiornati\n");
            break;
    
    case 5: //Modulo numero complesso
        {   double modulo;
            modulo = modulo_complesso(z1);
            printf("Modulo di z1: %.6f \n", modulo);
            break;
        }
    case 6: //Fase numero complesso
        {   double fase;
            if (z1.reale == 0 && z1.immaginaria == 0)
            {
                printf("Fase non definita");
            }
            else{
                fase = fase_complesso(z1);
                printf("Fase di z1: %.6f rad\n", fase);
            }
            break;
        }

    case 7: //Coniugato numero complesso
            risultato = coniugato_complesso(z1);
            printf("Il coniugato di z1 vale: %.6f %+.6fi \n", risultato.reale, risultato.immaginaria);
            break;
        
    case 8: //Potenza numero complesso
        {
            int esponente;

            printf("Inserisci un esponente intero non negativo: ");
            if (scanf("%d", &esponente) != 1)
            {
                printf("Errore devi inserire un numero intero \n");
                return 1;
            }
            if (esponente < 0)
            {
                printf("Errore: l'esponente deve essere non negativo \n");
                break;
            }

            risultato = potenza_complesso(z1,esponente);
            printf("Il numero complesso %.6f %+.6fi elevato alla %d^ potenza vale: %.6f %+.6fi\n",
                            z1.reale, z1.immaginaria, esponente, risultato.reale, risultato.immaginaria);
            
            break;
            
        }
        

    default:
            printf("Scelta non valida\n");
            break;

    

    }
    
   } while (scelta!=0);
   
   return 0;
}