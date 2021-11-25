#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utn.h"
#include "Libro.h"
#include "LinkedList.h"
#include "Controller.h"
#include "informes.h"



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditoriales = ll_newLinkedList();
    LinkedList* listaLibrosMinotauro = ll_newLinkedList();
    LinkedList* listaConDescuentos = ll_newLinkedList();

    do{
        getValidInt("\n\n1- Cargar Datos de libros\n"
					"2- Cargar Datos de editoriales\n"
					"3- Ordenar la lista de Libros\n"
					"4- Imprimir Lista de Libros\n"
					"5- Lista de libros de la editorial MINOTAURO\n"
        			"6- Lista de libros con descuentos\n"
					"7- Salir\n","No valida\n",&option,1,7,1);

        switch(option)
        {
            case 1:
                if(!controller_loadLibrosFromText("libros.csv",listaLibros)){
                    printf("\nLibros Cargados ...\n");
                }
                break;
            case 2:
            	if(!controller_loadEditorialesFromText("editoriales.csv",listaEditoriales)){
            		printf("\nEditoriales Cargadas ...\n");
            	}
            	break;
            case 3:
                if(ll_len(listaLibros)!=0){

                	controller_ordenarPorAutor(listaLibros);
                }
                else{
                    printf("\nNo hay libros cargados en la lista");
                }
                break;
            case 4:
            	if(ll_len(listaLibros)!=0 && ll_len(listaEditoriales)!=0){

                	//controller_ListEditoriales(listaEditoriales);
                	controller_List(listaLibros,listaEditoriales);
                }
                else{
                    printf("\nNo hay libros y/o editoriales cargados en la lista");
                }
                break;
            case 5:
                if(ll_len(listaLibros)!=0){

                	listaLibrosMinotauro = ll_filter(listaLibros,librosMinotauro);
                	if(listaLibrosMinotauro != NULL)
                	{
                		//controller_List(listaLibrosMinotauro,listaEditoriales);
                		controller_saveAsText("librosminotauro.csv",listaLibrosMinotauro);
                	    printf("\nArchivo Generado ...");
                	}
                	else
                	{
                		printf("Error\n");
                	}
                }
                else{
                	printf("\nNo hay libros y/o editoriales cargados en la lista");
                }
                break;
            case 6:
            	if(ll_len(listaLibros)!=0 && ll_len(listaEditoriales)!=0){

					listaConDescuentos = ll_map(listaLibros, librosConDescuento);
            		if(listaConDescuentos != NULL)
            		{
						controller_List(listaConDescuentos,listaEditoriales);
						controller_saveAsText("mapeado.csv",listaConDescuentos);
						printf("\nArchivo Generado ...");
            		}
            		else{
            			printf("Error\n");
            		}
            	}
                break;
        }
    }while(option != 7);
    return 0;
}
