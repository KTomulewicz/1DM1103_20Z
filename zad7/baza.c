#include "baza.h"

Student * wczytaj_studentow(FILE *fin) 
{
    char bufor[255];
    int n;
    char *s;

    Student *last_student = NULL;
    Student *glowa = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (int i=0; i < n; i++) 
    {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Przedmiot * wczytaj_przedmioty(FILE *fin) 
{
    char bufor[255];
    int n;
    char *s;

    Przedmiot *last_subject = NULL;
    Przedmiot *glowa = NULL;

    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (int i=0; i < n; i++) 
    {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if (last_subject == NULL)
        {
            glowa = przed;
        }
        else
            last_subject->nast = przed;
        last_subject = przed;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        przed->kod_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->kod_przed, s);

        s = strtok(NULL, ";");
        przed->nazwa_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->nazwa_przed, s);

        s = strtok(NULL, ";");
        przed->sem = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(przed->sem, s);
    }

    return glowa;
}

Ocena * wczytaj_oceny(FILE *fin) 
{
    char bufor[255];
    int n;
    char *s;
    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (int i=0; i < n; i++) 
    {
        Ocena *ocena = (Ocena*) malloc(sizeof(Ocena));
        ocena->nast = NULL;

        if (last_ocena == NULL)
        {
            glowa = ocena;
        }
        else
            last_ocena->nast = ocena;
        last_ocena = ocena;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        ocena->kod_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocena->kod_przed, s);

        s = strtok(NULL, ";");
        ocena->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocena->nr_albumu, s);
    }

    return glowa;
}

SBaza * wczytaj_baze(char *nazwa) 
{

    FILE *fin = fopen(nazwa, "r");
    if (fin == NULL) 
    {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza-> lista_przedmiotow = wczytaj_przedmioty(fin);
    baza -> lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

SBaza * zapisz_baze(char *nazwa, SBaza * baza) 
{
    FILE *fin = fopen (nazwa, "w+");
        fprintf(fin, "%d\n", ile_studentow(baza));
        Student *student = baza->lista_studentow;
        Przedmiot *przedmiot = baza->lista_przedmiotow;
        Ocena *ocena= baza->lista_ocen;
    
    
    for (int i=0; i < ile_studentow(baza); i++)
    {
        fprintf (fin, "%s;%s;%s;%s\n", student->imie, student->nazwisko, student->nr_albumu, student->email);
        student=student->nast;
    }
     fprintf(fin, "%d\n", ile_przedmiotow(baza));
    
    for (int a=0; a < ile_przedmiotow(baza); a++)
    {
        fprintf (fin, "%s;%s;%s\n", przedmiot->kod_przed, przedmiot->nazwa_przed, przedmiot->sem);
        przedmiot=przedmiot->nast;
    }
   

    fprintf(fin, "%d\n", ile_ocen(baza));
    for (int j=0; j < ile_ocen(baza); j++)
    {
        fprintf (fin, "%s;%s\n", ocena->kod_przed, ocena->nr_albumu);
        ocena=ocena->nast;
    }
    

    fclose(fin);

    return NULL;
}

SBaza * dodaj_studentow (SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    Student *nowy = (Student*) malloc(sizeof(Student));
    Student *aktualny = NULL;

    nowy->nast = NULL;

    nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);

    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);

    nowy->nr_albumu= (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);

    aktualny=baza->lista_studentow;

    if(ile_studentow(baza) == 0)
    {
        baza->lista_studentow = nowy;
    }
    else
    {
        for (int i=1; i<ile_studentow(baza); i++)
        {
            aktualny = aktualny->nast;
        }
        aktualny->nast = nowy;
    }

    return NULL;

}

void dodaj_przedmiot (SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem)
{
    Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));
    Przedmiot *aktualny = NULL;

    nowy->nast = NULL;

    nowy->kod_przed = (char*) malloc(sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);

    nowy->nazwa_przed = (char*) malloc(sizeof(char) * (strlen(nazwa_przed ) + 1));
    strcpy(nowy->nazwa_przed , nazwa_przed );

    nowy->sem = (char*) malloc(sizeof(char) * (strlen(sem ) + 1));
    strcpy(nowy->sem , sem );

    aktualny=baza->lista_przedmiotow;

    if(ile_przedmiotow(baza) == 0)
    {
        baza->lista_przedmiotow = nowy;
    }
    else
    {
        for (int i=1; i<ile_przedmiotow(baza); i++)
        {
            aktualny = aktualny->nast;
        }
        aktualny->nast = nowy;
    }

}

SBaza * dodaj_oceny (SBaza *baza, char *kod_przed, char *nr_albumu)
{
    Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));
    Ocena *aktualny = NULL;

    nowy->nast = NULL;

    nowy->kod_przed = (char*) malloc(sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);


    aktualny=baza->lista_ocen;

    if(ile_ocen(baza) == 0)
    {
        baza->lista_ocen = nowy;
    }
    else
    {
        for (int i=1; i<ile_ocen(baza); i++)
        {
            aktualny = aktualny->nast;
        }
        aktualny->nast = nowy;
    }

    return NULL;

}

int ile_studentow(SBaza *baza) 
{
    int n = 0;
    Student * student = baza->lista_studentow;
    while (student != NULL) 
    {
        n++;
        student = student->nast;
    }
    return n;
}

int ile_przedmiotow(SBaza *baza)
{
    int n = 0;
    Przedmiot * przedmiot = baza->lista_przedmiotow;
    while (przedmiot !=NULL)
    {
        n++;
        przedmiot = przedmiot->nast;
    }
    return n;
}

int ile_ocen (SBaza *baza)
{
    int n=0;
    Ocena * ocena = baza->lista_ocen;
    while (ocena != NULL)
    {
        n++;
        ocena = ocena->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) 
{

    Student * stud = baza->lista_studentow;
    while (stud != NULL) 
    {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void zwolnij_student(Student *s) 
{
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_przedmioty(Przedmiot *s) 
{
    free(s->kod_przed);
    free(s->nazwa_przed);
    free(s->sem);
    free(s);
}

void zwolnij_oceny(Ocena *s) 
{
    free(s->kod_przed);
    free(s->nr_albumu);
    free(s);
}

void zwolnij_liste_studentow(Student *s) 
{
    Student *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij_liste_przedmiotow(Przedmiot *s) 
{
    Przedmiot *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_przedmioty(s);
        s = n;
    }
}

void zwolnij_liste_ocen(Ocena *s) 
{
    Ocena *n;
    while (s != NULL) 
    {
        n = s->nast;
        zwolnij_oceny(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) 
{
    zwolnij_liste_studentow(baza->lista_studentow);
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    zwolnij_liste_ocen(baza->lista_ocen);
    free(baza);
}