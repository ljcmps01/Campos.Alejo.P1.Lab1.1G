#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

#include <string.h>

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;
//gris,negro,azul,blanco,rojo

#endif // COLOR_H_INCLUDED
int listarColores(eColor vColor[],int tam);
int cargarDescripcionColor(eColor colores[], int tam, int id, char desc[]);

