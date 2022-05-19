#include <stdio.h>
#include <stdlib.h>

#include "moto.h"
#include "color.h"
#include "fecha.h"
#include "service.h"

#define TAM 10
#define TAMT 4
#define TAMC 5
#define TAMS 4

int main()
{
    char salir = 'n';
    int proximoId = 1000;
    eMoto lista[TAM];
    eTipo tipos[TAMT]=
    {
        {1000, "Enduro" },
        {1001, "Chopera" },
        {1002, "Scooter" },
        {1003, "Vintage" }
    };
    eColor colores[TAMC]=
    {
        {10000, "Gris"},
        {10001, "Negro" },
        {10002, "Azul" },
        {10003, "Blanco" },
        {10004, "Rojo" }
    };

    eServicio servicio[TAMS]=
    {
      {1000,"Limpieza",450},
      {1001,"Ajuste",300},
      {1002,"Balanceo",150},
      {1003,"Cadena",390}
    };

    inicializarMotos(lista, TAM);
    hardcodearMotos(lista, TAM,&proximoId);
    do
    {
        switch(menuMotos())
        {
            case 4:     //Listar motos
                listarMotos(lista,TAM,tipos,colores,TAMT,TAMC);
                break;
            case 10:    //Salir
                salir='s';
                break;

            default:
                printf("Entrada invalida\n");
                system("PAUSE");
            break;
        }
        system("PAUSE");
    }while(salir!='s');

    return 0;
}
