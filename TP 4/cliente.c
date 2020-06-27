#include "cliente.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

eCliente* newCliente()
{
    eCliente* cliente;
    cliente = (eCliente*) malloc(sizeof(eCliente));
    return cliente;
}

eCliente* newClienteParametrizado(char* id,char* nombre,char* localidad)
{
    eCliente* cliente;
    cliente = newCliente();
    if(cliente != NULL)
    {
        cliente->id = atoi(id);
        strcpy(cliente->nombre,nombre);
        strcpy(cliente->localidad,localidad);
    }
    return cliente;
}

int cliente_setId(eCliente* cliente,int id)
{
    int ret = -1;
    if(cliente != NULL)
    {
        cliente->id = id;
        ret = 0;
    }
    return ret;
}

int cliente_getId(eCliente* cliente,int* id)
{
    int ret = -1;
    if(cliente != NULL)
    {
        *id = cliente->id;
        ret = 0;
    }
    return ret;
}

int cliente_setNombre(eCliente* cliente,char* nombre)
{
    int ret = -1;
    if(cliente != NULL)
    {
        strcpy(cliente->nombre,nombre);
        ret = 0;
    }
    return ret;
}

int cliente_getNombre(eCliente* cliente,char* nombre)
{
    int ret = -1;
    if(cliente != NULL)
    {
        strcpy(nombre,cliente->nombre);
        ret = 0;
    }
    return ret;
}
int cliente_setLocalidad(eCliente* cliente,char* localidad)
{
    int ret = -1;
    if(cliente != NULL)
    {
        strcpy(cliente->localidad,localidad);
        ret = 0;
    }
    return ret;
}

int cliente_getLocalidad(eCliente* cliente,char* localidad)
{
    int ret = -1;
    if(cliente != NULL)
    {
        strcpy(localidad,cliente->localidad);
        ret = 0;
    }
    return ret;
}

int cliente_compareById(void* cliente1,void* cliente2)
{
    int ret = 0;
    int id1;
    int id2;

    cliente1 = (eCliente*)cliente1;
    cliente2 = (eCliente*)cliente2;

    if(cliente1 != NULL && cliente2 != NULL)
    {
        cliente_getId(cliente1,&id1);
        cliente_getId(cliente2,&id2);
        if(id1>id2)
        {
            ret = 1;
        }
        else if(id1<id2)
        {
            ret = -1;
        }
    }
    return ret;
}

int cliente_compareByName(void* cliente1,void* cliente2)
{
    char nombre1[51];
    char nombre2[51];
    int ret = 0;

    cliente1 = (eCliente*)cliente1;
    cliente2 = (eCliente*)cliente2;

    if(cliente1 != NULL && cliente2 != NULL)
    {
        cliente_getNombre(cliente1,nombre1);
        cliente_getNombre(cliente2,nombre2);
        ret = strcmp(nombre1,nombre2);
    }
    return ret;
}

void cliente_imprimir(eCliente* cliente)
{
    if(cliente != NULL)
    {
         printf("%4d %13s %13s\n",cliente->id,cliente->nombre,cliente->localidad);
    }

}

