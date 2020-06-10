#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char id[10],nombre[20],horas[15],sueldo[15],auxString[35];
    Employee *aux ;
    int ret;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fscanf(pFile,"%[^\n]\n",auxString);
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horas,sueldo);
            aux = employee_newParametros(id,nombre,horas,sueldo);
            ll_add(pArrayListEmployee,aux);
        }
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee *aux ;
    int ret;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            aux = employee_new();
            if(fread(aux,sizeof(Employee),1,pFile)==1)
            {
                ll_add(pArrayListEmployee,aux);
            }
        }
        ret = 1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}
