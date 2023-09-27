#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b);

int main(void){
    char a = 0, b = 0;
    printf("Value-Tausch\n");

    printf("Bitte geben Sie den Wert von a ein: ");
    fflush(stdin);
    scanf("%c", &a);
    printf("Bitte geben Sie den Wert von b ein: ");
    fflush(stdin);
    scanf("%c", &b);

    printf("Before Swap:\na = %c, b = %c\n", a, b);
    swap(&a, &b);
    printf("After Swap:\na = %c, b = %c\n", a, b);
}

void swap(char *a, char *b){
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}