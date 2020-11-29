#ifndef operacje_h
#define operacje_h

float norm(struct Macierz *m);

struct Macierz* sumuj(struct Macierz *a, struct Macierz *b); 

struct Macierz* odejmij(struct Macierz *a, struct Macierz *b); 

struct Macierz* mnozenie(struct Macierz *a, struct Macierz *b);

struct Macierz* multiply(struct Macierz *m, float skalar);

#endif