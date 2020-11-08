
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Macierz
{
    int r;
    int c;
    float tab[200][200];
};

void wczytaj(FILE * fin, struct Macierz *m) 
{
    int i,j;

    // fscanf(fin, "%d", &(*m).r);
    // fscanf(fin, "%d", &(*m).c);
    //(*m).c == m->c

    fscanf(fin, "%d", &m->r);
    fscanf(fin, "%d", &m->c);

    for (i=0; i < m->r; i++) 
    {
        for (j=0; j < m->c; j++) 
        {
            fscanf(fin, "%f", &m->tab[i][j]);
        }
    }
}


float norm(struct Macierz m) 
{
    float n = 0;

    for (int w = 0; w < m.r; w++) 
    {
        for (int k=0; k < m.c; k++) 
        {
            n += m.tab[w][k] * m.tab[w][k];
        }
    }
    return sqrt(n);
}

struct Macierz multiply(struct Macierz m, float skalar) 
{
    struct Macierz wynik;
    wynik.r=m.r;
    wynik.c=m.c;

    for (int w = 0; w < m.r; w++) 
    {
        for (int k=0; k < m.c; k++) 
        {
            wynik.tab[w][k] = (m.tab[w][k] * skalar);
        }
    }
    return wynik;
}

// warunek równych kolumn i wierszy
struct Macierz sumuj(struct Macierz a, struct Macierz b) 
{
    struct Macierz suma;
    suma.r=a.r;
    suma.c=a.c;
    
    if ((a.r==b.r) && (a.c==b.c))
    {
        for (int w = 0; w < a.r; w++) 
        {
            for (int k=0; k < a.c; k++) 
            {
                suma.tab[w][k] += a.tab[w][k] + b.tab[w][k];
            }
        
            //printf("\n");
        }
        return suma;
    }
    else
    {
        printf("Dzialanie niemozliwe do wykonania, zle wymiary macierzy!");
    }
}

// warunek równych kolumn i wierszy
struct Macierz odejmij(struct Macierz a, struct Macierz b) 
{
    struct Macierz roznica;
    roznica.r=a.r;
    roznica.c=a.c;

    if ((a.r==b.r) && (a.c==b.c))
    {
        for (int w = 0; w < a.r; w++) 
        {
            for (int k=0; k < a.c; k++) 
            {
                roznica.tab[w][k] += a.tab[w][k] - b.tab[w][k];
            }
            //printf("\n");
        }
        return roznica;
    }
    else
    {
        printf("Dzialanie niemozliwe do wykonania, zle wymiary macierzy!");
    }
}

// warunek liczba kolumn macierzy A jest rowna liczbie wierszy macierzy B
struct Macierz mnozenie(struct Macierz a, struct Macierz b) 
{
    struct Macierz iloczyn;
    iloczyn.r=a.r;
    iloczyn.c=b.c;

    if (a.c == b.r )
    {
    for (int w = 0; w < a.r; w++) 
        {
            for (int k=0; k < b.c; k++) 
            {
                iloczyn.tab[w][k]=0;
                for (int n=0; n < a.c; n++)
                {
                iloczyn.tab[w][k] += a.tab[w][n] * b.tab[n][k];
                }
            }
        }
        return iloczyn;
    }
    else
    {
        printf("Dzialanie niemozliwe do wykonania, zle wymiary macierzy!");
    }
    
}

struct Macierz wypisz(struct Macierz m) 
{
    int i, j;
    printf("[ ");
    for (i = 0; i < m.r; i++) 
    {
        for (j=0; j < m.c; j++) 
        {
            printf("%5.1f ", m.tab[i][j]);
        }
        if (i < (m.r-1))
            printf("\n  ");
    }
    
    printf("]\n");
}


void zapisz(char nazwa[], struct Macierz m)
{
    FILE * fout = fopen(nazwa, "w");
    int i,j;

    fprintf(fout, "%d\n%d\n", m.r, m.c);
    for (i = 0; i < m.r; i++) 
    {
        for (j=0; j < m.c; j++) 
        {
            fprintf(fout, "%f\n", m.tab[i][j]);
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


int main(int argc, char *argv[])
{

    struct Macierz mac1;
    struct Macierz mac2;
    struct Macierz macw;
    
    FILE * fin1;
    FILE * fin2;
    // = fopen(argv[1], "r");

    if ( strcmp( argv[1], "norm") == 0) 
    {
        fin1  = fopen(argv[2], "r");
        wczytaj(fin1, &mac1);

        if (argv[3]!=0)
        {
            zapisz2(argv[3], norm(mac1));
            return 0;
        }

        else 
        printf("Norma macierzy %s = %f\n", argv[1], norm(mac1));

        fclose(fin1);
        
    } 

    else if ( strcmp( argv[1], "multiply") == 0) 
    {
        
        fin1 = fopen(argv[2], "r");

        float k=atof(argv[3]);

        wczytaj(fin1, &mac1);
        macw=multiply(mac1,k);

        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            return 0;
        }
        else  
        wypisz(macw);
    
        fclose(fin1);
        
    } 
    
    else if ( strcmp( argv[1], "sum") == 0) 
    {
        fin1 = fopen(argv[2], "r");
        fin2 = fopen(argv[3], "r");
        wczytaj(fin1, &mac1);
        wczytaj(fin2, &mac2);

        macw=sumuj(mac1,mac2);

        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
        }
        else  
        wypisz(macw);

       
        fclose(fin1);
        fclose(fin2);
    } 


    else if ( strcmp( argv[1], "subtract") == 0) 
    {
        fin1 = fopen(argv[2], "r");
        fin2 = fopen(argv[3], "r");
        wczytaj(fin1, &mac1);
        wczytaj(fin2, &mac2);

        macw=odejmij(mac1,mac2);

        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            return 0;
        }
        else  
        wypisz(macw);
        
        fclose(fin1);
        fclose(fin2);
    } 

    else if ( strcmp( argv[1], "prod") == 0) 
    {
        fin1 = fopen(argv[2], "r");
        fin2 = fopen(argv[3], "r");
        wczytaj(fin1, &mac1);
        wczytaj(fin2, &mac2);

        macw=mnozenie(mac1,mac2);
        
        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            return 0;
        }


        else  
        wypisz(macw);
    
        fclose(fin1);
        fclose(fin2);
    } 

return 0;
}