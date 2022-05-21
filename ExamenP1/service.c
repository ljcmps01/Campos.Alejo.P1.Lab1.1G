#include <stdio.h>
#include <stdlib.h>
#include "service.h"


int inicializarTrabajos(eTrabajo vec[], int tam)
{
    int todoOk = 0;
    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaTrabajo(eTrabajo vec[],int tam, int *pNextId, eMoto vMoto[], int tamM, eServicio vServicio[], int tamS)
{
    system("cls");

    int todoOk=0;
    int indiceLibre;
    int existeLibre= siguienteTrabajoLibre(vec,tam,&indiceLibre);

    int id;
    int checkId;

    eTrabajo nuevoTrabajo;


    if(vec!=NULL&&tam>0&&pNextId!=NULL)
    {
        if(existeLibre)
        {
            printf("indice libre: %d\n",indiceLibre);

            listarMotosSimple(vMoto,tamM);
            printf("Ingresar ID de la moto a laborar: ");
            do
            {
                id=IngresarIntValido(0,9999);
                checkId=buscarId(vMoto,tamM,id); //retornar indice o -1 en caso de no encontrar match
            }while(checkId<0);
            nuevoTrabajo.idMoto=id;


            //listarServicios()

            //IngresarFecha()

            nuevoTrabajo.id=(*pNextId)++;
            nuevoTrabajo.isEmpty=0;
            vec[indiceLibre]=nuevoTrabajo;

            todoOk=1;
        }
        else
        {
            printf("No se encontró espacio libre en la lista\n");
        }
    }

    system("PAUSE");
    system("cls");
    return todoOk;
}

int siguienteTrabajoLibre(eTrabajo vec[], int tam,int *pIndex)
{
    int todoOk=0;

    if(vec!=NULL&&tam>0&&pIndex!=NULL)
    {
        *pIndex=-1;
        for(int i=0;i<tam;i++)
        {
            if(vec[i].isEmpty)
            {
                *pIndex=i;
                todoOk=1;
                break;
            }
        }
    }
    return todoOk;
}
