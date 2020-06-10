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
        return 1;
    }
    else
    {
        return 0;
    }
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id,index,opcion;
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
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int ret = 1;

    if(pArrayListEmployee != NULL)
    {
        id = getInt("Ingresar id del empleado a Eliminar: ");
        index = findEmployeeById(pArrayListEmployee,id);
        if(index != -1)
        {
            ll_remove(pArrayListEmployee,index);
        }
        else
        {
            ret = 0;
        }
    }
    else
    {
        ret = 0;
    }
    return ret;

}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int len;
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
        return 1;
    }
    else
    {
        return 0;
    }
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp1,*emp2,aux;
    int i,j;
    int len;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0;i<len-1;i++)
        {
            for(j=i+1;j<len;j++)
            {
                emp1 = ll_get(pArrayListEmployee,i);
                emp2 = ll_get(pArrayListEmployee,j);
                if(strcmp(emp1->nombre,emp2->nombre) > 0)
                {
                    aux = *emp1;
                    *emp1 = *emp2;
                    *emp2 = aux;
                }
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}


int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int i,len;
    Employee *aux;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        pArchivo = fopen(path,"w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<len;i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            fprintf(pArchivo,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
        }
        fclose(pArchivo);
    }
    return 1;
}


int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int i,len;
    Employee *aux;
    if(pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        pArchivo = fopen(path,"wb");
        for(i=0;i<len;i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            fwrite(aux,sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
    }
    return 1;
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
