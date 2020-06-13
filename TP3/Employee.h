#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


Employee* employee_new();
/** \brief creates a new employee in the heap
 *
 * \return Employee* memory address of the employee
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
/** \brief creates a new employee in the heap with his fields
 *
 * \return Employee* memory address of the employee
 */
void employee_delete();
/** \brief delete employee in the heap with
 *
 * \return void
 */
int employee_setId(Employee* this,int id);
/** \brief Set the id in the employee
 *
 * \return int 1 if is OK, 0 if not
 */
int employee_getId(Employee* this,int* id);
/** \brief Get the id in the employee
 *
 * \return int 1 if is OK, 0 if not
 */

int employee_setNombre(Employee* this,char* nombre);
/** \brief Set the name in the employee
 *
 * \return int 1 if is OK, 0 if not
 */
int employee_getNombre(Employee* this,char* nombre);
/** \brief Get the name in the employee
 *
 * \return int 1 if is OK, 0 if not
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Set the WorkedHours in the employee
 *
 * \return int 1 if is OK, 0 if not
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
/** \brief Get the WorkedHours in the employee
 *
 * \return int 1 if is OK, 0 if not
 */

int employee_setSueldo(Employee* this,int sueldo);
/** \brief Set the Salary in the employee
 *
 * \return int 1 if is OK, 0 if not
 */
int employee_getSueldo(Employee* this,int* sueldo);
/** \brief Get the Salary in the employee
 *
 * \return int 1 if is OK, 0 if not
 */
int employee_CompareByName(void* e1, void* e2);
/** \brief Compare the names
 *
 * \return int > 0 if first is higher, = 0 if are equal, < if first is lower
 */
int employee_CompareById(void* e1, void* e2);
/** \brief Compare the id
 *
 * \return int > 0 if first is higher, = 0 if are equal, < if first is lower
 */

void employee_show(Employee );
/** \brief print an employee
 *
 */

#endif // employee_H_INCLUDED
