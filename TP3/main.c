#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "entradaValidada.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int opcion;
    int ret;
    LinkedList* miLista = ll_newLinkedList();
    do{
        controller_printMenu();
        opcion = getInt("\nIngrese una opcion:");
        system("cls");
        switch(opcion)
        {
            case 1: ret = controller_loadFromText("data.csv",miLista);
                    succes(ret,"Carga exitosa!\n","No se pudo cargar\n");
                break;
            case 2: ret = controller_loadFromBinary("data.bin",miLista);
                    succes(ret,"Carga exitosa!\n","No se pudo cargar\n");
                break;
            case 3: ret = controller_addEmployee(miLista);
                    succes(ret,"Agregado!\n","No se pudo agregar\n");
                break;
            case 4: ret = controller_editEmployee(miLista);
                    succes(ret,"Editado!\n","No se pudo editar\n");
                break;
            case 5: ret = controller_removeEmployee(miLista);
                    succes(ret,"Removido!\n","No se pudo remover\n");
                break;
            case 6: ret = controller_ListEmployee(miLista);
                    succes(ret,"","No existe la lista\n");
                break;
            case 7: ret = controller_sortEmployee(miLista);
                    succes(ret,"Ordenados!\n","No se pudo ordenar\n");
                break;
            case 8: ret = controller_saveAsText("data.csv",miLista);
                    succes(ret,"Guardado!\n","No se pudo guardar\n");
                break;
            case 9: ret = controller_saveAsBinary("data.bin",miLista);
                    succes(ret,"Guardado!\n","No se pudo guardar\n");
                break;
            case 10:
                break;
            default: printf("\nOpcion invalida\n\n");
                break;
        }
    }while(opcion != 10);


    return 0;
}
