#include <stdio.h>
#include <stdlib.h>
#include "moto.h"

#define DATOSH 5

int altaMotos(eMoto vec[],int tam, int *pNextId)
{
    system("cls");

    int todoOk=0;
    int indiceLibre;
    int existeLibre= siguienteLibre(vec,tam,&indiceLibre);

    eMoto nuevaMoto;

    int listaCilindrada[5]={50,125,500,600,750};

    if(vec!=NULL&&tam>0&&pNextId!=NULL)
    {
        if(existeLibre)
        {
            printf("indice libre: %d\n",indiceLibre);
            printf("Ingresar marca: ");
            fflush(stdin);
            scanf("%20s",nuevaMoto.marca);
            printf("Se ingreso la marca: %s\n\n",nuevaMoto.marca);

            //listarTipos()
            printf("Ingresar tipo: ");
            nuevaMoto.idTipo=IngresarIntValido(1000,1003);
            printf("Se ingreso el tipo %d\n",nuevaMoto.idTipo);

            //listarColores()
            printf("Ingresar color: ");
            nuevaMoto.idColor=IngresarIntValido(10000,10004);
            printf("Se ingreso el color%d\n",nuevaMoto.idColor);

            //listarCilindrada()
            for(int i=0;i<5;i++)
            {
                printf("%d\t|\t%d\n",i,listaCilindrada[i]);
            }
            printf("Ingresar cilindrada: ");
            nuevaMoto.cilindrada=listaCilindrada[IngresarIntValido(0,4)];
            printf("Se ingreso la cilindrada %d\n",nuevaMoto.cilindrada);

            printf("Ingresar puntaje (0:10): ");
            nuevaMoto.puntaje=IngresarIntValido(0,10);
            printf("Se ingreso el puntaje %d\n",nuevaMoto.puntaje);

            nuevaMoto.id=(*pNextId)++;
            nuevaMoto.isEmpty=0;
            vec[indiceLibre]=nuevaMoto;

            todoOk=1;
        }
        else
        {
            printf("No se encontr� espacio libre en la lista\n");
        }
    }

    system("PAUSE");
    system("cls");
    return todoOk;
}

int siguienteLibre(eMoto vec[], int tam,int *pIndex)
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

int inicializarMotos(eMoto vec[], int tam)
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

int hardcodearMotos(eMoto vec[], int tam, int* pNextId)
{
    int todoOk = 0;
    eMoto motos[DATOSH] =
    {
        //id-marca-idTipo-idColor-cilindrada-puntaje-isEmpty
        {0, "Yamaha", 1000, 10001, 50,1,0},
        {0, "Mitsubishi", 1002, 10002, 500,5,0},
        {0, "Ducati", 1002, 10000, 125,7,0},
        {0, "BMW", 1003, 10002, 750,9,0},
        {0, "Harley Davidson", 1001, 10000, 600,7,0}
    };
    if( vec != NULL && pNextId != NULL && tam > 0 && tam <= 10 && DATOSH <= tam)
    {
        for(int i=0; i < DATOSH; i++)
        {
            vec[i] = motos[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    else
    {
        printf("Error al hardcodear datos iniciales\n");
        system("PAUSE");
    }
    return todoOk;

}

int listarMotos(eMoto vec[], int tam, eTipo tipos[], eColor colores[], int tamTipo, int tamCol)
{
    int todoOk = 0;
    int flag = 1;
    if( vec != NULL && tam > 0)
    {
        ordenarTipos(vec,tam,tipos,tamTipo);
        system("cls");
        printf("       *** Listado de Motos ***\n");
        printf("   id       marca       tipo  color     cilindrada   puntaje\n");
        printf("-----------------------------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                mostrarMotoFila(vec[i], tipos, tamTipo, colores, tamCol);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("     No hay Motos en el sistema\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

void mostrarMotoFila(eMoto moto, eTipo tipo[],int tamT,eColor color[], int tamC)
{

    char descripcionTipo[20];
    char descripcionColor[20];

    cargarDescripcionTipo(tipo, tamT, moto.idTipo, descripcionTipo);
    cargarDescripcionColor(color, tamC, moto.idColor, descripcionColor);


    printf("    %4d    %20s      %10s    %10s    %d   %d\n",
           moto.id,
           moto.marca,
           descripcionTipo,
           descripcionColor,
           moto.cilindrada,
           moto.puntaje
          );
}


int menuMotos()
{

    int opcion;

    system("cls");
    printf("     *** UTN Moto Service ***\n\n");
    printf("1. Alta moto\n");
    printf("2. Modificar moto\n");
    printf("3. Baja moto\n");
    printf("4. Listar motos\n");
    printf("5. Listar tipos\n");
    printf("6. Listar colores\n");
    printf("7. Listar servicios\n");
    printf("8. Alta trabajo\n");
    printf("9. Listar trabajos\n");
    printf("10. Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}


int cargarDescripcionTipo(eTipo tipos[], int tam, int id, char desc[])
{

    int todoOk = 0;
    if(tipos != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( tipos[i].id == id){
                strcpy( desc, tipos[i].descripcion);
                todoOk = 1;
                break;
            }
         }
    }
    return todoOk;
}

int ordenarTipos(eMoto vec[],int cMotos, eTipo tipos[], int cTipo)
{
    int cantMotos=0;

    for(int i=0;i<cMotos;i++)
    {
        if(!vec[i].isEmpty)
        {
            cantMotos++;
        }

    }

    char descripcion[20];
    char descripcionSiguiente[20];

    eMoto aux;

    for(int i=0;i<cantMotos-1;i++)
    {
        if(!vec[i].isEmpty){
            cargarDescripcionTipo(tipos,cTipo,vec[i].idTipo,descripcion);
            for(int j=i+1;j<cantMotos;j++)
            {
                if(!vec[i].isEmpty){
                    cargarDescripcionTipo(tipos,cTipo,vec[j].idTipo,descripcionSiguiente);
                    int comparacion=strcmp(descripcion,descripcionSiguiente);
                    if(comparacion>0)
                    {
                        aux=vec[i];
                        vec[i]=vec[j];
                        vec[j]=aux;

                        cargarDescripcionTipo(tipos,cTipo,vec[i].idTipo,descripcion);
                        cargarDescripcionTipo(tipos,cTipo,vec[j].idTipo,descripcionSiguiente);
                    }
                    else
                    {
                        if(comparacion==0){
                            if(vec[i].id>vec[j].id)
                            {
                                aux=vec[i];
                                vec[i]=vec[j];
                                vec[j]=aux;
                                cargarDescripcionTipo(tipos,cTipo,vec[i].idTipo,descripcion);
                                cargarDescripcionTipo(tipos,cTipo,vec[j].idTipo,descripcionSiguiente);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;

}
