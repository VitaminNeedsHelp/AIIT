#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 12

void printMenu(char *choice, char *array);
void checkBanknote(char *array);
int checkControlnumber(char array[]);
int checkPrinter(char array[]);

int main(void){

    char array[SIZE] = {0};
    char choice = 0;

    printMenu(&choice, array);

    while(choice != '3')
    {
        switch(choice)
        {
            case '1':
                printf("Banknote: ");
                scanf("%s", array);
                break;
            case '2':
                checkBanknote(array);
                break;
            default:
                printf("Falsche Eingabe!\n");
                break;
        }
        printMenu(&choice, array);
    }
}

void printMenu(char *choice, char *array){
    printf("Banknotencheck\n--------------\n");
    printf("1) Banknote eingeben\n");
    printf("2) Banknote pruefen\n");
    printf("3) Beenden\n");
    printf("Auswahl: ");
    scanf(" %c", choice);
}

void checkBanknote(char *array){
    int controlnumber = 0;
    int printer = 0;

    controlnumber = checkControlnumber(array);
    printer = checkPrinter(array);

    if(controlnumber == 0)
    {
        printf("Falsche Kontrollnummer!\n");
    }
    else
    {
        printf("Kontrollnummer: %d\n", controlnumber);
    }

    if(printer == 0)
    {
        printf("Falsche Druckerei!\n"); 
    }
    else
    {
        printf("Druckerei: %d\n", printer);
    }
}

int checkControlnumber(char array[]){
    int sum = 0;
    int controlnumber = 0;
    int rest = 0;

    for(int i=0; i<11; i++)
    {
        if(i<2)
        {
            array[i] = array[i] - 64;
            
            if (array>=10){
                sum += array[i] % 10 + array[i] / 10;   
            }
            else
            {
                sum += array[i];
            }
        }
        else
        {
            sum += array[i] - 48;
        }
    }
    printf("%d\n", sum);
    do
    {
        controlnumber = sum % 9;
        sum = controlnumber;
    }while(controlnumber > 9);

    printf("%d\n", controlnumber);

    rest = 7 - controlnumber;

    if(rest < 0)
    {
        rest = 9 - controlnumber;
    }

    return rest;
}

int checkPrinter(char array[]){
    int sum = 0;
    int printer = 0;

    for(int i=0; i<10; i++)
    {
        if(i<=1)
        {
            sum += array[i] - 64;
        }
        else
        {
            sum += array[i] - 48;
        }
    }

    do
    {
        printer = sum % 9;
        sum = printer;
    }while(printer > 9);

    return printer;
}