#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

void moduloExt(int numerator, int denominator, int *div_result, int *div_remainder);
int test(int numerator, int denominator, int div_result, int div_remainder);

int main(void){
    int numerator = 0, denominator = 0;
    int div_result = 0, div_remainder = 0;
    printf("Divisionsberechnung mit Restangabe\xB8\n*******************************\n");

    printf("Z\x84hler eingeben [0-9999]: ");
    fflush(stdin);
    scanf("%d", &numerator);
    printf("Nenner eingeben [1-9999]: ");
    fflush(stdin);
    scanf("%d", &denominator);

    moduloExt(numerator, denominator, &div_result, &div_remainder);
    printf("%d / %d = %d | Rest = %d\n", numerator, denominator, div_result, div_remainder);
    if(test(numerator, denominator, div_result, div_remainder)){
        printf("Test erfolgreich\n");
    }
    else{
        printf("Test fehlgeschlagen\n");
    }
    printf("Neue Berechnung? [j/n]: ");
    fflush(stdin);
    if(getche() == 'j'){
        system("cls");
        main();
    }
    else{
        printf("\nProgrammende\n");
        return 0;
    }
}

void moduloExt(int numerator, int denominator, int *div_result, int *div_remainder){
    *div_result = numerator / denominator;
    *div_remainder = numerator % denominator;
}

int test(int numerator, int denominator, int div_result, int div_remainder){
    if(div_result == numerator / denominator && div_remainder == numerator % denominator){
        return 1;
    }
    else{
        return 0;
    }
}

