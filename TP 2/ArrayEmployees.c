
#include "ArrayEmployees.h"
#define STR_TAM 51
int initEmployees(Employee list[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        list[i].isEmpty = 1;
        list[i].id = 0;
    }
    return 0;
}

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int index;
    index = getEmptyPosition(list,len);
    if(index != -1 )
    {
        list[index].id = id;
        strcpy(list[index].name,name);
        strcpy(list[index].lastName,lastName);
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = 0;
        return 0;
    }
    else
    {
        return -1;
    }
    return -1;
}

int nuevoEmpleado(Employee list[],int len)
{
    int id,sector,retorno = -1;
    float salario;
    char nombre[STR_TAM],apellido[STR_TAM];
    if(getEmptyPosition(list,len) != -1)
    {
        id = newId(list,len);
        getStringLetras("\nIngresar nombre: ",nombre);
        getStringLetras("\nIngresar apellido: ",apellido);
        salario = getFloat("\nIngresar salario: ");
        sector = getInt("\nIngresar sector: ");
        retorno = addEmployee(list, len, id, nombre,apellido,salario, sector);
    }
    return retorno;
}

int findEmployeeById(Employee list[], int len,int id)
{
    int i, index = -1;
    for(i=0;i<len;i++)
    {
        if(list[i].isEmpty == 0 && list[i].id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

int removeEmployee(Employee list[], int len, int id)
{
    int index;
    index = findEmployeeById(list,len,id);

    if(index != -1)
    {
        list[index].isEmpty = 1;
        return 0;
    }
    else
    {
        return -1;
    }
}

int sortEmployees(Employee list[], int len, int order)  //2 mayor a menor, 1 menor a mayor
{
    Employee aux;
    int i,j;
    if(order == 0)  //menor a mayor
    {
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len-1;j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector > list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    if(order == 1)  //mayor a menor
    {
        for(i=0;i<len;i++)
        {
            for(j=i+1;j<len-1;j++)
            {
                if(strcmp(list[i].lastName,list[j].lastName) > 0)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
                if(strcmp(list[i].lastName,list[j].lastName) == 0 && list[i].sector < list[j].sector)
                {
                    aux = list[i];
                    list[i] = list[j];
                    list[j] = aux;
                }
            }
        }
    }
    return 0;
}

int printEmployees(Employee list[], int length)
{
    int i,cantSupProm,cantEmpleados;
    float totalSalary,promSalary;
    printf("\n     ID       Nombre              Apellido         Salario         Sector");
    for(i=0;i<length;i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("\n %5d %15s %20s \t%12.2f %10d",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    printf("\n\n");
    cantEmpleados = cantEmployees(list,length);
    totalSalary = totalSalarios(list,length);
    promSalary = promSalarios(totalSalary,cantEmpleados);
    cantSupProm = empleadosPromSup(list,length,promSalary);

    printf("Total de salarios: %.2f \nPromedio de salarios: %.2f \nCantidad de Empleados que cobran arriba del promedio: %d\n\n",totalSalary,promSalary,cantSupProm);
    printf("Precione enter para continuar...\n");
    getchar();
    system("cls");
    return 0;
}

int modificarEmployee(Employee list[],int tam)
{
    int opcion,id,index;
    id = getInt("\nIgrese el id de el empleado que modificara: ");
    index = findEmployeeById(list,tam,id);

    if(index != -1)
    {
        printf("\n\t1. Modificar nombre \n\t2. Modificar apellido \n\t3. Modificar salario \n\t4. Modificar sector\n");
        opcion = getInt("\nIngrese una opcion: ");

        switch(opcion)
        {
            case 1: modificarNombre(list,index);
                break;

            case 2: modificarApellido(list,index);
                break;

            case 3: modificarSalario(list,index);
                break;

            case 4: modificarSector(list,index);
                break;

            default:
                printf("\n Error: opcion incorrecta");
        }
        return 0;
    }
    else
    {
            return index;
    }

}
void modificarNombre(Employee list[],int index)
{
    char string[51];
    getStringLetras("Ingrese el nuevo nombre: ",string);
    strcpy(list[index].name,string);
}
void modificarApellido(Employee list[],int index)
{
    char string[51];
    getStringLetras("Ingrese el nuevo apellido: ",string);
    strcpy(list[index].lastName,string);
}
void modificarSalario(Employee list[],int index)
{
    float salario;
    salario = getFloat("Ingrese el nuevo salario: ");
    list[index].salary = salario;
}
void modificarSector(Employee list[],int index)
{
    int sector;
    sector = getInt("Ingrese el nuevo sector: ");
    list[index].sector = sector;
}

float totalSalarios(Employee list[],int tam)
{
    int i;
    float total = 0;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty == 0)
        {
            total += list[i].salary;
        }
    }
    return total;
}

float promSalarios(float total,int cant)
{
    float prom;
    prom = total/cant;
    return prom;
}
int empleadosPromSup(Employee list[],int tam,float prom)
{
    int i,cant = 0;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > prom)
        {
            cant ++;
        }
    }
    return cant;
}

int cantEmployees(Employee list[],int tam)
{
    int i,cant = 0;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty == 0)
        {
            cant++;
        }
    }
    return cant;
}

