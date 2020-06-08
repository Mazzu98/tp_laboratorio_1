#include <stdlib.h>
#include "Employee.h"
#include <string.h>
#include <stdio.h>

Employee* employee_new()
{
    Employee *empleado;
    empleado = (Employee*)malloc(sizeof(Employee));
    return empleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee *empleado;
    empleado = employee_new();
    empleado->id = atoi(idStr);
    strcpy(empleado->nombre,nombreStr);
    empleado->horasTrabajadas = atoi(horasTrabajadasStr);
    empleado->sueldo = atoi(sueldoStr);
    return empleado;
}

int employee_setNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_getNombre(Employee* this,char* nombre)
{
    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setSueldo(Employee* this,int sueldo)
{
    if(this != NULL)
    {
        this->sueldo = sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    if(this != NULL)
    {
        *sueldo = this->sueldo;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setId(Employee* this,int id)
{
    if(this != NULL)
    {
        this->id = id;
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getId(Employee* this,int* id)
{
    if(this != NULL)
    {
        *id = this->id;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajdas)
{
    if(this != NULL)
    {
        *horasTrabajdas = this->horasTrabajadas;
        return 1;
    }
    else
    {
        return 0;
    }
}

int employee_CompareByName(Employee* e1, Employee* e2)
{
    return strcmp(e1->nombre, e2->nombre);
}

int employee_CompareById(Employee* e1, Employee* e2)
{
    if(e1 != NULL && e2 != NULL)
    {
        if(e1->id > e2->id)
        {
            return 1;
        }
        else
        {
            if(e1->id < e2->id)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
    return strcmp(e1->nombre, e2->nombre);
}

void employee_show(Employee empleado)
{
    printf("%4d %13s %6d %9d\n",empleado.id,empleado.nombre,empleado.horasTrabajadas,empleado.sueldo);
}

