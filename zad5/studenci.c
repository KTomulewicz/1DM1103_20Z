#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;

} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) 

{
    FILE * fin = fopen(fnazwa, "r");
    int cnt;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (int i=0; i<cnt; i++) 
    {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

void wypisz (student dane[100], int n) 
{
    for (int i=0; i < n; i++) 
    {
        printf("{ Student: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymal‚ %.1f\n", dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko, dane[i].kod_przed, dane[i].nazwa_przed, dane[i].ects, dane[i].ocena );
    }
}

int znajdz (char *szukany_nr, char nr_albumow[100][10], int n) 
{
    for (int i=0; i < n; i++) 
    {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int znajdz_studentow (char nr_albumow[100][10], student dane[100], int n) 
{
    int znalezione = 0;
    
    for (int i=0; i < n; i++) 
    {
        if (znajdz(dane[i].nr_albumu, nr_albumow, znalezione) == -1) 
        {
            strncpy(nr_albumow[znalezione], dane[i].nr_albumu, 9);
            znalezione++;
        }
    }
    return znalezione;
}

int znajdzp(char *szukany_nr, char kod_przed[100][10], int n) 
{
    for (int i=0; i<n; i++) 
    {
        if (strcmp(szukany_nr, kod_przed[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int znajdz_przedmioty(char kod_przed[100][10], student dane[100], int n) 
{
    int znalezione=0;

    for (int i=0; i <n; i++)
    {
        if (znajdzp(dane[i].kod_przed, kod_przed, znalezione) == -1) 
        {
            strncpy(kod_przed[znalezione], dane[i].kod_przed, 9);
            znalezione++;
        }
    }
    return znalezione;
}