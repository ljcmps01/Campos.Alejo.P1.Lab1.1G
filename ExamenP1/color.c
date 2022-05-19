#include <stdio.h>
#include <stdlib.h>
#include "color.h"

int cargarDescripcionColor(eColor colores[], int tam, int id, char desc[])
{

    int todoOk = 0;
    if(colores != NULL && tam > 0 && desc != NULL){

         for(int i= 0; i < tam; i++){

            if( colores[i].id == id){
                strcpy( desc, colores[i].nombreColor);
                todoOk = 1;
                break;
            }
         }
    }
    return todoOk;
}
