struct pokoje;
pokoje* pobierz_informacje();
void wpisz_do_pliku (pokoje*);
void wpisz_do_pliku_dla_komputera (pokoje*);
pokoje* rezerwowanie(pokoje*,int,float,int,int);
void wypisz_dostepnosc(pokoje*);
void dostepnosc_w_czasie(pokoje*,int,int,int);
int menu(int);
