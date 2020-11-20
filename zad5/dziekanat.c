#include "studenci.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void najlepszy_student (student dane[100], int ile_rekordow) 
{
    char nr_albumow[100][10];

    float srednie[100];
    float sumy_wazonych_ocen[100] = {0};
    float najlepsza = 0.0f;

    int sumy_ects[100] = {0};
    int pozycja, ile_studentow, najlepsza_pozycja;


    ile_studentow = znajdz_studentow (nr_albumow, dane, ile_rekordow);

    for (int i=0; i < ile_rekordow; i++) 
    {
        pozycja = znajdz (dane[i].nr_albumu, nr_albumow, ile_studentow );

        sumy_wazonych_ocen[pozycja] += dane[i].ocena * dane[i].ects;
        sumy_ects[pozycja] += dane[i].ects;
    }    

    for (int i=0; i < ile_studentow; i++) 
    {
        printf("Student [%d]: %s - %f:%d - %f \n", i+1, nr_albumow[i], sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    }

    for (int i=0; i < ile_studentow; i++) 
    {
        if (najlepsza < sumy_wazonych_ocen[i] / sumy_ects[i]) 
        {
            najlepsza = sumy_wazonych_ocen[i] / sumy_ects[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepszy student: \n");
    printf("Student [%d]: %s - %f \n", najlepsza_pozycja+1, nr_albumow[najlepsza_pozycja], sumy_wazonych_ocen[najlepsza_pozycja] / sumy_ects[najlepsza_pozycja] );

}

void najgorszy_przedmiot(student dane[100], int ile_rekordow) 

{
    char kod_przed[100][10];
    char nazwa_przed[100][255];

    float srednia[100] = {0};
    float najlepsza = 6.0f;

    int dodawania[100] = {0};
    int pozycja, liczba_przedmiotow, najlepsza_pozycja;
    
    liczba_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (int i=0; i < ile_rekordow; i++) 
    {
        pozycja = znajdzp( dane[i].kod_przed, kod_przed, liczba_przedmiotow );
        strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);

        dodawania[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }   

    for (int i=0; i < liczba_przedmiotow; i++) 
    {
        srednia[i] = srednia[i]/dodawania[i];
    }   
    
    for (int i=0; i < liczba_przedmiotow; i++) 
    {
        if (najlepsza > srednia[i]) 
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najgorsza średnia: ");
    printf("%s - %s: %.2f \n", kod_przed[najlepsza_pozycja], nazwa_przed[najlepsza_pozycja], srednia[najlepsza_pozycja] );

}

void najlepszy_przedmiot(student dane[100], int ile_rekordow) 
{
    char kod_przed[100][10];
    char nazwa_przed[100][255];

    float srednia[100] = {0};
    float najlepsza = 0.0f;
    
    int dodawania[100] = {0};
    int pozycja, liczba_przedmiotow, najlepsza_pozycja;

    liczba_przedmiotow = znajdz_przedmioty(kod_przed, dane, ile_rekordow);

    for (int i=0; i < ile_rekordow; i++) 
    {
        pozycja = znajdzp( dane[i].kod_przed, kod_przed, liczba_przedmiotow );
        strcpy(nazwa_przed[pozycja],dane[i].nazwa_przed);

        dodawania[pozycja]++;
        srednia[pozycja] += dane[i].ocena;
    }   

    for (int i=0; i < liczba_przedmiotow; i++) 
    {
        srednia[i] = srednia[i]/dodawania[i];
    }   

    for (int i=0; i < liczba_przedmiotow; i++) 
    {
        if (najlepsza < srednia[i]) 
        {
            najlepsza = srednia[i];
            najlepsza_pozycja = i;
        }
    }

    printf("Najlepsza średnia: ");
    printf("%s - %s: %.2f \n", kod_przed[najlepsza_pozycja], nazwa_przed[najlepsza_pozycja], srednia[najlepsza_pozycja] );

}