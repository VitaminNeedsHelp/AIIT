#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define SIZE 30

void printMenu(char *choice, int *array);
void checkBoatlength(int *array);
void parkBoats(int *array, int length);
void findBoats(int *array, int *check, int *position, int length);

int main(void){

    int array[SIZE] = {0};
    int length = 0;
    char choice = 0;

    printMenu(&choice, array);

    while(choice != '6')
    {
        switch(choice)
        {
            case '1':
                for(int i=0; i<SIZE; i++)
                {
                    printf("%2d",array[i]);
                    printf("|");
                }
                printf("\n");
                break;
            case '2':
                parkBoats(array, 1);
                break;
            case '3':
                printf("Length: ");
                scanf("%d", &length);
                parkBoats(array, length);
                break;
            case '4':
                checkBoatlength(array);
                break;
            case '5':
                for(int i=0; i<SIZE; i++)
                {
                    array[i]=0;
                }
                break;
            default:
                printf("Falsche Eingabe!\n");
                break;
        }
        printMenu(&choice, array);
    }
}

void printMenu(char *choice, int *array){
    printf("Ultimate Boat Inserter\n----------------------\n");
    printf(" 1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30|\n");

    for(int i=0; i<SIZE; i++)
    {
        printf("%2d",array[i]);
        printf("|");
    }

    printf("\n\n");
    printf("1...Show All Elements inkl. Positionrow\n2...Insert on Position x, Boat with length 1\n3...Insert on Position x, Boat with length y\n4...Check Boatlength on Position x\n5...Reset all Boats to 0\n");
    printf("6...Exit\n");

    *choice=getch();
}

void checkBoatlength(int *array){
    int position = 0, length = 0;

    printf("Position: ");
    scanf("%d", &position);

    length = array[position-1];

    printf("Length: %d\n", length);
}

void parkBoats(int *array, int length){
    int position = 0, check = 0;

    printf("Position: ");
    scanf("%d", &position);
    while(check==0){
    findBoats(array, &check, &position, length);
    }

    if(check == 1&&position-1<=SIZE)
    {
        for(int i = position-1; i<position-1+length; i++)
        {
            array[i] = length;
        }
        printf("Boat with length %d parked on position %d\n", length, position);
    }
    else
    {
        printf("No free space for boat with length %d\n", length);
    }
}
    


void findBoats(int *array, int *check, int *position, int length){
    bool flag = true;
            printf("d");
        if(array[*position-1] == 0 && length==1)
        {
            *check = 1;
            return;
        }
        else
        {
            //printf("Position: %d", *position);
            for(int i=*position-1; i<=*position-1+length; i++)
            {
                if(array[i] != 0)
                {
                    flag = false;
                    *position = i+2;
                    return;
                }
            }
            if(flag)
            {
                *check = 1;
                return;
            }
            else
            {
                *check = 0;
                return;
            }
        }
    }

