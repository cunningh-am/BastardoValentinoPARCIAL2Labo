#include "Movies.h"
#include "LinkedList.h"

/** \brief  es un controlador que se encarga de abrir un file y enviarselo a el parser para que convierta el dato de texto al tipo de dato real, tambien le envia un linked list para que cargue esos datos
 *
 * \param path char*    ubicacion del file
 * \param pArrayListEmployee LinkedList*   puntero al linked list donde van a ser cargados los datos
 * \return int  retorna -1 en caso de que la validacion este mal, 1 en caso de que este todo bien
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
/** \brief          es un controlador que como el de texto, abre un file para enviarselo al parser binario y que convierta los datos en binario a datos reales, tambien le envia linked list para que los cargue
 *
 * \param path char*  ubicacion del file
 * \param pArrayListEmployee LinkedList*  lista donde se cargaran
 * \return int  retorna -1 en caso de que la validacion sea incorrecta, 1 en caso de que no pueda abrir el file y 0 en caso de que este todo bien
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief      recibe un puntero a linked list, y se encarga de mandarle una por una todas sus peliculas a controller_printMovie
 *
 * \param pArrayListMovie LinkedList*  puntero a la ll
 * \return int  retorna 0 en caso de que la validacion sea incorrecta, 1 en caso de que este bien
 *
 */
int controller_ListMovie(LinkedList* pArrayListMovie);
/** \brief  imprime una pelicula, esta encapsulada dentro de _listMovie ya que la misma mediante iteraciones puede enviarle todas las peliculas para imprimirlas una debajo de otra
 *
 * \param unMovie eMovie*  puntero de la pelicula que va a imprimir en pantalla
 * \return int             retorna 0 en caso de que la validacion no sea correcta, 1 en el caso de que este bien
 *
 */
int controller_printMovie(eMovie* unMovie);
/** \brief  recibe un puntero a linked list, y se lo envia a ll_sort junto con otra funcion que servira de criterio para ordenar la lista. tambien se encarga de imprimirla en pantalla con _listmovie
 *
 * \param pArrayListMovie LinkedList* puntero a la ll
 * \return LinkedList* retorna el puntero a la linked list, para que la misma luego pueda ser guardada como archivo aparte
 *
 */
LinkedList* controller_sortMovie(LinkedList* pArrayListMovie);
/** \brief      recibe un puntero al file y un puntero a linked list, y va iterando para mediante 'get's, ir guardando todos los datos en variables auxiliares y las imprime en un archivo de texto con el formato deseado.
 *
 * \param path char*  es puntero al archivo donde lo vamos a guardar
 * \param pArrayListMovie LinkedList* puntero a la ll
 * \return int 0 en caso de que la validacion sea incorrecta, 1 en caso de que este todo bien
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListMovie);
/** \brief  controlador que recibe un puntero a linked list, puntero a file, y va guardando los datos en formato binario en el archivo
 *
 * \param path char*    path del file binario donde se guardaran los datos.
 * \param pArrayListMovie LinkedList* puntero a la ll
 * \return int retorna 0 en caso de que la validacion sea incorrecta, 1 en caso de que este todo bien
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListMovie);
