#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytywanie.h"



struct Macierz* wczytaj(char *fnazwa) 
{
    FILE *fin;
    struct Macierz *m;
    fin=fopen(fnazwa, "r");

    m = (struct Macierz*) malloc(sizeof(struct Macierz));

    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);


    m->tab = (float**) malloc(sizeof(float*) * m->r);
    for (int i=0; i < m->r; i++) 
    {
        m->tab[i] = (float*) malloc(sizeof(float) * m->c);
        for (int j=0; j < m->c; j++) 
        {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }

    fclose(fin);

    return m;
}

struct Macierz* wypisz(struct Macierz *m) 
{
    
    
    for (int i = 0; i < m->r; i++) 
    {
        printf("[ ");
        for (int j=0; j < m->c; j++) 
        {
            printf("%5.1f ", m->tab[i][j]);
        }
        printf(" ]");   
        if (i < (m->r-1))
        {
            printf("\n");
        }
        
    }
    
    
}


void zapisz(char nazwa[], struct Macierz *m)
{
    FILE * fout = fopen(nazwa, "w");
    
    fprintf(fout, "%d\n%d\n", m->r, m->c);

    for (int i = 0; i < m->r; i++) 
    {
        for (int j=0; j < m->c; j++) 
        {
            fprintf(fout, "%f\n", m->tab[i][j]);
        }
    }

    fclose(fout);
}

void zapisz2(char nazwa[], float e)
{
    FILE * fout = fopen(nazwa, "w");
    
     fprintf(fout, "%f\n", e);


    fclose(fout);
}

void zwolnij (struct Macierz *m)
{
    for (int i=0; i < m->r; i++)
    {
        free(m->tab[i]);
    }
    free(m->tab);
    free(m);
}

