#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
    int id;
    char nombre[100];
}eEditorial;

#endif /* EDITORIAL_H_ */

eEditorial* editorial_newParametros(char* idStr,char* nombreStr);
eEditorial* editorial_new();
void editorial_delete(eEditorial* this);
int editorial_setId(eEditorial* this, int id);
int editorial_getId(eEditorial* this, int* id);
char editorial_setNombre(eEditorial* this, char* nombre);
char editorial_getNombre(eEditorial* this, char* nombre);
