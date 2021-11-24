#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Movies.h"
#include "miBiblioteca.h"

eMovie* eMovie_new()
{
    eMovie* newMovie;

    newMovie=(eMovie*)malloc(sizeof(eMovie));
    if(newMovie!=NULL)
    {
        newMovie->id=0;
        strcpy(newMovie->nombre,"-");
        strcpy(newMovie->genero,"-");
        newMovie->duracion=0;
    }

    return newMovie;
}

eMovie* eMovie_newParametros(char* idStr, char* nombreStr, char* generoStr, char* duracionStr)
{
    eMovie* newMovie;

    newMovie=eMovie_new();

    if(newMovie!=NULL)
    {
        if((eMovie_setId(newMovie, atoi(idStr))
                || eMovie_setNombre(newMovie, nombreStr)
                || eMovie_setGenero(newMovie, generoStr)
                || eMovie_setDuracion(newMovie, atoi(duracionStr))))
        {
            eMovie_delete(newMovie);
            newMovie=NULL;
        }
    }

    return newMovie;
}
void eMovie_delete(eMovie* unMovie)
{
    if(unMovie!=NULL)
    {
        free(unMovie);
    }
}


int eMovie_setId(eMovie* unMovie, int id)
{
    int error=1;

    if(unMovie!=NULL && id>0)
    {
        unMovie->id=id;
        error=0;
    }
    return error;
}
int eMovie_getId(eMovie* unMovie, int* id)
{
    int error=1;

    if(unMovie!=NULL && id!=NULL)
    {
        *id=unMovie->id;
        error=0;
    }
    return error;
}

int eMovie_setNombre(eMovie* unMovie, char nombre[])
{
    int error=1;

    if(unMovie!=NULL && nombre!=NULL)
    {
        if(strlen(nombre)<128 && strlen(nombre)>1)
        {
            strcpy(unMovie->nombre, nombre);
        }
        error=0;
    }
    return error;
}

int eMovie_getNombre(eMovie* unMovie, char* nombre)
{
    int error=1;
    if(unMovie!=NULL && nombre!=NULL)
    {
        strcpy(nombre, unMovie->nombre);
        error=0;
    }
    return error;
}

int eMovie_setGenero(eMovie* unMovie,char* genero)
{
      int error=1;

    if(unMovie!=NULL && genero!=NULL)
    {
        if(strlen(genero)<128 && strlen(genero)>1)
        {
            strcpy(unMovie->genero, genero);
        }
        error=0;
    }
    return error;
}
int eMovie_getGenero(eMovie* unMovie,char* genero)
{
       int error=1;
    if(unMovie!=NULL && genero!=NULL)
    {
        strcpy(genero, unMovie->genero);
        error=0;
    }
    return error;
}



int eMovie_setDuracion(eMovie* unMovie,int duracion)
{
    int error=1;

    if(unMovie!=NULL)
    {
        unMovie->duracion=duracion;
        error=0;
    }
    return error;
}

int eMovie_getDuracion(eMovie* unMovie,int* duracion)
{
    int error=1;

    if(unMovie!=NULL && duracion!=NULL)
    {
        *duracion=unMovie->duracion;
        error=0;
    }
    return error;
}





int eMovie_sortByGenero(void* eMovie1, void* eMovie2)
{
    int retorno=1;
    eMovie* aux1=(eMovie*) eMovie1;
    eMovie* aux2=(eMovie*) eMovie2;
    char genero1[128];
    char genero2[128];

    if(eMovie1!=NULL && eMovie2!=NULL)
    {
        eMovie_getGenero(aux1, genero1);
        eMovie_getGenero(aux2, genero2);

        retorno=strcmp(genero1, genero2);

        if(retorno>0)
        {
            retorno=1;
        }
        else if(retorno<0)
        {
            retorno=-1;
        }
        else if(retorno==0)
        {
            retorno=eMovie_sortByDuracion(eMovie1,eMovie2);
        }

    }

    return retorno;
}
int eMovie_sortByDuracion(void* eMovie1, void* eMovie2)
{
    int retorno=0;
    eMovie* aux1=(eMovie*) eMovie1;
    eMovie* aux2=(eMovie*) eMovie2;
    int id1;
    int id2;

    if(eMovie1!=NULL && eMovie2!=NULL)
    {
        eMovie_getId(aux1, &id1);
        eMovie_getId(aux2, &id2);

        if(id1>id2)
        {
            retorno=1;
        }
        else if(id1<id2)
        {
            retorno=-1;
        }
    }
    return retorno;
}
void* eMovie_asignarDuracion(void* unMovie)
{
    int duracion;
    int max=240;
    int min=100;


    if(unMovie!=NULL)
    {
        duracion = rand() % (max-min+1) + min;

        eMovie_setDuracion(unMovie,duracion);

    }
    return unMovie;
}
int eMovie_filtroGenero1(void* unMovie)
{
    int ret=0;

    char genero[128]={"Adventure"};

    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero2(void* unMovie)
{
    int ret=0;

    char genero[128]={"Drama"};




    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero3(void* unMovie)
{
    int ret=0;

char genero[128]={"Comedy"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero4(void* unMovie)
{
    int ret=0;

char genero[128]={"Romance"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero5(void* unMovie)
{
    int ret=0;

char genero[128]={"Documentary"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero6(void* unMovie)
{
    int ret=0;

char genero[128]={"Horror"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero7(void* unMovie)
{
    int ret=0;

char genero[128]={"Animation"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero8(void* unMovie)
{
    int ret=0;

char genero[128]={"Musical"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero9(void* unMovie)
{
    int ret=0;

char genero[128]={"Action"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero10(void* unMovie)
{
    int ret=0;

char genero[128]={"Western"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
int eMovie_filtroGenero11(void* unMovie)
{
    int ret=0;

char genero[128]={"Thriller"};


    char generoMovie[128];
    strcpy(generoMovie,((eMovie*)unMovie)->genero);

    if(strcmp(generoMovie,genero)==0)
    {
        ret=1;
    }
    return ret;
}
