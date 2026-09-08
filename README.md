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