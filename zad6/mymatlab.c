#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wczytywanie.h"
#include "operacje.h"


int main(int argc, char *argv[])
{

    struct Macierz *mac1;
    struct Macierz *mac2;
    struct Macierz *macw;
    
    
    // = fopen(argv[1], "r");

    if ( strcmp( argv[1], "norm") == 0) 
    {
        mac1=wczytaj(argv[2]);

        if (argv[3]!=0)
        {
            zapisz2(argv[3], norm(mac1));
            return 0;
            zwolnij(mac1);
        
        }
        else 
        printf("Norma macierzy %s = %f\n", argv[1], norm(mac1));
        zwolnij(mac1);
        
        
    } 

    else if ( strcmp( argv[1], "multiply") == 0) 
    {
        

        float k=atof(argv[3]);

        mac1=wczytaj(argv[2]);
        macw=multiply(mac1,k);

        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            zwolnij(macw);
            zwolnij(mac1);
            return 0;
        }
        
        else  
        wypisz(macw);
        zwolnij(macw);
        zwolnij(mac1);
        
        
        
    } 
   
    else if ( strcmp( argv[1], "sum") == 0) 
    {
        mac1=wczytaj(argv[2]);
        mac2=wczytaj(argv[3]);

        macw=sumuj(mac1,mac2);

        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            zwolnij(macw);
            zwolnij(mac1);
            zwolnij(mac2); 
            return 0;
        }
        else  
        wypisz(macw);
        zwolnij(mac1);
        zwolnij(mac2);


    } 


    else if ( strcmp( argv[1], "subtract") == 0) 
    {
        
        mac1=wczytaj(argv[2]);
        mac2=wczytaj(argv[3]);

        macw=odejmij(mac1,mac2);

        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            zwolnij(macw);
            zwolnij(mac1);
            zwolnij(mac2); 
            return 0;
        }
        else  
        wypisz(macw);
        zwolnij(macw);
        zwolnij(mac1);
        zwolnij(mac2); 
        
        
    } 

    else if ( strcmp( argv[1], "prod") == 0) 
    {
        
        mac1=wczytaj(argv[2]);
        mac2=wczytaj(argv[3]);

        macw=mnozenie(mac1,mac2);
        
        if (argv[4]!=0)
        {
            zapisz(argv[4], macw);
            zwolnij(macw);
            zwolnij(mac1);
            zwolnij(mac2); 
            return 0;
        }

        else  
        wypisz(macw);
        zwolnij(macw);
        zwolnij(mac1);
        zwolnij(mac2);    
    } 

return 0;
}