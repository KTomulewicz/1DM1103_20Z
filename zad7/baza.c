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

        s = strtok(NULL, "\n");
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
        Ocena *ocen = (Ocena*) malloc(sizeof(Ocena));
        ocen->nast = NULL;

        if (last_ocena == NULL)
        {
            glowa = ocen;
        }
        else
            last_ocena->nast = ocen;
        last_ocena = ocen;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        ocen->kod_przed = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->kod_przed, s);

        s = strtok(NULL, "\n");
        ocen->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(ocen->nr_albumu, s);

        s = strtok(NULL, ";");
    
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
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
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

void zapisz_baze(char *nazwa, SBaza * baza) 
{
    int n=ile_studentow(baza);
    int m=ile_przedmiotow(baza);
    int r=ile_ocen(baza);

    FILE *fin = fopen (nazwa, "w+");
    Student *student = baza->lista_studentow;
    Przedmiot *przedmiot = baza->lista_przedmiotow;
    Ocena *ocen= baza->lista_ocen;

    
    fprintf(fin,"%d\n",n);
    while (student!=NULL)
    {
        fprintf (fin,"%s;%s;%s;%s\n", student->imie, student->nazwisko, student->nr_albumu, student->email);
        student=student->nast;
    }

    fprintf(fin,"%d\n",m);
    while (przedmiot!=NULL)
    {
        fprintf (fin,"%s;%s;%s\n", przedmiot->kod_przed, przedmiot->nazwa_przed, przedmiot->sem);
        przedmiot=przedmiot->nast;
    }
   

    fprintf(fin,"%d\n",r);
    for (int i=0; i<r; i++)
    {
        fprintf (fin,"%s;%s\n", ocen->kod_przed, ocen->nr_albumu);
        ocen=ocen->nast;
    }
    

    fclose(fin);

}

void dodaj_studentow (SBaza *baza, char *imie, char *nazwisko, char *nr_albumu, char *email)
{
    Student *nowy = (Student*) malloc(sizeof(Student));
  	Student *aktualnie = NULL;

  	nowy->nast = NULL;
    
  	nowy->imie = (char*) malloc(sizeof(char) * (strlen(imie) + 1));
    strcpy(nowy->imie, imie);

    nowy->nazwisko = (char*) malloc(sizeof(char) * (strlen(nazwisko) + 1));
    strcpy(nowy->nazwisko, nazwisko);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    nowy->email = (char*) malloc(sizeof(char) * (strlen(email) + 1));
    strcpy(nowy->email, email);

    aktualnie=baza->lista_studentow;
    
    if(ile_studentow(baza) == 0)
    {
      baza->lista_studentow = nowy;
    }

    else
    {
      for(int i=1; i < ile_studentow(baza); i++)
      {
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }
        
}

void dodaj_przedmiot (SBaza *baza, char *kod_przed, char *nazwa_przed, char *sem)
{
    Przedmiot *nowy = (Przedmiot*) malloc(sizeof(Przedmiot));

    Przedmiot *aktualnie = NULL;

  	nowy->nast = NULL;

  	nowy->kod_przed = (char*) malloc(sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);

    nowy->nazwa_przed = (char *)malloc(sizeof(char) * (strlen(nazwa_przed) + 1));
    strcpy(nowy->nazwa_przed, nazwa_przed);

    nowy->sem = (char*) malloc(sizeof(char) * (strlen(sem) + 1));
    strcpy(nowy->sem, sem);

    aktualnie = baza->lista_przedmiotow;
    
    if(ile_przedmiotow(baza) == 0)
    {
      baza->lista_przedmiotow = nowy;
    }

    else
    {
      for(int i=1; i<ile_przedmiotow(baza); i++)
      {
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }    
}

void dodaj_oceny (SBaza *baza, char *kod_przed, char *nr_albumu)
{
    Ocena *nowy = (Ocena*) malloc(sizeof(Ocena));

    Ocena *aktualnie = NULL;
    
  	nowy->nast = NULL;
    
  	nowy->kod_przed = (char*) malloc(sizeof(char) * (strlen(kod_przed) + 1));
    strcpy(nowy->kod_przed, kod_przed);

    nowy->nr_albumu = (char*) malloc(sizeof(char) * (strlen(nr_albumu) + 1));
    strcpy(nowy->nr_albumu, nr_albumu);

    aktualnie=baza->lista_ocen;
    
    if(ile_ocen(baza) == 0)
    {
      baza->lista_ocen = nowy;
    }

    else
    {
      for(int i=1; i<ile_ocen(baza); i++)
      {
        aktualnie = aktualnie->nast;
      }
      aktualnie->nast = nowy;
    }
        
    
}

void listuj_studentow(SBaza *baza) 
{

    Student * stud = baza->lista_studentow;

    printf("%d\n", ile_studentow(baza));
    while (stud != NULL) 
    {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void listuj_przedmiot(SBaza *baza) 
{

    Przedmiot * przed = baza->lista_przedmiotow;

    printf("%d\n", ile_przedmiotow(baza));
    while (przed != NULL) 
    {
        printf("%s %s %s \n", przed->kod_przed, przed->nazwa_przed, przed->sem);
        przed = przed->nast;
    }
}

void listuj_oceny(SBaza *baza) 
{

    Ocena * ocen = baza->lista_ocen;

    printf("%d\n", ile_ocen(baza));
    while (ocen != NULL) 
    {
        printf("%s %s \n", ocen->kod_przed, ocen->nr_albumu);
        ocen = ocen->nast;
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