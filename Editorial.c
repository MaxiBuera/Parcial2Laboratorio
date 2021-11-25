#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "editorial.h"


eEditorial* editorial_newParametros(char* idStr,char* nombreStr)
{
	eEditorial* this;
    this = editorial_new();

    int id;
    char nombre[100];

    id = atoi(idStr);
    strcpy(nombre,nombreStr);

    editorial_setId(this,id);
    editorial_setNombre(this,nombre);

    return this;
}

eEditorial* editorial_new()
{
    return malloc(sizeof(eEditorial));
}

void editorial_delete(eEditorial* this)
{
    free(this);
}

int editorial_setId(eEditorial* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {

        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int editorial_getId(eEditorial* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
         retorno = 0;
    }
    return retorno;
}


char editorial_setNombre(eEditorial* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre >= 0)
    {

        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


char editorial_getNombre(eEditorial* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;

}
