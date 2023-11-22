#include <stdio.h>

#include <stdlib.h>

 

#define Zeile 3   /* Anzahl Felder erste Dimension - Zeilen   */

#define Spalte 4   /* Anzahl Felder zweite Dimension - Spalten */

 

void Zuweisung(int thatArray[Zeile][Spalte]) {

    int i,j,help;

    for(i=0; i < Zeile; i++) {

        for(j=0; j < Spalte; j++) {

            printf("Wert fuer myArray[%d][%d]:", i, j);

            scanf("%d", &thatArray[i][j]);

      }

   }

}

 

void Ausgabe (int thatArray[Zeile][Spalte]) {

    int i,j;

    printf("\nAusgabe von myArray[%d][%d]...\n\n", Zeile, Spalte);

    for(i=0; i < Zeile; i++) {

        for(j=0; j < Spalte; j++) {

            printf("\t%4d ",thatArray[i][j]);

        }

        printf("\n\n");

    }

}

 

int main(void) {

    int i,j;

    int myArray[Zeile][Spalte];

    //Eingabe der Array-Elemente

    Zuweisung(myArray);

    //Ausgabe der Array-Elemente

    Ausgabe(myArray);  

   return 0;

}