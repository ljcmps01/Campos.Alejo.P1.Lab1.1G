#include "fecha.h"

#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

typedef struct
{
    int id;         //Desde 20000
    char descripcion[25];
    int precio; //(Limpieza: $450, Ajuste: $300, Balanceo: $150, Cadena: $390)
}eServicio;

typedef struct
{
    int id;         //autoincremental
    int idMoto;     //Validar existencia
    int idServicio; //Validar existencia
    eFecha fecha;      //Validar dia mes y año
}eTrabajo;


#endif // SERVICE_H_INCLUDED
