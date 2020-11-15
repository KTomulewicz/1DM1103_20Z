/**
Mamy mini bazÄ™ studentĂłw (tabelÄ™ z studentami, przedmiotami i ocenami)
Cel: obliczyÄ‡ ranking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student 
{
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod[10];
    char nazwa[255];
    float ocena;
    int ects;

} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) 
{
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++)
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
        strncpy(dane[i].kod, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}



int znajdz (char *szukanynr, char kod[100][10], int n) 
{
    
    for (int i=0; i < n; i++) 
    {
        if (strcmp(szukanynr, kod[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty (char kod[100][10], student dane[100], int n) 
{
    int znalezione = 0;

    for (int i=0; i < n; i++) 
    {
        if (znajdz(dane[i].kod, kod, znalezione ) == -1)
        {
            strncpy(kod[znalezione], dane[i].kod, 9);
            znalezione++;
        }
    }
    return znalezione;
}

void najlepszy_przedmiot(student dane[100], int rekordy) 
{
    char kod[100][10];
    char nazwa[100][255];
    
    float srednia[100] = {0};
    int dodawania[100] = {0};

    int pozycja, najlepsza_pozycja, przedmioty;
    float najlepsza = 0.0f;


    przedmioty = znajdz_przedmioty(kod, dane, rekordy);

    for (int i=0; i < rekordy; i++)
    {
        pozycja = znajdz( dane[i].kod, kod, przedmioty );
    
        strcpy(nazwa[pozycja], dane[i].nazwa);
        dodawania[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
        
    }    

    for (int i=0; i < przedmioty; i++)
    {
        srednia[i] = srednia[i] / dodawania[i];
    } 
        

    for (int i=0; i < przedmioty; i++)
    {
        if (najlepsza < srednia[i])
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepsza srednia: ");
    printf("%s - %s: %.2f \n", kod[najlepsza_pozycja], nazwa[najlepsza_pozycja], srednia[najlepsza_pozycja]);

}


void najgorszy_przedmiot(student dane[100], int rekordy) 
{
    char kod[100][10];
    char nazwa[100][255];

    float srednia[100] = {0};
    int dodawania[100] = {0};
    
    int pozycja, najgorsza_pozycja, przedmioty;
    float najgorsza = 6.0f;


    przedmioty = znajdz_przedmioty(kod, dane, rekordy);

    for (int i=0; i < rekordy; i++)
    {
        pozycja = znajdz( dane[i].kod, kod, przedmioty );
    
        strcpy(nazwa[pozycja], dane[i].nazwa);
        
        dodawania[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }    

    for (int i=0; i < przedmioty; i++)
    {
        srednia[i] = srednia[i] / dodawania[i];
    } 
        

    for (int i=0; i < przedmioty; i++)
    {
        if (najgorsza > srednia[i])
        {
            najgorsza = srednia[i];
            najgorsza_pozycja = i;
        }
    }

    printf("Najgorsza srednia: ");
    printf("%s - %s: %.2f \n", kod[najgorsza_pozycja], nazwa[najgorsza_pozycja], srednia[najgorsza_pozycja]);

}




int main(int argc, char ** argv)
{
    student t[100];
    int a;

    a = wczytaj(t, argv[1]);
    
    najlepszy_przedmiot(t, a);
    najgorszy_przedmiot(t, a);
    

    return 0;
}