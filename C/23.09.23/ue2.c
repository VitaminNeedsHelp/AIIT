//Schreibe ein C-Programm um 3 Zahlen aufsteigend bzw. absteigend zu sortieren. Verwende dafür zwei Funktionen (aufsteigend/absteigend) mit Referenzparameter. Die Zahlen sollen über die Tastatur eingelesen werden.

#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int *b, int *c, int choice);

int main(void){
    int a = 0, b = 0, c = 0;
    int choice = 0;
    printf("Zahlen-Sortierung\n");

    printf("Bitte geben Sie den Wert von a ein: ");
    fflush(stdin);
    scanf("%d", &a);
    printf("Bitte geben Sie den Wert von b ein: ");
    fflush(stdin);
    scanf("%d", &b);
    printf("Bitte geben Sie den Wert von c ein: ");
    fflush(stdin);
    scanf("%d", &c);
    do{
        printf("Aufsteigend sortieren - 1\nAbsteigend sortieren - 2\nDeine Wahl: ");
        fflush(stdin);
        scanf("%d", &choice);
    }while(choice != 1 && choice != 2);

    printf("Before Sort:\na = %d, b = %d, c = %d\n", a, b, c);
    sort(&a, &b, &c, choice);
    printf("After Sort:\na = %d, b = %d, c = %d\n", a, b, c);
}

void sort(int *a, int *b, int *c, int choice){
    int temp;
    if(choice == 1){
        if(*a > *b){
            temp = *a;
            *a = *b;
            *b = temp;
        }
        if(*b > *c){
            temp = *b;
            *b = *c;
            *c = temp;
        }
        if(*a > *b){
            temp = *a;
            *a = *b;
            *b = temp;
        }
    }
    else{
        if(*a < *b){
            temp = *a;
            *a = *b;
            *b = temp;
        }
        if(*b < *c){
            temp = *b;
            *b = *c;
            *c = temp;
        }
        if(*a < *b){
            temp = *a;
            *a = *b;
            *b = temp;
        }
    }
}

