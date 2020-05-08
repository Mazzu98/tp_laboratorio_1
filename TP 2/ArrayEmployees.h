#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

/*----------------------Funciones solicitadas------------------------------------------*/
int initEmployees(Employee [], int );
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array and put 0 in all the id
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/

int addEmployee(Employee [], int , int , char [],char [],float ,int );
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
* free space] - (0) if Ok
*/

int findEmployeeById(Employee [], int ,int );
/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
*pointer received or employee not found]
*/
int removeEmployee(Employee [], int , int );
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
*find a employee] - (0) if Ok
*/

int sortEmployees(Employee [], int , int );
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/

int printEmployees(Employee [], int );
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/

/*----------------------Funciones agregadas-------------------------------------------*/
int nuevoEmpleado(Employee [],int );
/** \brief search if there is space and ask you to enter the employee fields
*   and call addEmployee to fill the fields
* \param list Employee*
* \param length int
* \return int
*/
void printMainMenu(void);
/** \brief print the menu
* \return void
*/
int modificarEmployee(Employee [],int);
/** \brief modify an employee by his id, ask what do you want to change
* and call the corresponsal function
* \param list Employee*
* \param length int
nt Return (-1) if Error [Invalid length or NULL pointer or if can't
*find a employee] - (0) if Ok
*/
void modificarNombre(Employee [],int);
/** \brief modify the name of the employee in the indicated position
* \param list Employee*
* \param index of the employee
* \return void
*/
void modificarApellido(Employee [],int);
/** \brief modify the last name of the employee in the indicated position
* \param list Employee*
* \param index of the employee
* \return void
*/
void modificarSalario(Employee [],int);
/** \brief modify the salary of the employee in the indicated position
* \param list Employee*
* \param index of the employee
* \return void
*/
void modificarSector(Employee [],int);
/** \brief modify the sector of the employee in the indicated position
* \param list Employee*
* \param index of the employee
* \return void
*/
int getEmptyPosition(Employee [],int);
/** \brief serch in the array the first empty position in the 'isEmpty' field of employee
* \param list Employee*
* \param length int
* \return -1 if there is no empty position or the index of the empty position
*/
int newId(Employee [],int);
/** \brief give you the id
* \param list Employee*
* \param int length
* \return the new id
*/
int empleadosPromSup(Employee [],int ,float );
/** \brief calculates the quantity of employees that are over the average salary
* \param list Employee*
* \param index of the employee
* \return void
*/
float promSalarios(float ,int );
/** \brief calculate the average salary
* \param float total salary
* \param int cant employees
* \return average salary
*/
float totalSalarios(Employee [],int );
/** \brief the total salary
* \param list Employee*
* \param int length
* \return float the total salari
*/
int cantEmployees(Employee [],int);
/** \brief the total employees added at the array
* \param list Employee*
* \param int length
* \return int cant of employees availables
*/
/*----------------------Ingreso de datos----------------------------------------------*/
int getInt(char []);
/** \brief This function ask for an int an validate it, if it isn't an int, will ask again
* \param is the string used to ask for the integer
* \return return the int entered by keybord
*/

int validarInt(char []);
/** \brief This function validates an integer, if it isn´t an int it warn you on screen
* \param the string to validate
* \return return 1 if it is integer and 0 if it isn't
*/

void getStringLetras(char [],char []);
/** \brief This function ask for a string an validate it
* and convert converts the entire string to lowercase, except the first letters,
* if some character is not letter it will ask again
* \param is the string used to ask for the string
* \param the place in memory where it will be saved
* \return not return
*/
int validarStringLetras(char[]);
/** \brief This function validates a string, if some character is not letter it warn you on screen
* \param the string to validate
* \return return 1 if only have letters and 0 if it have special caracters or numbers
*/

float getFloat(char []);
/** \brief This function ask for a float an validate it, if it isn't a float, will ask again
* \param is the string used to ask for the float
* \return return the int float by keybord
*/
int validacionFloat(char []);
/** \brief This function validates an float, if it isn´t a float it warn you on screen
* \param the string to validate
* \return return 1 if it is float and 0 if it isn't
*/
