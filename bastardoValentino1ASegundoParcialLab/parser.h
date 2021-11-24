/** \brief  parsea los datos de un archivo de texto y los convierte al tipo de dato necesario para que se almacenen en la estructura requerida
 *
 * \param pFile FILE*   path del archivo donde se encuentra el archivo de texto
 * \param pArrayListPais LinkedList*
 * \return int  retorna 0 en caso de que la validacion sea erronea, 1 en caso de que todo vaya bien
 *
 */
int parser_MovieFromText(FILE* pFile , LinkedList* pArrayListPais);
/** \brief  lo mismo que el parser de texto pero manejando archivos binarios
 *
 * \param pFile FILE*
 * \param pArrayListPais LinkedList*
 * \return int
 *
 */
int parser_MovieFromBinary(FILE* pFile , LinkedList* pArrayListPais);
