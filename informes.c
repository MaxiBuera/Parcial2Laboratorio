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
#define PLANETA 1
#define SIGLO_XXI_EDITORES 2
#define MINOTAURO 4

int librosMinotauro(void* plibro)
{
    int retorno = -1;
    eLibro* libro = plibro;
    int idEditorial;

    if(plibro != NULL)
    {
        libro_getIdEditorial(libro, &idEditorial);

        if(idEditorial == MINOTAURO){

            retorno = 0;
        }

    }

    return retorno;
}

int librosConDescuento(void* plibro)
{
    int retorno = -1;
    eLibro* libro = plibro;
    int idEditorial;
    float precio;
    float precioConDescuento;
    int descuento;

    if(plibro != NULL)
    {
        libro_getIdEditorial(libro, &idEditorial);
        libro_getPrecio(libro, &precio);

        if(idEditorial == PLANETA){

        	if(precio >= 300){

        		descuento = (precio * 0.2);
        		precioConDescuento = precio - descuento;
        		libro_getPrecio(libro, &precioConDescuento);
        		//printf("\nACA: %f - %f - %d",precio,precioConDescuento,descuento);

                retorno = 0;
        	}
        }
        else if(idEditorial == SIGLO_XXI_EDITORES){

			if(precio <= 200){

				descuento = (precio * 0.1);
				precioConDescuento = precio - descuento;
				libro_getPrecio(libro, &precioConDescuento);
				//printf("\nACA: %f - %f - %d",precio,precioConDescuento,descuento);

				retorno = 0;
			}
		}

        else{

        	retorno = 0;
        }
    }

    return retorno;
}
