#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

#define SIZE 15

void fillRandomLetters(char *str, int size);
void menu(int *choice);
void insertAndShiftLeft(char *str, int position, int size);
void insertAndShiftRight(char *str, int position, int size);

int main(void){
    char str[SIZE] = {0};
    int choice = 0;
    int position = 0;

    srand(time(NULL));

    fillRandomLetters(str, SIZE);

    printf("  1|  2|  3|  4|  5|  6|  7|  8|  9| 10| 11| 12| 13| 14| 15|\n", str);
    for(int i = 0; i < SIZE; i++){
    if(i < SIZE- 1){
            printf(" %c -", str[i]);
        }
    else{
            printf(" %c\n", str[i]);
        }
    }

    menu(&choice);

    printf("Your choice: %d\n", choice);

    switch(choice){
        case 1:
            printf("Insert and shift left:\n");
            insertAndShiftLeft(str, position, SIZE);
            break;
        case 2:
            printf("Insert and shift right\n");
            break;
        case 3:
            printf("Exit\n");
            return 0;
            break;
    }

}

void fillRandomLetters(char *str, int size){
    int i;
    for(i = 0; i < size; i++){
        str[i] = rand() % 26 + 97;
    }
}

void menu(int *choice){
    do{
        printf("1...Insert and shift left\n2...Insert and shift right\n3...Exit\n");
        printf("Your Choice: ");
        *choice = getche();
    }while(*choice < 1 || *choice > 3);
}

void insertAndShiftLeft(char *str, int position,int size){
    int i;
    char letter;

    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter letter: ");
    letter = getche();
    printf("\n");
    for(i = 0; i < size; i++){
        if(str[i] == letter){
            for(int j = i; j < size; j++){
                str[j] = str[j+1];
            }
            str[size-1] = 0;
        }
    }
}