#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

typedef struct
{
    int id;
    char titulo[100];
    char autor[100];
    float precio;
    int idEditorial;
}eLibro;

#endif // LIBRO_H_INCLUDED

eLibro* libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* idEditorialStr);
eLibro* libro_newParametros2(char* titulo,char* autor,float infectados,int idEditorial);
eLibro* libro_newParametros3(int id,char* titulo,char* autor,float precio,int idEditorial);
eLibro* libro_newParametros4(int id,char* titulo,char* autor,float precio, int idEditorial);
eLibro* libro_new();
void libro_delete(eLibro* this);

int libro_setId(eLibro* this,int id);
int libro_getId(eLibro* this,int* id);

char libro_setTitulo(eLibro* this,char* nombre);
char libro_getTitulo(eLibro* this,char* nombre);

char libro_setAutor(eLibro* this,char* autor);
char libro_getAutor(eLibro* this,char* autor);

float libro_setPrecio(eLibro* this,float precio);
float libro_getPrecio(eLibro* this,float* precio);

int libro_setIdEditorial(eLibro* this, int idEditorial);
int libro_getIdEditorial(eLibro* this, int* idEditorial);

int compararSegunAutor(void* libro1,void* libro2);

int proximoIdLibro();
