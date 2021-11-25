#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Libro.h"

int proximoIdLibro();

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* idEditorialStr)
{
    eLibro* this;
    this = libro_new();

    int id;
    char titulo[100];
    char autor[100];
    float precio;
    int idEditorial;

    id = atoi(idStr);
    strcpy(titulo,tituloStr);
    strcpy(autor,autorStr);
    precio = atof(precioStr);
    idEditorial = atoi(idEditorialStr);

    libro_setId(this,id);
    libro_setTitulo(this,titulo);
    libro_setAutor(this,autor);
    libro_setPrecio(this,precio);
    libro_setIdEditorial(this,idEditorial);

    return this;
}

eLibro* libro_newParametros2(char* titulo,char* autor,float precio,int idEditorial){

    eLibro* this;
    this = libro_new();

    if(     !libro_setId(this, proximoIdLibro())
       &&   !libro_setTitulo(this, titulo)
       &&   !libro_setAutor(this, autor)
       &&   !libro_setPrecio(this,precio)
       &&   !libro_setIdEditorial(this,idEditorial))
    {
         return this;
    }
    libro_delete(this);
    return NULL;
}

eLibro* libro_newParametros3(int id,char* titulo,char* autor,float precio, int idEditorial){

    eLibro* this;
    this = libro_new();

    if(     !libro_setId(this, id)
       &&   !libro_setTitulo(this, titulo)
       &&   !libro_setAutor(this, autor)
       &&   !libro_setPrecio(this,precio)
       &&   !libro_setIdEditorial(this,idEditorial))
    {
         return this;
    }
    libro_delete(this);
    return NULL;
}

eLibro* libro_newParametros4(int id,char* titulo,char* autor,float precio, int idEditorial){

    eLibro* this;
    this = libro_new();

    if(     !libro_setId(this, proximoIdLibro())
       &&   !libro_setTitulo(this, titulo)
       &&   !libro_setAutor(this, autor)
       &&   !libro_setPrecio(this,precio)
       &&   !libro_setIdEditorial(this,idEditorial))
    {
         return this;
    }
    libro_delete(this);
    return NULL;
}

eLibro* libro_new()
{
    return malloc(sizeof(eLibro));
}

void libro_delete(eLibro* this)
{
    free(this);
}


int  libro_setId(eLibro* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {

        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int libro_getId(eLibro* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
         retorno = 0;
    }
    return retorno;
}


char  libro_setTitulo(eLibro* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo >= 0)
    {

        strcpy(this->titulo,titulo);
        retorno = 0;
    }
    return retorno;
}


char libro_getTitulo(eLibro* this, char* titulo)
{
    int retorno = -1;
    if(this != NULL && titulo != NULL)
    {

        strcpy(titulo,this->titulo);
        retorno = 0;
    }
    return retorno;

}

char  libro_setAutor(eLibro* this, char* autor)
{
    int retorno = -1;
    if(this != NULL && autor >= 0)
    {

        strcpy(this->autor,autor);
        retorno = 0;
    }
    return retorno;
}


char libro_getAutor(eLibro* this, char* autor)
{
    int retorno = -1;
    if(this != NULL && autor != NULL)
    {

        strcpy(autor,this->autor);
        retorno = 0;
    }
    return retorno;

}

float libro_setPrecio(eLibro* this, float precio)
{
    int retorno = -1;
    if(this != NULL && precio >= 0)
    {

        this->precio = precio;
        retorno = 0;
    }
    return retorno;
}

float libro_getPrecio(eLibro* this, float* precio)
{
    int retorno = -1;
    if(this != NULL && precio != NULL)
    {

        *precio = this->precio;
         retorno = 0;
    }
    return retorno;
}

int  libro_setIdEditorial(eLibro* this, int idEditorial)
{
    int retorno = -1;
    if(this != NULL && idEditorial >= 0)
    {

        this->idEditorial = idEditorial;
        retorno = 0;
    }
    return retorno;
}

int libro_getIdEditorial(eLibro* this, int* idEditorial)
{
    int retorno = -1;
    if(this != NULL && idEditorial != NULL)
    {

        *idEditorial = this->idEditorial;
         retorno = 0;
    }
    return retorno;
}


int compararSegunAutor(void* libro1,void* libro2)
{
    int retorno=0;
    eLibro* l1= (eLibro*) libro1;
    eLibro* l2= (eLibro*) libro2;
    char autor1[100];
    char autor2[100];

    if(libro1!=NULL && libro2!=NULL)
    {
        libro_getAutor(l1,autor1);
        libro_getAutor(l2,autor2);

        if((strcmp(l1->autor,l2->autor) > 0))
        {
            retorno=-1;
        }else if(strcmp(l1->autor,l2->autor) < 0)
        {
            retorno=1;
        }
    }

    return retorno;
}

int proximoIdLibro()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}
