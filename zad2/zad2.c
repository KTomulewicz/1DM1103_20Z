#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// jedyne czego nie wiem to jak rozpatrywać przypadki, gdy wpisze np. macierz 3x3 a wektor 2x1, program obliczy koncowa macierz, ale matematycznie jest to niestety niepoprawne
// wiem ze jesli ma wyjsc wynik to ilosc kolumn w macierzy musi byc rowna ilosci rzedow w wektorze i po prostu nie wiem czy program ma to uwzgledniac
// wiec z gory zakladam ze podaje macierz i wektor ktory zawsze sie wymnozy


int wczyt (FILE *fin, float t[][200])
{

    int w=0, k=0, a;
    float liczba;

    if ((a = fscanf(fin, "%d" "%d", &w, &k)) != 2)
    {
        //musi byc 2 zeby bylo wiadomo ze ilosc kolumn i wierszy wpisala sie poprawnie
        printf ("Rozmiar macierzy nie zgadza się!"
                " Liczba wpisanych argumentów: %d\n", a);
        exit(-1);

        // wczytuje wymiary macierzy i wektora jednoczesnie sprawdzajac czy sa one liczba calkowita czy jakims napisem
        // jesli jest to napis to konczy program i wypisuje mi komunikat o bledzie
    }

    for (int i=0; i < w; i++)
    {
        for (int j=0; j < k; j++)
        {
            
            if (fscanf (fin, "%f", &liczba) != 1)
            {
                printf ("%d. liczba w %d. wierszu nie jest liczbą zmiennoprzecinkową.\n", j+1, i+1);
                exit(-2);
                // tutaj jestem w macierzy lub wektorze i sprawdzam czy w pojedynczych komorkach mam liczby czy tekst
                // jesli jest napis to konczy program i wypisuje mi blad 
            }
            t[i][j]=liczba;
        }
    }
    return w;
}



void mnozenie ( int wierszwektor, int wierszmacierz, float wektor[][200], float macierz[][200])
{
    int kw=0; // bedzie to kolumna wektora
    float iloczyn=0; // wynik mnożenia macierzy i wektora

    for (int i=0; i < wierszmacierz; i++)
    {
        //jestesmy w macierzy np. w pierwszym wierszu i musimy sprawdzic kolejne wiersze wektora
        for (int j=0; j < wierszwektor; j++)
        {
            //teraz mnozymy caly wiersz macierzy skaczac po kolumnach 

            iloczyn = iloczyn + macierz[i][j] * wektor[j][kw];  
            
        }
        printf ("%1.1f ", iloczyn);
        iloczyn=0;
    }   
}


int main(int argc, char *argv[])
{

    FILE *fin1;
    FILE *fin2;

    int wierszmacierz, wierszwektor;

    float m[200][200], we[200][200];

    wierszmacierz = wczyt(fopen (argv[1], "r"), m);
    wierszwektor = wczyt(fopen (argv[2], "r"), we);
    // wczytywanie plikow tekstowych

    
    printf ("(%d) ", wierszmacierz);
    printf ("[");
    
    mnozenie(wierszwektor, wierszmacierz, we, m);
    // mnozenie macierzy i wektora
    printf ("]");

    return 0;
}