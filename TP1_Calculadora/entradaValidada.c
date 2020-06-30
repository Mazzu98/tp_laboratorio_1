#include "entradaValidada.h"

int getInt(char text[])
{
    char num[11];
    do{
        puts(text);
        fflush(stdin);
        gets(num);

    }while(!validarInt(num));

    return atoi(num);
}

int validarInt(char string[])
{
    int i,validacion = 1;
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<48 || string[i]>57)
        {
            validacion = 0;
            break;
        }
    }
    if(validacion == 0)
    {
            printf("\nError: debe ingresar un numero entero\n\n");
    }
    return validacion;
}

void getOLString(char text[],char string[])
{
    do{
        fflush(stdin);
        puts(text);
        gets(string);
    }while(!validarOLString(string));

}
int validarOLString(char string[])
{
    int i,validacion = 1;
    strlwr(string);
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<97 || string[i]>122)
        {
            validacion = 0;
            break;
        }
    }
    if(validacion == 0)
    {
        printf("\nError: este campo debe poseer solo letras, intente de nuevo...\n\n");
    }
    return validacion;
}

float getFloat(char text[])
{
    char string[20];
    float num;
    do{
        puts(text);
        fflush(stdin);
        gets(string);
    }while(!validacionFloat(string));

    num = atof(string);
    return num;
}

int validacionFloat(char string[])
{
    int i,puntosCont = 0, validacion = 1;
    for(i=0;i<strlen(string);i++)
    {
        if(string[i] == '.')
        {
            puntosCont++;
        }
        else if(string[i] < 48 || string[i] > 57)
        {
            validacion = 0;
            break;
        }
    }
    if(puntosCont>1)
    {
        validacion = 0;
    }
    if(validacion == 0)
    {
        printf("\nError: debe ingresar el valor decimal correctamente\n\n");
    }
    return validacion;
}

void getString(char text[],char string[])
{
        fflush(stdin);
        puts(text);
        gets(string);
}
