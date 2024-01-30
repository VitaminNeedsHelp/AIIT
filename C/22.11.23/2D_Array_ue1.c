#include <stdio.h>
#include <stdlib.h>

 

#define Mitarbeiter 3
#define Tage 5

void eingabe(int stundenArray[Tage][Mitarbeiter]);
int menu();
/*ArbeiterWochenStunden – Wahl 1

ArbeiterTagesDurchschnitt – Wahl 2

TeamTagesDurchschnitt – Wahl 3

TeamWochenStunden – Wahl 4

ArbeiterStundenUebersicht – Wahl 5*/

int teamWochenStunden(int stundenArray[Tage][Mitarbeiter]);
void arbeiterWochenStunden(int stundenArray[Tage][Mitarbeiter]);
void arbeiterTagesDurchschnitt(int stundenArray[Tage][Mitarbeiter]);
void teamTagesDurchschnitt(int stundenArray[Tage][Mitarbeiter]);
void arbeiterStundenUebersicht(int stundenArray[Tage][Mitarbeiter], int tag, int arbeiter);


int main(void){
    int stundenArray[Tage][Mitarbeiter], auswahl = 0, tag = 0, arbeiter = 0;

    for(int i = 0; i < Mitarbeiter; i++){
        for(int j = 0; j < Tage; j++){
            stundenArray[i][j] = 0;
        }
    }

    eingabe(stundenArray);

    do
    {
        auswahl = menu();
        switch(auswahl){
        case 1:
            arbeiterWochenStunden(stundenArray);
            break;
        case 2:
            arbeiterTagesDurchschnitt(stundenArray);
            break;
        case 3:
            teamTagesDurchschnitt(stundenArray);
            break;
        case 4: 
            printf("Gesamtstunden aller Arbeiter in der Woche\n-----------------------------------------\nGesamtstunden aller Arbeiter i. d. Woche: %3d Std.\n", teamWochenStunden(stundenArray));
            break;
        case 5:
            printf("Bitte Tag eingeben: ");
            scanf("%d", &tag);
            printf("Bitte Arbeiter eingeben: ");
            scanf("%d", &arbeiter);
            arbeiterStundenUebersicht(stundenArray, tag, arbeiter);
            break;
        case 6:
        return 0;
            break;
        default:
            break;
        }
    }
    while(auswahl != 6);
}

void eingabe(int stundenArray[Tage][Mitarbeiter]){
    int i, j;
    for(i = 0; i < Tage; i++){
        printf("\n\n\t\tTag %d in der Woche\n\t\t-------------------\n", i+1);
        for(j = 0; j < Mitarbeiter; j++){
            printf("Arbeiter Nr. %d in Std.: ", j+1);
            scanf("%d", &stundenArray[i][j]);
        }
    }
}

int menu(){
    int wahl = 0;
    printf("\n\n-1- Stundenwoche\n-2- Durchschnitt/Tag\n-3- Durchschnitt aller Arbeiter/Tag\n-4- Durchschnitt aller Arbeiter/Woche\n-5- Einzelauswahl eines Arbeiters\n-6- ENDE\n\n");
    scanf("%d", &wahl);
    return wahl;
}

int teamWochenStunden(int stundenArray[Tage][Mitarbeiter]){
    //alle eingaben im array zusammenzählen
    int i, j, summe = 0;
    for(i = 0; i < Tage; i++){
        for(j = 0; j < Mitarbeiter; j++){
            summe += stundenArray[i][j];
        }
    }
    return summe;
}

void arbeiterWochenStunden(int stundenArray[Tage][Mitarbeiter]){
    for(int i=0; i + 1 <= Mitarbeiter; i++){
        int j, summe = 0;
        printf("Wochenarbeitszeit von Mitarbeiter %d:\n-------------------------------------\n", i+1);
        for(j = 0; j < Tage; j++){
            printf("|%d Std.", stundenArray[j][i]);
            summe += stundenArray[j][i];
        }
        printf("| = Ges: %d Std.\n\n", summe);
    }
}

void arbeiterTagesDurchschnitt(int stundenArray[Tage][Mitarbeiter]){
    for(int i=0; i + 1<= Mitarbeiter; i++){
        int j;
        float durchschn = 0, summe = 0;
        printf("Durchschn. pro Tag/Woche Arbeiter %d:\n-------------------------------------\n", i+1);
        for(j = 0; j < Tage; j++){
            summe += stundenArray[j][i];
        }
        durchschn = summe / Tage;
        printf("Durchschn. v. Arbeiter %d p. Tag: %.1f Std/Tag\n\n", i + 1, durchschn);
    }
}

void teamTagesDurchschnitt(int stundenArray[Tage][Mitarbeiter]){
    int i, j;
    for(i = 0; i < Tage; i++){
        float durchschn = 0, summe = 0;
        for(j = 0; j < Mitarbeiter; j++){
            summe += stundenArray[i][j];
        }
        durchschn = summe / Mitarbeiter;
        printf("Durchschn. Arbeitszeit aller Mitarbeiter pro Tag %d: %.1f Std.\n\n", i + 1, durchschn);
    }
}

void arbeiterStundenUebersicht(int stundenArray[Tage][Mitarbeiter], int tag, int arbeiter){
    printf("Arbeiter %d hat am Tag %d, %d Std. gearbeitet!\n\n", arbeiter, tag, stundenArray[tag-1][arbeiter-1]);
}
