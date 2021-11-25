#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Libro.h"
#include "Editorial.h"


/** \brief  Formatea la cadena pasada por parametro (primer letra mayuscula)
 *
 * \param   cadena a formatear
 * \return
 *
 */
void controller_normalizeFields(char field[]){

    int j,i;
    i = strlen(field);

    for(j=0;j<i;j++){

        if(j==0){

            field[j] = toupper(field[j]);
        }
        else{

            field[j] = tolower(field[j]);
        }
    }
}

/** \brief Carga los datos de los paises desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_loadLibrosFromText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;


    FILE* pFile = NULL;
    pFile = fopen(path,"r");

    if(parser_LibroFromText(pFile,pArrayList)==0){

        retorno = 0;
    }


    fclose(pFile);

    return retorno;
}

int controller_loadEditorialesFromText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;


    FILE* pFile = NULL;
    pFile = fopen(path,"r");

    if(parser_EditorialesFromText(pFile,pArrayList)==0){

        retorno = 0;
    }


    fclose(pFile);

    return retorno;
}

int getDescripcionEditorial(LinkedList* pArrayList, int idEditorial)
{
    int retorno = -1;
    int i;
    int id;
    char nombre[100];

    eEditorial* auxEditorial = NULL;

    if(pArrayList != NULL)
    {

    	for(i=0;i<ll_len(pArrayList);i++){

    		auxEditorial = ll_get(pArrayList, i);

    		editorial_getId(auxEditorial,&id);
    		editorial_getNombre(auxEditorial,nombre);

    		if(idEditorial == id)
				printf("%22s\n",nombre);
    	}

        retorno = 0;
    }

    return retorno;
}


/** \brief Listar libros
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_List(LinkedList* pArrayList, LinkedList* pArrayList2)
{
    int i;
    int id;
    char titulo[100];
    char autor[100];
    float precio;
    int idEditorial;

    eLibro* auxLibro=NULL;

    if(pArrayList != NULL && pArrayList2 != NULL){

    	printf("\n");
        printf("%4s %18s %20s %20s %20s\n", "ID Libro:", "Titulo:", "Autor:", "Precio:", "Editorial:");

        for(i=0;i<ll_len(pArrayList);i++){

        	auxLibro = ll_get(pArrayList, i);

            libro_getId(auxLibro,&id);
            libro_getTitulo(auxLibro,titulo);
            libro_getAutor(auxLibro,autor);
            libro_getPrecio(auxLibro,&precio);
            libro_getIdEditorial(auxLibro,&idEditorial);

            printf("%4d %22s %20s %20.2f",id,titulo,autor,precio);

            getDescripcionEditorial(pArrayList2,idEditorial);
        }
    }

    return 1;
}

int controller_ListEditoriales(LinkedList* pArrayList)
{

    int i;
    int id;
    char nombre[100];


    eEditorial* auxEditorial=NULL;

    if(pArrayList != NULL){

    	printf("\n");
        printf("%4s %18s\n", "ID Editorial:", "Nombre:");

        for(i=0;i<ll_len(pArrayList);i++){

        	auxEditorial = ll_get(pArrayList, i);

            editorial_getId(auxEditorial,&id);
            editorial_getNombre(auxEditorial,nombre);


            printf("%4d %26s\n",id,nombre);
        }
    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayList)
{

    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    eLibro* auxPais = NULL;

    int idStr;
    char tituloStr[100];
    char autorStr[100];
    float precioStr;
    int idEditorialStr;


    if(pArrayList != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayList);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Titulo,Autor,Precio,IdEditorial\n");
            for(i=0; i<len; i++)
            {
                auxPais = (eLibro*) ll_get(pArrayList, i);
                libro_getId(auxPais, &idStr);
                libro_getTitulo(auxPais, tituloStr);
                libro_getAutor(auxPais, autorStr);
                libro_getPrecio(auxPais, &precioStr);
                libro_getIdEditorial(auxPais, &idEditorialStr);

                fprintf(pFile, "%d,%s,%s,%.2f,%d\n", idStr, tituloStr, autorStr, precioStr,idEditorialStr);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

int controller_ordenarPorAutor(LinkedList*pArray)
{
    int retorno=-1;

    if(pArray!=NULL)
    {
        if(!ll_sort(pArray,compararSegunAutor,0))
        {
        	printf("\nLista de Libros Ordenadas ...\n");
            retorno=0;
        }
    }

    return retorno;
}
