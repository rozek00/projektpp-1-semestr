#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"
#define ilosc_pokoi 15
#define ilosc_pieter 4
#define cena_pokoju 100


int main()
{
    int dlugosc_rezerwacji, wybor;
    float kwota;
    int wybrany_pokoj;
    int wybrane_pietro;
    int za_ile_dni;
    pokoje* lista = pobierz_informacje();

    for (;;)
    {
        wybor = menu(wybor);

        switch (wybor)
        {
        case 1:
            wypisz_dostepnosc(lista);
            break;

        case 2:
            printf("Wplac kwote: ");
            scanf("%f", &kwota);
            printf("Podaj dlugosc dni: ");
            scanf("%d", &dlugosc_rezerwacji);
            printf("Wybierz pietro: ");
            scanf("%d", &wybrane_pietro);
            printf("Wybierz pokoj: ");
            scanf("%d", &wybrany_pokoj);

            if (wybrane_pietro >= 0 && wybrane_pietro < ilosc_pieter && wybrany_pokoj > 0 && wybrany_pokoj <= ilosc_pokoi)
            {
                lista = rezerwowanie(lista, dlugosc_rezerwacji, kwota, wybrane_pietro, wybrany_pokoj);
            }
            else
            {
                printf("Podano nieprawidlowe pietro lub numer pokoju.\n");
            }
            break;

        case 3:
            printf("Wybierz pietro: ");
            scanf("%d", &wybrane_pietro);
            printf("Wybierz pokoj: ");
            scanf("%d", &wybrany_pokoj);
            printf("Podaj za ile dni chcesz sprawdzic dostepnosc: ");
            scanf("%d", &za_ile_dni);

            if (wybrane_pietro > 0 && wybrane_pietro <= ilosc_pieter && wybrany_pokoj > 0 && wybrany_pokoj <= ilosc_pokoi)
            {
                dostepnosc_w_czasie(lista, wybrane_pietro, wybrany_pokoj, za_ile_dni);
            }
            else
            {
                printf("Podano nieprawidlowe pietro lub numer pokoju.\n");
            }
            break;

        case 4:
            wpisz_do_pliku(lista);
            wpisz_do_pliku_dla_komputera(lista);
            return 0;

        default:
            printf("Nieprawidlowy wybor.\n");
        }
    }

    return 0;
}
