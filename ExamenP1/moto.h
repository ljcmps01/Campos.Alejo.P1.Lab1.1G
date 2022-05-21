#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED

#include "fecha.h"
#include "color.h"
#include "utilidades.h"

#include <string.h>

typedef struct
{
    int id;
    char marca[20];
    int idTipo;     //Validar
    int idColor;    //*VALIDAR*
    int cilindrada;
    int puntaje;    //1:10
    int isEmpty;
}eMoto;

typedef struct
{
    int id;
    char descripcion[20];
}eTipo;

#endif // MOTO_H_INCLUDED


int inicializarMotos(eMoto vec[], int tam);
int hardcodearMotos(eMoto vec[], int tam, int* pNextId);

int altaMotos(eMoto vec[],int tam, int *pNextId, eTipo vTipo[], int tamT, eColor vColor[], int tamC);
int siguienteMotoLibre(eMoto vec[], int tam,int *pIndex);
int listarTipos(eTipo vTipo[],int tam);

int modificarMoto(eMoto vec[],int tam, int *pNextId, eTipo vTipo[], int tamT, eColor vColor[], int tamC);
int buscarId(eMoto vMotos[], int tam, int id);
int subMenuModificar();

int bajaMoto(eMoto vec[],int tam, int *pNextId, eTipo vTipo[], int tamT, eColor vColor[], int tamC);

int listarMotos(eMoto vec[], int tam, eTipo tipos[], eColor colores[], int tamTipo, int tamCol);
int listarMotosSimple(eMoto vec[], int tam);
void mostrarMotoFila(eMoto moto, eTipo tipo[],int tamT,eColor color[], int tamC);
int ordenarTipos(eMoto vec[],int cMotos, eTipo tipos[], int cTipo);

int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char desc[]);
int menuMotos();
