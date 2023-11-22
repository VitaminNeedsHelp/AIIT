#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

char menu(int *array, int size);
void printArray(int *array, int size);
void enterValueSortArray(int *array, int size, int value, int *length); //Einfügen und sortieren in einem
void deleteValue(int *array, int size, int value, int *length);

int main(void){

    int array[SIZE] = {0};
    int input, value, length = 0;

    do{
        input = menu(array, SIZE);
        switch(input){
            case '1':
                printf("Bitte geben Sie einen Wert ein: ");
                scanf("%d", &value);
                enterValueSortArray(array, SIZE, value, &length);
                break;
            case '2':
                printf("Bitte geben Sie einen Wert ein: ");
                scanf("%d", &value);
                deleteValue(array, SIZE, value, &length);
                break;
            case '3':
                printf("Aktuelle L\x84nge des Arrays: %d\n", length);
                break;
            case 'b':
                printf("Programm wird beendet...\n");
                break;
            default:
                printf("Falsche Eingabe!\n");
                break;
        }
    }while(input != 'b');

    system("PAUSE");
    return 0;

}

char menu(int *array, int size){
    char input;

    printf("Aktuelles Array: \n");
    printArray(array, SIZE);
    printf("\n\n");
    printf("1...Wert einf\x81gen\n");
    printf("2...Wert l\x94schen\n");
    printf("3...Aktuelle L\x84nge des Arrays anzeigen\n");
    printf("b...Programm beenden\n");
    printf("Ihre Eingabe: ");
    fflush(stdin);
    scanf("%c", &input);

    return input;
}

void printArray(int *array, int size){
    for(int i = 0; i < size; i++){
        if(array[i] != 0){
            printf("%3d |", array[i]);
        }
    }
    printf("\n");
}

void enterValueSortArray(int *array, int size, int value, int *length){
    int temp, i = 0;
    for(i = (*length) - 1; i >= 0 && array[i] > value ; i--)
        {
            array[i + 1] = array[i]; 
        }

        array[i + 1] = value;
        (*length)++;
}

void deleteValue(int *array, int size, int value, int *length){
    int flag = 0;
    for (int i = 0; i < *length; i++) {
        if (array[i] == value) {
            for (int j = i; j < (*length); j++) {
                array[j] = array[j + 1];
            }
            flag = 1;
            (*length)--;
            i--;
        }
    }
    if(flag == 0){
        printf("Wert nicht gefunden!\n");
    }
}