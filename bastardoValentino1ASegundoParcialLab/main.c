
#include <stdio.h>
#include <stdlib.h>
#include "Controller.h"
#include "Movies.h"
#include "miBiblioteca.h"
#include <string.h>
#include <time.h>

#include "LinkedList.h"
int main()
{
    srand(time(NULL));
    char seguir='s';
    LinkedList* listaMovie = ll_newLinkedList();
     LinkedList* listaOrden = ll_newLinkedList();
    int archivoCargado=0;
    char nombreArchivo[32];
    int rtaGen;

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if(archivoCargado)
            {
                printf("\nNo se puede cargar, ya hay un archivo cargado.\n\n");
                system("pause");
            }
            else
            {
                ingresarStr("nombre del archivo",nombreArchivo,32);

                if(controller_loadFromText(nombreArchivo,listaMovie))
                {
                    archivoCargado=1;
                    system("pause");
                    archivoCargado++;
                }
            }
            break;
        case 2:
            if(!ll_isEmpty(listaMovie))
            {
                listaMovie= ll_map(listaMovie,eMovie_asignarDuracion);
                printf("\nDuracion asignada con exito.\n\n");
                system("pause");

            }
            else
            {
                printf("\nNo se puede asignar estadisticas sin antes cargar un Movie.\n\n");
                system("pause");
            }

            break;
        case 3:
            if(!ll_isEmpty(listaMovie))
            {
                controller_ListMovie(listaMovie);
                system("pause");
            }
            else
            {
                printf("\nNo puede listar Movie sin antes cargar un archivo de texto/binario o dar una alta.\n\n");
                system("pause");
            }

            break;
        case 4:
           if(!ll_isEmpty(listaMovie))
            {
                LinkedList* listaGenero = NULL;
                listaGenero=ll_newLinkedList();
                if(listaGenero!=NULL)
                {
                    printf("Ingrese el genero por el cual desea filtrar: \n[1]-Adventure\n[2]-Drama\n[3]-Comedy\n[4]-Romance\n[5]-Documentary\n[6]-Horror\n[7]-Animation\n[8]-Musical\n[9]-Action\n[10]-Western\n[11]-Thriller\n[Default]-Cancelar\n\n");
                    ingresarIntPos("genero",&rtaGen,1,11);
                    switch(rtaGen)
                    {
                    case 1:
                         listaGenero=ll_filter(listaMovie,eMovie_filtroGenero1);
                        break;
                        case 2:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero2);
                        break;
                        case 3:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero3);
                        break;
                        case 4:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero4);
                        break;
                        case 5:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero5);
                        break;
                        case 6:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero6);
                        break;
                        case 7:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero7);
                        break;
                        case 8:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero8);
                        break;
                        case 9:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero9);
                        break;
                        case 10:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero10);
                        break;
                         case 11:
                            listaGenero=ll_filter(listaMovie,eMovie_filtroGenero11);
                        break;
                        default:
                            printf("Se genero un archivo en blanco");
                            break;

                    }


                    controller_saveAsText("moviesGenero.csv",listaGenero);
                    system("pause");

                }
                else
                {
                    printf("\nNo hay espacio en memoria.\n");
                    system("pause");
                }
            }
            else
            {
                printf("\nNo se puede hacer un listado nuevo si no hay peliculas cargadas.\n\n");
                system("pause");
            }
            break;
        case 5:
            if(!ll_isEmpty(listaMovie))
            {
                listaOrden=controller_sortMovie(listaMovie); // FALTA SUB-ORDENAR POR DURACION


            }
            else
            {
                printf("\nNo se puede remover un empleado sin antes cargar un archivo o dar una alta.\n\n");
                system("pause");
            }

            break;
        case 6:
              if(!ll_isEmpty(listaOrden))
            {
                controller_saveAsText("moviesOrdenadasPorGenero.csv",listaOrden);
                system("pause");
            }
            else
            {
                printf("\nEjecute primero la funcionalidad [5] y genere una nueva lista.\n\n");
                system("pause");
            }
            break;
            break;
        case 7:
           if(!ll_isEmpty(listaMovie))
            {
                controller_saveAsText("MoviesNew.csv",listaMovie);
                system("pause");
            }
            else
            {
                printf("\nNo se puede guardar una lista sin peliculas.\n\n");
                system("pause");
            }
            break;
        case 8:
            seguir='n';
            break;

        default:
            printf("\nIngrese una opcion valida.\n");
            system("pause");

            break;
        }
    }
    while(seguir=='s');
    return 0;
}
