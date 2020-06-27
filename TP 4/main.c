#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "cliente.h"
#include "parser.h"
#include "entradaValidada.h"
#include "controller.h"


int main()
{
    int opcion;
    int id=0;
    int success;
    LinkedList* lista = ll_newLinkedList();
    LinkedList* lista2= NULL;

    do
    {
        printMenu();
        opcion = getInt("Ingresar opcion:");
        switch(opcion)
        {
            case 1: controller_leerArchivoBin(lista,"data.bin");
                break;
            case 2: controller_altaCliente(lista,&id);
                break;
            case 3: controller_modificarCliente(lista);
                break;
            case 4: controller_bajaCliente(lista);
                break;
            case 5: controller_insertarCliente(lista,&id);
                break;
            case 6: controller_mostrarLista(lista);
                break;
            case 7: controller_sortCliente(lista);
                break;
            case 8: controller_escribirBinario(lista,"data.bin");
                break;
            case 9: lista2 = ll_clone(lista);
                break;
            case 10: success = controller_verificarClonacion(lista,lista2);
                     succes(success,"No se clonó","Clonado");
                break;
            case 11: ll_deleteLinkedList(lista);
                    lista=NULL;
                    break;
            default:
                break;
        }
    }while(opcion != 12);

    return 0;
}
