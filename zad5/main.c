#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "studenci.h"
#include "dziekanat.h"


int main(int argc, char ** argv) 
{
    student dane[100];
    int ile;
    
    ile = wczytaj(dane);

    if ( strcmp( argv[1], "najlepszy_student") == 0) 
    {
        //wypisz(dane, ile);
        najlepszy_student(dane, ile);
    } 

    else if ( strcmp( argv[1], "przedmiot") == 0) 
    {
        najlepszy_przedmiot(dane, ile);
        najgorszy_przedmiot(dane, ile);
    } 
    
    return 0;
}