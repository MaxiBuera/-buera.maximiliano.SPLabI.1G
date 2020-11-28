#ifndef PAISES_H_INCLUDED
#define PAISES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;
}Pais;

#endif // PAISES_H_INCLUDED

Pais* pais_newParametros(char* idStr,char* nombreStr,char* recuperadosStr,char* infectadosStr, char* muertosStr);
Pais* pais_newParametros2(char* nombre,int recuperados,int infectados,int muertos);
Pais* pais_newParametros3(int id,char* nombre,int recuperados,int infectados,int muertos);
Pais* pais_newParametros4(int id,char* nombre,int recuperados,int infectados, int muertos);
Pais* pais_new();
void pais_delete(Pais* this);

int pais_setId(Pais* this,int id);
int pais_getId(Pais* this,int* id);

char pais_setNombre(Pais* this,char* nombre);
char pais_getNombre(Pais* this,char* nombre);

int pais_setRecuperados(Pais* this,int recuperados);
int pais_getRecuperados(Pais* this,int* recuperados);

int pais_setInfectados(Pais* this,int infectados);
int pais_getInfectados(Pais* this,int* infectados);

int pais_setMuertos(Pais* this, int muertos);
int pais_getMuertos(Pais* this, int* muertos);

int proximoIdPais();
