#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytywanie.h"


float norm(struct Macierz *m) 
{
    float n = 0;

    for (int w = 0; w < m->r; w++) 
    {
        for (int k=0; k < m->c; k++) 
        {
            n += m->tab[w][k] * m->tab[w][k];
        }
    }
    return sqrt(n);
}

struct Macierz* multiply(struct Macierz *m, float skalar) 
{
    struct Macierz *wynik;
    wynik = (struct Macierz*) malloc(sizeof(struct Macierz));

    wynik->r=m->r;
    wynik->c=m->c;

    wynik->tab = (float**) malloc(sizeof(float*) * wynik->r);
    for (int i=0; i < wynik->r; i++)
        {
            wynik->tab[i] = (float*) malloc(sizeof(float) * wynik->c);
        }
    

    for (int w = 0; w < m->r; w++) 
    {
        for (int k=0; k < m->c; k++) 
        {
            wynik->tab[w][k] = (m->tab[w][k] * skalar);
        }
    }
    return wynik;
}

// warunek równych kolumn i wierszy
struct Macierz* sumuj(struct Macierz *a, struct Macierz *b) 
{
    struct Macierz *suma;
    suma = (struct Macierz*) malloc(sizeof(struct Macierz));

    suma->r=a->r;
    suma->c=a->c;

    suma->tab = (float**) malloc(sizeof(float*) * suma->r);
    for (int i=0; i < suma->r; i++)
        {
            suma->tab[i] = (float*) malloc(sizeof(float) * suma->c);
        }
    
    if ((a->r==b->r) && (a->c==b->c))
    {
        for (int w = 0; w < a->r; w++) 
        {
            for (int k=0; k < a->c; k++) 
            {

                suma->tab[w][k] = a->tab[w][k] + b->tab[w][k];
            }
        
            //printf("\n");
        }
        return suma;
        ////
    }
    else
    {
        printf("Dzialanie niemozliwe do wykonania, zle wymiary macierzy!");
    }
}


// warunek równych kolumn i wierszy
struct Macierz* odejmij(struct Macierz *a, struct Macierz *b) 
{
    struct Macierz *roznica;
    roznica = (struct Macierz*) malloc(sizeof(struct Macierz));

    roznica->r=a->r;
    roznica->c=a->c;

    roznica->tab = (float**) malloc(sizeof(float*) * roznica->r);
    for (int i=0; i < roznica->r; i++)
        {
            roznica->tab[i] = (float*) malloc(sizeof(float) * roznica->c);
        }
    
    if ((a->r==b->r) && (a->c==b->c))
    {
        for (int w = 0; w < a->r; w++) 
        {
            for (int k=0; k < a->c; k++) 
            {

                roznica->tab[w][k] = a->tab[w][k] - b->tab[w][k];
            }
        
            //printf("\n");
        }
        return roznica;
        ////
    }
    else
    {
        printf("Dzialanie niemozliwe do wykonania, zle wymiary macierzy!");
    }
}


struct Macierz* mnozenie(struct Macierz *a, struct Macierz *b) 
{
    struct Macierz *iloczyn;
    iloczyn = (struct Macierz*) malloc(sizeof(struct Macierz));

    iloczyn->r=a->r;
    iloczyn->c=a->c;

    iloczyn->tab = (float**) malloc(sizeof(float*) * iloczyn->r);
    for (int i=0; i < iloczyn->r; i++)
        {
            iloczyn->tab[i] = (float*) malloc(sizeof(float) * iloczyn->c);
        }
    
    if (a->c==b->r) 
    {
        for (int w = 0; w < a->r; w++) 
        {
            for (int k=0; k < a->c; k++) 
            {
                for (int n=0; n < a->c; n++)
                {
                iloczyn->tab[w][k] += a->tab[w][n] * b->tab[n][k];
                }
            }
        
            //printf("\n");
        }
        return iloczyn;
        ////
    }
    else
    {
        printf("Dzialanie niemozliwe do wykonania, zle wymiary macierzy!");
    }
}
