#ifndef SERVICE_H_INCLUDED
#define SERVICE_H_INCLUDED

#include "fecha.h"
#include "moto.h"


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
    int isEmpty;
}eTrabajo;


#endif // SERVICE_H_INCLUDED
int inicializarTrabajos(eTrabajo vec[], int tam);

int altaTrabajo(eTrabajo vec[],int tam, int *pNextId, eMoto vMoto[], int tamM, eServicio vServicio[], int tamS);
int siguienteTrabajoLibre(eTrabajo vec[], int tam,int *pIndex);
