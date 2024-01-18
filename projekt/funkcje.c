#include "funkcje.h"
struct pokoje
{
    /*hotel ma 4 pietra kazde pietro ma 15 pokoi */
    int pietro;
    int pokoj;
    int dostepnosc; /*pokoj wolny ma wartosc 0 a zajety 1 */
    float wplacona_kwota;
    int dlugosc_rezerwacji;
    struct pokoje* nast;
};
typedef struct pokoje pokoje;
pokoje* pobierz_informacje()
{
    FILE *a;
    a = fopen("odczyt_dla_komputera.txt", "r");
    int i;
    int j=1;
    int k=0;
    pokoje* p = NULL;
    pokoje* pokoj;
    if(a == NULL)
    {
    printf("Nie udalo sie odczytac informacji z pliku.\n");
    for (i = 0; i < ilosc_pieter*ilosc_pokoi; i++)
    {
        if (j>15)
        {
            j=1;
            k++;
        }
        pokoj = (pokoje*)malloc(sizeof(pokoje));
        pokoj->pietro=k;
        pokoj->pokoj=j;
        pokoj->nast = p;
        pokoj->dostepnosc=0;
        pokoj->wplacona_kwota = 0.0;
        pokoj->dlugosc_rezerwacji = 0;
        p = pokoj;
        j++;
    }
    }
    else
    {
    for (i = 0; i < ilosc_pieter*ilosc_pokoi; i++)
    {
        if (j>15)
        {
            j=1;
            k++;
        }
        pokoj = (pokoje*)malloc(sizeof(pokoje));
        pokoj->nast = p;
        fscanf(a, "%d %d %d %f %d ",&pokoj->pietro,&pokoj->pokoj, &pokoj->dostepnosc, &pokoj->wplacona_kwota, &pokoj->dlugosc_rezerwacji);
        p = pokoj;
        j++;
    }
    }
    fclose(a);
    return pokoj;
}
void wpisz_do_pliku (pokoje* lista)
{
    FILE *c;
    c=fopen("odczyt_dla_komputera.txt","w");
    for(;lista!=NULL;lista=lista->nast)
    {
        fprintf(c,"%d %d %d %f %d ",lista->pietro,lista->pokoj,lista->dostepnosc,lista->wplacona_kwota,lista->dlugosc_rezerwacji);
    }
    fclose(c);
}
void wpisz_do_pliku_dla_komputera (pokoje* lista)
{
    FILE *b;
    b=fopen("odczyt_dla_ludzi.txt","w");
    for(;lista!=NULL;lista=lista->nast)
    {
        fprintf(b,"Pokoj %d na pietrze %d jest ",lista->pokoj,lista->pietro);
        if (lista->dostepnosc==0)
        {
            fprintf(b,"wolny\n");
        }
        else
        {
            fprintf(b,"zajety\n");
        }
        fprintf(b,"Wplacono %f zl i rezerwacja trwa %d dni\n",lista->wplacona_kwota,lista->dlugosc_rezerwacji);
    }
    fclose(b);
}
pokoje* rezerwowanie(pokoje* lista, int dlugosc_rezerwacji, float kwota, int wybrane_pietro, int wybrany_pokoj)
{
    pokoje* p=lista;
    pokoje* k=p->nast;
    while (p != NULL)
    {
        if (p->pietro == wybrane_pietro && p->pokoj == wybrany_pokoj)
        {
            if (p->dostepnosc == 0 && kwota == cena_pokoju * dlugosc_rezerwacji)
            {
                if(wybrane_pietro==3&&wybrany_pokoj==15)
                {
                lista->dostepnosc = 1;
                lista->wplacona_kwota = kwota;
                lista->dlugosc_rezerwacji = dlugosc_rezerwacji;
                printf("Rezerwacja udana.\n");
                return lista;
                }
                else
                {
                p->dostepnosc = 1;
                p->wplacona_kwota = kwota;
                p->dlugosc_rezerwacji = dlugosc_rezerwacji;
                printf("Rezerwacja udana.\n");
                lista->nast=k;
                return lista;
                }
            }
            else
            {
                printf("Pokoj jest juz zajety lub podano niewlasciwa kwote.\n");
                return lista;
            }
        }
        p = p->nast;
    }
    printf("Podany pokoj nie istnieje.\n");
    return 0;
}
void wypisz_dostepnosc(pokoje* lista)
{
    for(;lista!=NULL;lista=lista->nast)
    {
        if(lista->dostepnosc==0)
        {
            printf("Pokoj %d ",lista->pokoj);
            printf("na pietrze %d jest wolny\n",lista->pietro);
        }
        else
        {
            printf("Pokoj %d ",lista->pokoj);
            printf("na pietrze %d jest zajety\n",lista->pietro);

        }
    }
}
void dostepnosc_w_czasie(pokoje* lista, int wybrane_pietro, int wybrany_pokoj, int za_ile_dni)
{
    while (lista != NULL)
    {
        if (lista->pietro == wybrane_pietro && lista->pokoj == wybrany_pokoj)
        {
            if (za_ile_dni>lista->dlugosc_rezerwacji)
            {
                printf("Pokoj w tym czasie jest wolny.\n");
            }
            else
            {
                printf("Pokoj w tym czasie jest zajety.\n");
            }
        }
        lista = lista->nast;
    }
}
int menu(int wybor)
{
    printf("------------------------------------------\n");
    printf("WITAJ W HOTELU MARMUR\n");
    printf("------------------------------------------\n");
    printf("1.Pokaz dostepnosc pokoi\n");
    printf("2.Zarezerwuj pokoj\n");
    printf("3.Sprawdz dostepnosc w danym czasie\n");
    printf("4.Wyjdz\n");
    printf("Wybor: "); scanf("%d",&wybor); printf("\n");
    return wybor;
}
