
#include "ArrayEmployees.h"
#define T 2

int main()
{
    Employee list[T];
    int opcion,id,funDone,cantIngresados = 0;
    initEmployees(list,T);
    do{
        printMainMenu();
        opcion = getInt("Ingrese una opcion: ");

        switch(opcion)
        {
            case 1: funDone = nuevoEmpleado(list,T);
                    system("cls");
                    if(funDone == -1)
                    {
                        printf("\nNo hay mas espacios disponibles\n");
                    }
                    else
                    {
                        printf("\nEmpleado anadido exitosamente!\n");
                        cantIngresados++;
                    }
                    break;

            case 2: funDone = modificarEmployee(list,T);
                    system("cls");
                    if(funDone == -1)
                    {
                        printf("\nNo existe empleado con ese numero de id\n");
                    }
                    else
                    {
                        printf("\nModificacion exitosa!\n");
                    }
                    break;

            case 3: id = getInt("\nIngrese el id del empleado que desea dar de baja: ");
                    funDone = removeEmployee(list,T,id);
                    system("cls");
                    if(funDone == -1)
                    {
                        printf("\nNo existe empleado con ese id\n");
                    }
                    else
                    {
                        printf("\nEmpleado dado de baja exitosamente!\n");
                        cantIngresados--;
                    }
                    break;

            case 4: if(cantIngresados > 0)
                    {
                        sortEmployees(list,T,0);
                        printEmployees(list,T);

                    }
                    else
                    {
                        printf("\nNo hay ningun empleado en la lista \n");
                    }
                    break;

            case 5:
                    break;
            default:
                printf("\nIngrese una opcion correcta: \n");
        }

    }while(opcion !=5);

    return 0;
}
