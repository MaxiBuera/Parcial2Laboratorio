#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Libro.h"
#include "Editorial.h"


/** \brief Parsea los datos los datos de los libros desde el archivo libros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayList)
{

    int retorno = -1;

    char id[4096];
    char titulo[4096];
    char autor[4096];
    char precio[4096];
    char idEditorial[4096];


    eLibro* auxLibro;

    if(pFile != NULL && pArrayList != NULL){

        fseek ( pFile , 34L , SEEK_SET );

        while(!feof(pFile)){

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,titulo,autor,precio,idEditorial);
            auxLibro = libro_newParametros(id,titulo,autor,precio,idEditorial);
            ll_add(pArrayList,auxLibro);
        }
        retorno=0;
    }


    return retorno;
}

int parser_EditorialesFromText(FILE* pFile , LinkedList* pArrayList)
{

    int retorno = -1;

    char id[4096];
    char nombre[4096];


    eEditorial* auxEditorial;

    if(pFile != NULL && pArrayList != NULL){

        fseek ( pFile , 18L , SEEK_SET );

        while(!feof(pFile)){

            fscanf(pFile,"%[^,],%[^,\n]\n",id,nombre);
            auxEditorial = editorial_newParametros(id,nombre);
            ll_add(pArrayList,auxEditorial);
        }
        retorno=0;
    }


    return retorno;
}

