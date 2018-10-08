#ifndef PROYECTO_H_INCLUDED
#define PROYECTO_H_INCLUDED


typedef struct
    {
        int id;
        char name[51];
        char lastName[51];
        float salary;
        int sector;
        int isEmpty;

    }sEmployee;

/** \brief
*
* \param
* \param
* \return
*
*/
int options();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void initEmployees(sEmployee* list, int len);

int addEmployees(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int searchEmpty(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void printEmployee(sEmployee list);
void printEmployees(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int findEmployeeById(sEmployee* list, int len, int id);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void modifyEmployee(sEmployee* list, int len);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int sortEmployees(sEmployee* list, int len, int order);

int removeEmployee(sEmployee* list, int len);
float  salaryAverage(sEmployee* list, int len);
int  aboveAverage(sEmployee* list, int len);
float  totalSalary(sEmployee* list, int len);

void getString(char* message,char* input);

char getChar(char* message);

int esNumerico(char* str);

int stringNumberFloat(char* str);

int getStringLetras(char* message,char* input);

int getStringNumeros(char* message,char* input);
int funcion_getStringNumerosFlotantes(char* mensaje,char* input);

void harcodeoEmployee(sEmployee* list);


#endif // PROYECTO_H_INCLUDED
