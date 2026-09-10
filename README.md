# Calcolatrice di numeri complessi in C

Progetto didattico che collega la programmazione in C
agli argomenti di numeri complessi studiati a Metodi Matematici.

## Funzionalità

- Somma, prodotto e divisione tra due numeri complessi.
- Calcolo di modulo, fase e coniugato del primo numero.
- Potenze con esponente intero non negativo.
- Modifica dei numeri dal menu.
- Controllo della divisione per zero e della fase nell'origine.

La libreria include anche la conversione da forma polare
a cartesiana, utilizzata per calcolare le potenze.

## Struttura

- `complessi.h`: tipo Complesso e dichiarazioni delle funzioni.
- `complessi.c`: implementazione delle operazioni matematiche.
- `main.c`: input da tastiera e menu.

## Compilazione

Serve un compilatore C, per esempio GCC.

```bash
gcc -Wall -Wextra main.c complessi.c -o main.exe -lm
```

## Avvio

```bash
./main.exe
```

Inserire parte reale e immaginaria separate da uno spazio.
Per esempio, `3 -2` rappresenta il numero 3 - 2i.
Usare il punto per i decimali.

## Esempio

Con z1 = 3 + 2i e z2 = 1 - 5i:

- Somma: 4 - 3i
- Prodotto: 13 - 13i
- Divisione: circa -0.269231 + 0.653846i

## Limiti della versione attuale

- Un input non numerico termina il programma.
- La lettura con scanf non valida l'intera riga inserita.
- I calcoli usano double e possono presentare arrotondamenti.
- Valori molto grandi o molto piccoli possono superare
  i limiti numerici delle formule implementate.
- Per le potenze viene adottata la convenzione z^0 = 1,
  anche quando z è zero.
  

## Radici n-esime

La calcolatrice permette di calcolare le radici di z1
con indice da 1 a 20. Ogni risultato viene elevato
all'indice scelto e confrontato con z1 mediante una
tolleranza assoluta di 1e-6.

## Analisi dei segnali

- `segnali.h` e `segnali.c`: DFT per campioni reali.
- `demo_segnali.c`: esempio con 100 campioni a 100 Hz.

Il segnale contiene due sinusoidi:
- 5 Hz, ampiezza 2.
- 15 Hz, ampiezza 0.5.

Compilazione e avvio:

```bash
gcc -Wall -Wextra demo_segnali.c segnali.c complessi.c -o demo_segnali.exe -lm
./demo_segnali.exe
```

La demo genera nella cartella di esecuzione:
- `segnale.csv`: tempo e valore dei campioni.
- `spettro.csv`: frequenza e ampiezza da 0 a 50 Hz.

I file vengono sovrascritti a ogni esecuzione.
La DFT usa un algoritmo diretto con complessità O(N²).
L'esempio usa frequenze coincidenti con i bin della DFT.

## Test automatici

`test_complessi.c` verifica somma, prodotto, divisione
e rifiuto della divisione per zero.

```bash
gcc -Wall -Wextra test_complessi.c complessi.c -o test_complessi.exe -lm
./test_complessi.exe
```

Il programma termina con codice 0 se tutti i test passano,
1 al primo fallimento.