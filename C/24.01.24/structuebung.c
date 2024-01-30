#include <stdio.h>

struct datum 
{ 
    int tag;
    int monat;
    int jahr;
    int tag_des_jahres;
};

void eingabe_datum(struct datum *wann); 

int tag_im_jahr(struct datum *anzahlTage); 

int mon_tab[2][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31}, 
                     {0,31,29,31,30,31,30,31,31,30,31,30,31}};

int main(void){
    struct datum wann;
    eingabe_datum(&wann);
    printf("Der %d.%d.%d ist der %d. Tag des Jahres.\n", wann.tag, wann.monat, wann.jahr, wann.tag_des_jahres);
    return 0;
}

void eingabe_datum(struct datum *wann){
    printf("Tag: ");
    scanf("%d", &wann->tag);
    printf("Monat: ");
    scanf("%d", &wann->monat);
    printf("Jahr: ");
    scanf("%d", &wann->jahr);
    wann->tag_des_jahres = tag_im_jahr(wann);
}

int tag_im_jahr(struct datum *anzahlTage){
    int i, j, k, tage;
    tage = 0;
    int schaltjahr = 0;
    if(anzahlTage->jahr % 4 == 0){
        if(anzahlTage->jahr % 100 == 0){
            if(anzahlTage->jahr % 400 == 0){
                for(i = 0; i < anzahlTage->monat; i++){
                    tage += mon_tab[1][i];
                }
                tage += anzahlTage->tag;
                schaltjahr = 1;
            }
            else{
                for(j = 0; j < anzahlTage->monat; j++){
                    tage += mon_tab[0][j];
                }
                tage += anzahlTage->tag;
            }
            schaltjahr = 0;
        }
        else{
            for(k = 0; k < anzahlTage->monat; k++){
                tage += mon_tab[1][k];
            }
            tage += anzahlTage->tag;
        }
        schaltjahr = 1;
    }
    else{
        for(k = 0; k < anzahlTage->monat; k++){
            tage += mon_tab[0][k];
        }
        tage += anzahlTage->tag;
    }
    if (schaltjahr == 1){
        printf("Schaltjahr\n");
    }
    else{
        printf("Kein Schaltjahr\n");
    }
    return tage;
}