#include "fecha.h"

int validarAnio(int anio)
{
    if(anio>0)
    {
        return 1;
    }
    return 0;
}

int validarMes(int mes)
{
    if(mes>0 && mes<=12)
    {
       return 1;
    }
    return 0;
}

int validarDia(int dia)
{
    if(dia>0 && dia <=31){
        return 1;
    }
    return 0;
}

