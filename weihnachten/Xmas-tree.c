#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void){

int tree_height = 1, tree_width = 0, tree_trunk_width = 3, tree_trunk_height = 4, b = 24, c = 0;
char answer = 0;

    do{
        
        printf("X-Mas Tree configurator\n~~~~~~~~~~~~~~~~~~~~~~~\n\n");
        printf("Size of the tree [number of segments (1-8)]: ");
        scanf("%d", &tree_height);
        printf("\n");

        printf("\t\t\t\t\t*******************\n\t\t\t\t\t**Merry Christmas**\n\t\t\t\t\t*******************\n\n");

        for(int l = 0; l < tree_height; l++){
            for(int i = 0; i < 6; i++){
                tree_width = 2 * i + 1;
                printf("\t\t\t");
                for(int k = b; k >= 0; k--){
                    printf(" ");
                }
                for(int j = c; j < tree_width; j++){
                    printf("* ");
                }
                printf("\n");
                b=b-2;
            }
            c-=2;
            b = 24 + c;
        }

        for(int i = 0; i < tree_trunk_height; i++){
            printf("\t\t\t");
            for(int k = 22; k >= 0; k--){
                    printf(" ");
                }
            for(int j = 0; j < tree_trunk_width; j++){
                printf("* ");
            }
            printf("\n");
        }
        
    }while(tree_height < 1 || tree_height > 8);

    printf("Do you want to draw again? [y/n]: ");
    scanf(" %c", &answer);

    if(answer == 'y'){
        system("cls");
        main();
    }
    else{
        printf("Do you want to save the tree to a file? [y/n]: ");
        scanf(" %c", &answer);

        if(answer == 'y'){
            b = 24, c = 0;
            FILE *fptr;
            fptr = fopen("tree.txt", "w");
            fprintf(fptr, "X-Mas Tree configurator\n~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            fprintf(fptr, "Size of the tree [number of segments (1-8)]: %d\n\n", tree_height);
            fprintf(fptr, "\t\t\t\t\t\t\t*******************\n\t\t\t\t\t\t\t**Merry Christmas**\n\t\t\t\t\t\t\t*******************\n\n");

            for(int l = 0; l < tree_height; l++){
                for(int i = 0; i < 6; i++){
                    tree_width = 2 * i + 1;
                    fprintf(fptr, "\t\t\t");
                    for(int k = b; k >= 0; k--){
                        fprintf(fptr, " ");
                    }
                    for(int j = c; j < tree_width; j++){
                        fprintf(fptr, "* ");
                    }
                    fprintf(fptr, "\n");
                    b=b-2;
                }
                c-=2;
                b = 24 + c;
            }

            for(int i = 0; i < tree_trunk_height; i++){
                fprintf(fptr, "\t\t\t");
                for(int k = 22; k >= 0; k--){
                        fprintf(fptr, " ");
                    }
                for(int j = 0; j < tree_trunk_width; j++){
                    fprintf(fptr, "* ");
                }
                fprintf(fptr, "\n");
            }
            fclose(fptr);
            printf("\n\t\t\t\t\t*******************\n\t\t\t\t\t**Merry Christmas**\n\t\t\t\t\t*******************");
        }
        else{
        printf("\n\t\t\t\t\t*******************\n\t\t\t\t\t**Merry Christmas**\n\t\t\t\t\t*******************");
        }
    }

}