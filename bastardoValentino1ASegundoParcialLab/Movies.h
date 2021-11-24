#ifndef eMovie_H_INCLUDED
#define eMovie_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    char genero[128];

    int duracion;

}eMovie;
eMovie* eMovie_new();
/** \brief              crea una nueva eMovie cuyos parametros son todos punteros a char porque luego van a ser casteados de ser necesario mediante atoi
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param generoStr char*
 * \param duracionStr char*
 * \return eMovie*      retorna la eMovie con los parametros actualziados
 *
 */
eMovie* eMovie_newParametros(char* idStr, char* nombreStr, char* generoStr, char* duracionStr);

/** \brief grupo de seters, al cual uno le manda un puntero a eMovie y el mismo carga el campo indicado con el valor que le pases como segundo parametro
 *
 * \param
 * \param
 * \return retorna 1 en caso de que la validacion sea incorrecta, 0 en caso de que no haya ningun error
 *
 */

int eMovie_setId(eMovie* this,int id);
int eMovie_setNombre(eMovie* this,char* nombre);
int eMovie_setGenero(eMovie* this,char* genero);
int eMovie_setDuracion(eMovie* this,int duracion);
/** \brief grupo de geters, al cual le envias un puntero a una eMovie y te devuelve el parametro indicado en formato puntero.
 *
 * \param
 * \param
 * \return retorna 1 en caso de que la validacion sea incorrecta, 0 en caso de que no haya ningun error
 *
 */

int eMovie_getId(eMovie* this,int* id);
int eMovie_getNombre(eMovie* this,char* nombre);
int eMovie_getGenero(eMovie* this,char* genero);
int eMovie_getDuracion(eMovie* this,int* duracion);

/** \brief  Todas estas funciones comparan el genero de una eMovie pasada por puntero con otro genero hardcodeado
 *
 * \param unMovie void*     puntero void de la eMovie que debe ser casteada para obtener su genero y comparar
 * \return int      retornan 1 o -1 para indicar cual viene antes que la otra dependiendo su codigo ASCII
 *
 */
int eMovie_filtroGenero1(void* unMovie);
int eMovie_filtroGenero2(void* unMovie);
int eMovie_filtroGenero3(void* unMovie);
int eMovie_filtroGenero4(void* unMovie);
int eMovie_filtroGenero5(void* unMovie);
int eMovie_filtroGenero6(void* unMovie);
int eMovie_filtroGenero7(void* unMovie);
int eMovie_filtroGenero8(void* unMovie);
int eMovie_filtroGenero9(void* unMovie);
int eMovie_filtroGenero10(void* unMovie);
int eMovie_filtroGenero11(void* unMovie);



/** \brief  es la pFunc de ll_map, y le asigna valores random de duracion a las peliculas basadas en que tienen que durar mas de 100 minutos y menos de 240
 *
 * \param unMovie void*
 * \return void*
 *
 */
void* eMovie_asignarDuracion(void* unMovie);



/** \brief      se encarga de ordenar por duracion
 *
 * \param eMovie1 void* compara esta pelicula
 * \param eMovie2 void* con esta
 * \return int  retorna 1 o -1 para indicar que el primer elemento es mayor o menor que el segundo
 *
 */
int eMovie_sortByDuracion(void* eMovie1, void* eMovie2);

/** \brief  se encarga de ordenar por genero
 *
 * \param eMovie1 void*
 * \param eMovie2 void*
 * \return int  retorna 1 o -1 para indicar que el codigo ascii del primer elemento es mayor o menor que el del segundo
 *
 */
int eMovie_sortByGenero(void* eMovie1, void* eMovie2);

/** \brief  recibe la direccion de memoria de una eMovie y la libera.
 *
 * \param unMovie eMovie*
 * \return void  no retorna nada
 *
 */
void eMovie_delete(eMovie* unMovie);

#endif