int newId(Employee list[],int len)
{
    int i, maxId = 0;

    for(i=0;i<len;i++)
    {
        if(list[i].id > maxId)
        {
            maxId = list[i].id;
        }
    }
    maxId++;
    return maxId;
}

int getInt(char text[])
{
    char num[11];
    do{
        puts(text);
        fflush(stdin);
        gets(num);

    }while(!validarInt(num));

    return atoi(num);
}

int validarInt(char string[])
{
    int i,validacion = 1;
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<48 || string[i]>57)
        {
            validacion = 0;
            break;
        }
    }
    if(validacion == 0)
    {
            printf("\nError: debe ingresar un numero entero\n\n");
    }
    return validacion;
}

void getStringLetras(char text[],char string[])
{
    int i;
    do{
        fflush(stdin);
        puts(text);
        gets(string);
    }while(!validarStringLetras(string));

    for(i=0;i<strlen(string);i++)
    {
            if(i==0 || (i-1) == ' ')
            {
                string[i] -= 32;
            }
    }
}
int validarStringLetras(char string[])
{
    int i,validacion = 1;
    strlwr(string);
    for(i=0;i<strlen(string);i++)
    {
        if(string[i]<97 || string[i]>122)
        {
            validacion = 0;
            break;
        }
    }
    if(validacion == 0)
    {
        printf("\nError: este campo debe poseer solo letras, intente de nuevo...\n\n");
    }
    return validacion;
}

float getFloat(char text[])
{
    char string[20];
    float num;
    do{
        puts(text);
        fflush(stdin);
        gets(string);
    }while(!validacionFloat(string));

    num = atof(string);
    return num;
}

int validacionFloat(char string[])
{
    int i,puntosCont = 0, validacion = 1;
    for(i=0;i<strlen(string);i++)
    {
        if(string[i] == '.')
        {
            puntosCont++;
        }
        else if(string[i] < 48 || string[i] > 57)
        {
            validacion = 0;
            break;
        }
    }
    if(puntosCont>1)
    {
        validacion = 0;
    }
    if(validacion == 0)
    {
        printf("\nError: debe ingresar el valor decimal correctamente\n\n");
    }
    return validacion;
}

int getEmptyPosition(Employee list[],int tam)
{
    int i, index = -1;
    for(i=0;i<tam;i++)
    {
        if(list[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

void printMainMenu()
{
    printf("\n1) Dar de alta ");
    printf("\n2) Modificar empleado ");
    printf("\n3) Dar de baja ");
    printf("\n4) Informar");
    printf("\n5) Salir\n\n");
}
