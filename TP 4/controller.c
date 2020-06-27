#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "parser.h"
#include "entradaValidada.h"
#include "controller.h"

void printMenu()
{
    printf("1. Leer archivo binario\n");
    printf("2. Alta cliente\n");
    printf("3. Modificar cliente\n");
    printf("4. Baja cliente\n");
    printf("5. Insertar cliente\n");
    printf("6. Mostrar lista\n");
    printf("7. Ordenar lista\n");
    printf("8. Guardar en archivo binario\n");
    printf("9. Clonar lista\n");
    printf("10. Verificar clonacion\n");
    printf("11. Eliminar lista\n");
    printf("12. Salir\n");
}

int controller_leerArchivoBin(LinkedList* lista,char* path)
{
    FILE* pArchivo;
    int ret = 1;
    if(lista != NULL)
    {
        pArchivo = fopen(path,"rb");
        ret = parser_fromBin(lista,pArchivo);
        fclose(pArchivo);
    }
    return ret;
}
int controller_altaCliente(LinkedList* lista,int* newId)
{
    eCliente* cliente;
    char nombre[51];
    char localidad[51];
    int ret = 1;
    if(lista != NULL)
    {
        cliente = newCliente();
        if(cliente != NULL)
        {
            (*newId) = (*newId) + 1;
            cliente_setId(cliente,*newId);
            getString("Ingresar nombre: ",nombre);
            cliente_setNombre(cliente,nombre);
            getString("Ingresar localidad: ",localidad);
            cliente_setLocalidad(cliente,localidad);
            ret = ll_add(lista,cliente);
        }
    }
    return ret;
}

int controller_modificarCliente(LinkedList* lista)
{
    int id;
    int index;
    int ret = 1;
    int opcion;
    char nombre[51];
    char localidad[51];
    eCliente* cliente;
    if(lista != NULL)
    {
        id = getInt("Ingreese ID de el cliente a modificar: ");
        index = controller_findById(lista,id);
        if(index != -1)
        {
            cliente = ll_get(lista,index);
            opcion = getInt("1. Modificar nombre\n2. Modificar localidad\n");
            switch(opcion)
            {
                case 1: getString("Ingrese nuevo nombre: ",nombre);
                        cliente_setNombre(cliente,nombre);
                        break;
                case 2: getString("Ingrese nueva localidad: ",localidad);
                        cliente_setLocalidad(cliente,localidad);
                        break;
                default:
                        break;
            }
            ret = 0;
        }
    }
    return ret;
}

int controller_bajaCliente(LinkedList* lista)
{
    int ret = 1;
    int id;
    int index;
    eCliente* cliente;
    if(lista != NULL)
    {
        id = getInt("Ingrese el id de el cliente a eliminar:");
        index = controller_findById(lista,id);
        if(index != -1)
        {
            cliente = ll_pop(lista,index);
            cliente_imprimir(cliente);
            printf("Eliminado\n\n");
            ret = 0;
        }
    }
    return ret;
}

void controller_mostrarLista(LinkedList* lista)
{
    int i;
    eCliente* cliente;

    if(lista != NULL)
    {
        printf("  id       Nombre      Localidad\n");
        for(i=0;i<ll_len(lista);i++)
        {
            cliente = ll_get(lista,i);
            cliente_imprimir(cliente);
        }
    }
}

int controller_sortCliente(LinkedList* lista)
{
    int ret = 1;
    int opcion;
    printf("Ordenar:\n1. Por nombre\n2. Por id\n");
    do
    {
        opcion = getInt("Ingresar opcion:");
        if(opcion == 1)
        {
            printf("Ordenar:\n1. A-Z\n2. Z-A\n");
            opcion = getInt("Ingresar opcion:");
            if(opcion == 1)
            {
                printf("Ordenando...");
                ll_sort(lista,&cliente_compareByName,1);
            }
            else if (opcion == 2)
            {
                printf("Ordenando...");
                ll_sort(lista,&cliente_compareByName,0);
            }
        }
        else if (opcion == 2)
        {
            printf("Ordenar:\n1. Acendente\n2. Decendente\n");
            opcion = getInt("Ingresar opcion:");
            if(opcion == 1)
            {
                printf("Ordenando...");
                ll_sort(lista,&cliente_compareById,1);
            }
            else if (opcion == 2)
            {
                printf("Ordenando...");
                ll_sort(lista,&cliente_compareById,0);
            }
        }
        else
        {
            printf("Opcion invalida:\n");
        }
    }while(opcion < 1 || opcion > 2);

    system("cls");
    return ret;
}


int controller_eliminarLista(LinkedList* lista)
{
    int ret = 1;
    if(lista != NULL)
    {
        ll_deleteLinkedList(lista);
        ret = 0;
    }
    return ret;
}

int controller_findById(LinkedList* lista,int id)
{
    int idCompare;
    int i;
    int ret = -1;
    eCliente* cliente;

    if(lista != NULL && id > 0)
    {
        for(i=0;i<ll_len(lista);i++)
        {
            cliente = ll_get(lista,i);
            cliente_getId(cliente,&idCompare);
            if(idCompare == id)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int controller_insertarCliente(LinkedList* lista,int* newId)
{
    eCliente* cliente;
    char nombre[51];
    char localidad[51];
    int ret = 1;
    int index;
    if(lista != NULL)
    {
        cliente = newCliente();
        if(cliente != NULL)
        {
            index = getInt("En que posicion desea Insertar?");
            if(index > -1 && index <ll_len(lista))
            {
                (*newId) = (*newId) + 1;
                cliente_setId(cliente,*newId);
                getString("Ingresar nombre: ",nombre);
                cliente_setNombre(cliente,nombre);
                getString("Ingresar localidad: ",localidad);
                cliente_setLocalidad(cliente,localidad);
                ret = ll_push(lista,index,cliente);
            }
        }
    }
    return ret;
}

int controller_escribirBinario(LinkedList* lista,char* path)
{
    FILE* pArchivo;
    int ret = 1;
    int i;
    eCliente* cliente;

    if(lista != NULL)
    {
        pArchivo = fopen(path,"wb");
        for(i=0;i<ll_len(lista);i++)
        {
            cliente = ll_get(lista,i);
            fwrite(cliente,sizeof(eCliente),1,pArchivo);
        }
        fclose(pArchivo);
        ret = 0;
    }
    return ret;
}

int controller_verificarClonacion(LinkedList* lista1,LinkedList* lista2)
{
    int ret = -1;
    if(lista1 != NULL && lista2 != NULL)
    {
        ret = ll_containsAll(lista1,lista2);
    }
    return ret;
}

void succes(int ret,char succes[],char error[])
{
    if(ret == 0)
    {
        printf("%s\n",succes);
    }
    else if(ret == 1)
    {
        printf("%s\n",error);
    }
}
