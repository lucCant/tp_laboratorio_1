#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief To indicate that all position in the array are empty,
  * this function put the flag (isEmpty) in TRUE in all
  * position of the array
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
  *
  */

int initEmployees(Employee list[], int len);


/** \brief Displays the option menu
  * \return int return (option) to be used in a switch statement in main().
  *
  */

int menu();


/** \brief Registers name, last name, salary and sector, to be sent at function addEmployee().
  *
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  * \param id int
  * \return
  *
  */

void registerEmployee(Employee list[], int len, int id);


/** \brief add in a existing list of employees the values received as parameters
  * in the first empty position
  * \param list employee*
  * \param len int
  * \param id int
  * \param name[] char
  * \param lastName[] char
  * \param salary float
  * \param sector int
  * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
  *
  */

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);


/** \brief find an Employee by Id en returns the index position in array.
  *
  * \param list Employee*
  * \param len int
  * \param id int
  * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
  *
  */

int findEmployeeById (Employee list[], int len, int id);


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
  *
  * \param list Employee*
  * \param len int
  * \param id int
  * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
  *
  */

int removeEmployee (Employee list[], int len, int id);


/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
  *
  * \param list Employee*
  * \param len int
  * \param order int [1] indicate UP - [0] indicate DOWN
  * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
  *
  */

int sortEmployees (Employee list[], int len, int order);


/** \brief Prints the content of employees array
  *
  * \param list Employee*
  * \param length int
  * \return int
  *
  */

int printEmployees (Employee list[], int len);


/** \brief Changes employee data
  *
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  *
  */

void modifyEmployee (Employee list[], int len);


/** \brief Asks for id and sends it to function removeEmployee().
  *
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  *
  */

void annulEmployee(Employee list[], int len);


/** \brief Gathers parameters to be sent at sortEmployees() or computeSalaries().
  *
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  *
  */

void inform(Employee list[], int len);


/** \brief Computes salary operations: calculates average salary, prints total salary and employees with above-average salary
  *
  * \param list Employee* Pointer to array of employees
  * \param len int Array length
  */

void computeSalaries(Employee list[], int len);
