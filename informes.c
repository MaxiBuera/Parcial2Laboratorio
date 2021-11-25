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

int librosMinotauro(void* plibro)
{
    int retorno = -1;
    eLibro* libro = plibro;
    int idEditorial;

    if(plibro != NULL)
    {
        libro_getIdEditorial(libro, &idEditorial);

        if(idEditorial == 4){ // ID 4 -> Minotauro

            retorno = 0;
        }

    }

    return retorno;
}
