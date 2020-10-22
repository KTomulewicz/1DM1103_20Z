#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{

    
    float v;
    float a;    


    a=atof(argv[1]);
    
    
    v=a*a;


    printf("Wartość %1.0f do kwadratu to %1.0f.\n", a, v);
    
    //jedyne czego nie wiedziałem to czy nadal ma mi wypisać w formie liczby zmienno-przecinkowej np "2.00000" czy po prostu jako 2


    return 0;
}
