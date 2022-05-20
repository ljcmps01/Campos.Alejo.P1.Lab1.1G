#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

int IngresarIntValido(int min,int max)
{
    int num;
    int check=EOF;
    if(num!=NULL)
    {

        fflush(stdin);
        check=scanf("%d",&num);
        fflush(stdin);
        while(check==EOF||num<min||num>max)
        {
            printf("Ingreso no valido, ingresar opcion valida\n");
            fflush(stdin);
            check=scanf("%d",&num);
        }
    }
    return num;
}
