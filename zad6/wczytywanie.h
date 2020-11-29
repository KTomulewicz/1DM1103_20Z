#ifndef wczytywanie_h
#define wczytywanie_h


struct Macierz
{
    int r;
    int c;
    float **tab;
    
};


struct Macierz* wczytaj(char *fnazwa);

struct Macierz* wypisz(struct Macierz *m);

void zapisz(char nazwa[], struct Macierz *m);

void zapisz2(char nazwa[], float e);

void zwolnij (struct Macierz *m);

#endif