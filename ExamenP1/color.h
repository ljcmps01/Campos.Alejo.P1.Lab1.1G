#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[20];
} eColor;
//gris,negro,azul,blanco,rojo

#endif // COLOR_H_INCLUDED
int cargarDescripcionColor(eColor colores[], int tam, int id, char desc[]);
