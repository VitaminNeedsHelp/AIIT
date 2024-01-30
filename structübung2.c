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
int compareBS(struct BAUSTEIN bs1, struct BAUSTEIN bs2);

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
    printf("Vergleich: %d\n", compareBS(bs1, bs2));
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

int compareBS(struct BAUSTEIN bs1, struct BAUSTEIN bs2)
{
    int v1 = bs1.laenge * bs1.breite * bs1.hoehe;
    int v2 = bs2.laenge * bs2.breite * bs2.hoehe;
    if (v1 > v2)
    {
        return 1;
    }
    else if (v1 < v2)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
