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
    LinkedList* lista = ll_newLinkedList();

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
            case 5: controller_mostrarLista(lista);
                break;
            case 6: controller_sortCliente(lista);
                break;
            case 7: controller_escribirBinario(lista,"data.bin");
                break;
            default:
                break;
        }
    }while(opcion != 8);



    //ll_deleteLinkedList(lista);
    //controller_mostrarLista(lista);

    return 0;
}
