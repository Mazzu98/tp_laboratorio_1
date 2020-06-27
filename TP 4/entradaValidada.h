
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void getOLString(char [],char []);
/** \brief This function ask for a string an validate it
* if some character is not letter it will ask again
* \param is the string used to ask for the string
* \param the place in memory where it will be saved
* \return not return
*/
int validarOLString(char[]);
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
void getString(char [] ,char []);
/** \brief This function ask for a string
* \param is the string used to ask for the string
* \param max number of caracters
* \param the place in memory where it will be saved
* \return not return
*/
