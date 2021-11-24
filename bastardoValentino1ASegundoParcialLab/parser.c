#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Movies.h"


int parser_MovieFromText(FILE* pFile, LinkedList* pArrayListMovie)
{
    eMovie* auxMovie;
    int ret=0;
    char buffer[1][5];
    char auxNombre[128];
    char auxGenero[128];

    if(pFile != NULL && pArrayListMovie !=NULL)
    {
       fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], auxNombre, auxGenero, buffer[1]);
        do
        {
            if((fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], auxNombre, auxGenero, buffer[1]))==4)
            {
                auxMovie=eMovie_newParametros(buffer[0],auxNombre,auxGenero,buffer[1]);
                if(auxMovie!=NULL)
                {
                    ll_add(pArrayListMovie,auxMovie);
                    ret=1;
                }
            }
        }
        while(!feof(pFile));
    }

    return ret;
}


int parser_MovieFromBinary(FILE* pFile, LinkedList* pArrayListMovie)
{
    int ret=1;
    eMovie* auxMovie;

    if(pFile!=NULL && pArrayListMovie!=NULL)
    {
        do
        {
            auxMovie=eMovie_new();
            fread(auxMovie, sizeof(eMovie), 1, pFile);

            if(!feof(pFile))
            {
                if(ll_add(pArrayListMovie, auxMovie)!=0)
                {
                    eMovie_delete(auxMovie);
                    ret=1;
                    break;
                }
                else
                {
                    ret=0;
                }
            }
            else
            {
                break;
            }
        }
        while(!feof(pFile));

    }
    return ret;
}

