#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#define SIZE 15

void fillRandomLetters(char *str, int size);
void printArray(char *str, int size);
void menu(char *choice);
void insertAndShiftLeft(char *str, int position, int size);
void insertAndShiftRight(char *str, int position, int size);

int main(void){
    char str[SIZE] = {0};
    char choice = 0;
    int position = 0;

    srand(time(NULL));

    fillRandomLetters(str, SIZE);

    printArray(str, SIZE);

    menu(&choice);

    while(choice != 3){
        switch(choice){
            case '1':
                printf("\nInsert and shift left:\n");
                insertAndShiftLeft(str, position, SIZE);
                printArray(str, SIZE);
                menu(&choice);
                break;
            case '2':
                printf("\nInsert and shift right\n");
                insertAndShiftRight(str, position, SIZE);
                printArray(str, SIZE);
                menu(&choice);
                break;
            case '3':
                printf("\n");
                printf("                                    __ ");
                printf(" _____           _    _____        |  |");
                printf("|   __|___ ___ _| |  | __  |_ _ ___|  |");
                printf("|  |  | . | . | . |  | __ -| | | -_|__|");
                printf("|_____|___|___|___|  |_____|_  |___|__|");
                printf("                           |___|       ");
                return 0;
                break;
        }
    }

}

void fillRandomLetters(char *str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = rand() % 26 + 97;
    }
}

void printArray(char *str, int size){
    printf("  1|  2|  3|  4|  5|  6|  7|  8|  9| 10| 11| 12| 13| 14| 15|\n", str);
    for(int i = 0; i < SIZE; i++){
    if(i < SIZE- 1){
            printf(" %c -", str[i]);
        }
    else{
            printf(" %c\n", str[i]);
        }
    }
}

void menu(char *choice){
    do{
        printf("\n1...Insert and shift left\n2...Insert and shift right\n3...Exit\n");
        printf("Your Choice: ");
        *choice = getche();
    }while(*choice >= 1 && *choice <= 3);
}

void insertAndShiftLeft(char *str, int position,int size){
    int i;
    char letter;

    printf("Enter position: ");
    scanf(" %d", &position);
    printf("Enter letter: ");
    letter = getche();
    printf("\n");
    
    //shift left
    for(i = 0; i < position - 1; i++){
        str[i] = str[i + 1];
    }

    str[position - 1] = letter;
}


void insertAndShiftRight(char *str, int position, int size){
    int i;
    char letter;

    printf("Enter position: ");
    scanf(" %d", &position);
    printf("Enter letter: ");
    letter = getche();
    printf("\n");

    for(i = size - 1; i >= position; i--){
        str[i] = str[i - 1];
    }
    
    str[position - 1] = letter;
}