#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Movies.h"
#include "Controller.h"
#include "parser.h"
#include "miBiblioteca.h"




int controller_loadFromText(char* path, LinkedList* pArrayListMovie)
{
    int ret=(-1);
    FILE* f;

    if(path!=NULL && pArrayListMovie!=NULL)
    {
        f= fopen(path, "r");
        if(f!=NULL)
        {
            parser_MovieFromText(f,pArrayListMovie);
            printf("\nCarga de archivo de texto exitosa.\n\n");
            ret=1;
        }
        else
        {
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
        fclose(f);

    }
    return ret;
}

int controller_loadFromBinary(char* path, LinkedList* pArrayListMovie)
{
    int ret=-1;
    FILE* f;
    if(path!=NULL && pArrayListMovie!=NULL)
    {
        f=fopen(path, "rb");
        if(f!=NULL)
        {
            parser_MovieFromBinary(f, pArrayListMovie);
            printf("\nCarga de archivo binario exitosa.\n\n");
            ret=0;
        }
        else
        {
            ret=1;
            printf("\nNo se pudo cargar el archivo.\n\n");
        }
        fclose(f);
    }
    return ret;
}

int controller_ListMovie(LinkedList* pArrayListMovie)
{
    int ret=0;
    int len;
    eMovie* unMovie;

    if(pArrayListMovie!=NULL)
    {
        system("cls");
        printf("             LISTA DE PELICULAS           \n");
        printf("------------------------------------------\n");

        len=ll_len(pArrayListMovie);

        if(len>0)
        {
            for(int i=0; i<len; i++)
            {
                unMovie=ll_get(pArrayListMovie, i);
                controller_printMovie(unMovie);
                printf("------------------------------------------\n");
            }
            ret=1;
        }
        printf("\n");
    }
    return ret;
}
int controller_printMovie(eMovie* unMovie)
{
    int ret=0;
    int id;
    char nombre[128];
    char genero[128];
    int duracion;


    if(unMovie!=NULL)
    {
        ret=1;
        eMovie_getId(unMovie,&id);
        eMovie_getNombre(unMovie,nombre);
        eMovie_getGenero(unMovie,genero);
        eMovie_getDuracion(unMovie,&duracion);

        printf("ID:                  %d\nNOMBRE:              %s\nGENERO:              %s\nDURACION:            %d\n",id,nombre,genero,duracion);
    }
    return ret;
}
LinkedList* controller_sortMovie(LinkedList* pArrayListMovie)
{


    LinkedList* auxLista;
    auxLista=ll_clone(pArrayListMovie);

    if(pArrayListMovie!=NULL)
    {


                ll_sort(auxLista, eMovie_sortByGenero, 1);

                system("cls");
                controller_ListMovie(auxLista);
                system("pause");



}
return auxLista;
}
int controller_saveAsText(char* path, LinkedList* pArrayListMovie)
{
    int ret=0;
    int id;
    char nombre[128];
    char genero[128];
    int duracion;

    FILE* f;
    eMovie* unMovie;
    int len;


    if(path!=NULL && pArrayListMovie!=NULL)
    {
        f=fopen(path,"w");
        unMovie=eMovie_new();
        len=ll_len(pArrayListMovie);

        for(int i=0; i<len; i++)
        {
            unMovie=ll_get(pArrayListMovie,i);
            eMovie_getId(unMovie,&id);
            eMovie_getNombre(unMovie,nombre);
            eMovie_getGenero(unMovie,genero);
            eMovie_getDuracion(unMovie,&duracion);
            fprintf(f,"%d,%s,%s,%d\n",id,nombre,genero,duracion);
        }
        fclose(f);
        printf("\nArchivo de texto guardado con exito.\n\n");
        ret=1;

    }
    return ret;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListMovie)
{
    int ret=1;
    eMovie* unMovie;
    FILE* f;
    int len;

    if(path!=NULL && pArrayListMovie!=NULL)
    {
        f=fopen(path, "wb");
        unMovie=eMovie_new();

        if(unMovie!=NULL)
        {
            len=ll_len(pArrayListMovie);
            for(int i=0; i<len; i++)
            {
                unMovie=ll_get(pArrayListMovie, i);
                fwrite(unMovie, sizeof(eMovie), 1, f);
            }
            ret=0;
        }
        fclose(f);
        printf("\nArchivo binario guardado con éxito.\n\n");
    }

    return ret;
}
