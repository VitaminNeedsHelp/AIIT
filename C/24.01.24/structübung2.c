#include <stdio.h>
#include <stdlib.h>

struct BAUSTEIN
{
    int laenge;
    int breite;
    int hoehe;
    int rgb[3];
    char farbe[20];
    char name[80];
};

void eingabeBS(struct BAUSTEIN *bs);
void ausgabeBS(struct BAUSTEIN bs);
void compareBS(struct BAUSTEIN bs1, struct BAUSTEIN bs2);

int main(void)
{
    struct BAUSTEIN bs1, bs2;
    printf("Baustein 1:\n");
    eingabeBS(&bs1);
    printf("Baustein 2:\n");
    eingabeBS(&bs2);
    printf("Baustein 1:\n");
    ausgabeBS(bs1);
    printf("Baustein 2:\n");
    ausgabeBS(bs2);
    compareBS(bs1, bs2);
    return 0;
}

void eingabeBS(struct BAUSTEIN *bs)
{
    printf("Laenge: ");
    scanf("%d", &bs->laenge);
    printf("Breite: ");
    scanf("%d", &bs->breite);
    printf("Hoehe: ");
    scanf("%d", &bs->hoehe);
    printf("RGB-Werte: ");
    scanf("%d %d %d", &bs->rgb[0], &bs->rgb[1], &bs->rgb[2]);
    printf("Name: ");
    scanf("%s", bs->name);
}

void ausgabeBS(struct BAUSTEIN bs)
{
    printf("Laenge: %d\n", bs.laenge);
    printf("Breite: %d\n", bs.breite);
    printf("Hoehe: %d\n", bs.hoehe);
    printf("RGB-Werte: %d %d %d\n", bs.rgb[0], bs.rgb[1], bs.rgb[2]);
    // farbe als hex wert ausgeben
    printf("Farbe: #%02x%02x%02x\n", bs.rgb[0], bs.rgb[1], bs.rgb[2]);
    printf("Name: %s\n", bs.name);
}

void compareBS(struct BAUSTEIN bs1, struct BAUSTEIN bs2)
{
    int v1 = bs1.laenge * bs1.breite * bs1.hoehe;
    int v2 = bs2.laenge * bs2.breite * bs2.hoehe;
    int vv = 0;
    if (v1 > v2)
    {
        vv = v1 - v2;
        printf("Baustein 1 ist %d cm3 groesser als Baustein 2", vv);
    }
    else if (v1 < v2)
    {
        vv = v2 - v1;
        printf("Baustein 2 ist %d cm3 groesser als Baustein 1", vv);
    }
    else
    {
        printf("Baustein 1 und Baustein 2 sind gleich gross");
    }
}
