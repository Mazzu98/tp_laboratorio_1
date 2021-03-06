#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "entradaValidada.h"
#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    int ret;

    archivo = fopen(path,"r");
    ret = parser_EmployeeFromText(archivo,pArrayListEmployee);
    fclose(archivo);

    return ret;
}


int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* archivo;
    archivo = fopen(path,"rb");
    int ret;

    ret = parser_EmployeeFromBinary(archivo,pArrayListEmployee);
    fclose(archivo);

    return ret;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret = 0;
    if(pArrayListEmployee != NULL)
    {
        Employee* e1;
        Employee aux;

        aux.id = getNewId(pArrayListEmployee);
        getString("Ingrese el Nombre: ",aux.nombre);
        aux.horasTrabajadas = getInt("Ingrese las Horas Trabajadas: ");
        aux.sueldo = getInt("Igrese el sueldo: ");

        e1 = employee_new();
        *e1 = aux;
        ll_add(pArrayListEmployee,e1);

        system("cls");
        ret = 1;
    }
    return ret;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int opcion;
    int ret = 0;
    char auxCadena[15];
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        id = getInt("Ingresar id del empleado a modificar: ");
        index = findEmployeeById(pArrayListEmployee,id);
        if(index != -1)
        {
            aux = ll_get(pArrayListEmployee,index);
            do{
                opcion = getInt("1. Nombre\n2. Horas trabajadas\n3. Sueldo\n4. Cancelar \nIngrese una opcion: ");
                switch(opcion)
                {
                    case 1: getString("Ingrese nuevo nombre:",auxCadena);
                            employee_setNombre(aux,auxCadena);
                        break;
                    case 2: employee_setHorasTrabajadas(aux,getInt("Ingresar nuevas horas trabajadas: "));
                        break;
                    case 3: employee_setSueldo(aux,getInt("Ingresar nuevao sueldo: "));
                        break;
                    default:
                        break;
                }
            }while(opcion < 1 || opcion > 4);
            system("cls");
            ret = 1;
        }
    }
    return ret;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int ret = 0;

    if(pArrayListEmployee != NULL)
    {
        id = getInt("Ingresar id del empleado a Eliminar: ");
        index = findEmployeeById(pArrayListEmployee,id);
        if(index != -1)
        {
            ret = !ll_remove(pArrayListEmployee,index);
        }
    }
    system("cls");
    return ret;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;
    int ret = 0;
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        printf("  id\t    nombre   horasT  sueldo\n");
        for(int i=0; i<len; i++)
        {
            aux =(Employee*) ll_get(pArrayListEmployee, i);
            employee_show(*aux);
        }
        ret = 1;
    }

    return ret;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
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
                ll_sort(pArrayListEmployee,&employee_CompareByName,1);
            }
            else if (opcion == 2)
            {
                printf("Ordenando...");
                ll_sort(pArrayListEmployee,&employee_CompareByName,0);
            }
        }
        else if (opcion == 2)
        {
            printf("Ordenar:\n1. Acendente\n2. Decendente\n");
            opcion = getInt("Ingresar opcion:");
            if(opcion == 1)
            {
                printf("Ordenando...");
                ll_sort(pArrayListEmployee,&employee_CompareById,1);
            }
            else if (opcion == 2)
            {
                printf("Ordenando...");
                ll_sort(pArrayListEmployee,&employee_CompareById,0);
            }
        }
        else
        {
            printf("Opcion invalida:\n");
        }
    }while(opcion < 1 || opcion > 2);
        ll_sort(pArrayListEmployee,&employee_CompareByName,1);
    system("cls");
    return ret;
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int i;
    int len;
    int ret = 0;
    Employee *aux;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        pArchivo = fopen(path,"w");
        if(pArchivo != NULL)
        {
            fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
            for(i=0;i<len;i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                fprintf(pArchivo,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
            }
            fclose(pArchivo);
            ret = 1;
        }
    }

    return ret;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int i,len;
    int ret = 0;
    Employee *aux;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        pArchivo = fopen(path,"wb");
        if(pArchivo != NULL)
        {
            for(i=0;i<len;i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                fwrite(aux,sizeof(Employee),1,pArchivo);
            }
            fclose(pArchivo);
            ret = 1;
        }
    }
    return ret;
}

void controller_printMenu()
{
    printf("Menu: \n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf(" 3. Alta de empleado\n");
    printf(" 4. Modificar datos de empleado\n");
    printf(" 5. Baja de empleado\n");
    printf(" 6. Listar empleados\n");
    printf(" 7. Ordenar empleados\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
}

void succes(int ret,char succes[],char error[])
{
    if(ret == 1)
    {
        printf("%s\n",succes);
    }
    else if(ret == 0)
    {
        printf("%s\n",error);
    }
}

int findEmployeeById(LinkedList* lista,int id)
{
    int len = ll_len(lista);
    int i,idCompare;
    Employee* aux;
    for(i=0;i<len;i++)
    {
        aux = ll_get(lista,i);
        employee_getId(aux,&idCompare);
        if(idCompare == id)
        {
            return i;
        }
    }
    return -1;
}

int getNewId(LinkedList* lista)
{
    int maxId;
    int len;
    int id;
    int i;
    Employee *e1;
    len = ll_len(lista);

    if(len == 0)
    {
        id = 1;
    }
    else
    {
        for(i=0;i<len;i++)
        {
            e1 = ll_get(lista,i);
            employee_getId(e1,&id);
            if(i == 0 || maxId < id )
            {
                maxId = id;
            }
        }
        id = maxId +1;
    }
    return id;
}
