int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief load the text from the file
 *
 * \param path of the file
 * \param address of the linkedList

 * \return int 1 if is OK, 0 if not
 */

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief load the binaries from the file
 *
 * \param path of the file
 * \param address of the linkedList

 * \return int 1 if is OK, 0 if not
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);
/** \brief add an employee
 *
 * \param address of the linkedList
 * \return int 1 if is OK, 0 if not
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);
/** \brief edit an employee
 *
 * \param address of the linkedList
 * \return int 1 if is OK, 0 if not
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief remove an employee
 *
 * \param address of the linkedList
 * \return int 1 if is OK, 0 if not
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Lists the Employees
 *
 * \param address of the linkedList
 * \return int 1 if is OK, 0 if not
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);
/** \brief Sort the employees
 *
 * \param address of the linkedList
 * \return int 1 if is OK, 0 if not
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
/** \brief Save the list to the file
 *
 * \param path of the file
 * \param address of the linkedList

 * \return int 1 if is OK, 0 if not
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief load the list to the file
 *
 * \param path of the file
 * \param address of the linkedList

 * \return int 1 if is OK, 0 if not
 */

void controller_printMenu(void);
/** \brief Print the menu
 *
 * \return void
 */

void succes(int ,char [],char []);
/** \brief to print error or success message
 *
 * \param int to analize
 * \param success message
 * \param error message
 *
 * \return void
 */

int findEmployeeById(LinkedList*,int);
/** \brief find an employee by id
 *
 * \param linked list
 * \param id of the employee
 *
 * \return index of the employee if is ok, if not -1
 */

int getNewId(LinkedList*);
/** \brief find a new id
 *
 * \param linked list pointer
 *
 * \return void
 */


