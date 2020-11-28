#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "Paises.h"

int proximoIdPais();


Pais* pais_newParametros(char* idStr,char* nombreStr,char* recuperadosStr,char* infectadosStr, char* muertosStr)
{
    Pais* this;
    this = pais_new();

    int id;
    char nombre[128];
    int recuperados;
    int infectados;
    int muertos;

    id = atoi(idStr);
    strcpy(nombre,nombreStr);
    recuperados = atoi(recuperadosStr);
    infectados = atoi(infectadosStr);
    muertos = atoi(muertosStr);

    pais_setId(this,id);
    pais_setNombre(this,nombre);
    pais_setRecuperados(this,recuperados);
    pais_setInfectados(this,infectados);
    pais_setMuertos(this,muertos);

    return this;
}

Pais* pais_newParametros2(char* nombre,int recuperados,int infectados,int muertos){

    Pais* this;
    this = pais_new();

    if(     !pais_setId(this, proximoIdPais())
       &&   !pais_setNombre(this, nombre)
       &&   !pais_setRecuperados(this, recuperados)
       &&   !pais_setInfectados(this,infectados)
       &&   !pais_setMuertos(this,muertos))
    {
         return this;
    }
    pais_delete(this);
    return NULL;
}

Pais* pais_newParametros3(int id,char* nombre,int recuperados,int infectados, int muertos){

    Pais* this;
    this = pais_new();

    if(     !pais_setId(this, id)
       &&   !pais_setNombre(this, nombre)
       &&   !pais_setRecuperados(this, recuperados)
       &&   !pais_setInfectados(this,infectados)
       &&   !pais_setMuertos(this,muertos))
    {
         return this;
    }
    pais_delete(this);
    return NULL;
}

Pais* pais_newParametros4(int id,char* nombre,int recuperados,int infectados, int muertos){

    Pais* this;
    this = pais_new();

    if(     !pais_setId(this, proximoIdPais())
       &&   !pais_setNombre(this, nombre)
       &&   !pais_setRecuperados(this, recuperados)
       &&   !pais_setInfectados(this,infectados)
       &&   !pais_setMuertos(this,muertos))
    {
         return this;
    }
    pais_delete(this);
    return NULL;
}

Pais* pais_new()
{
    return malloc(sizeof(Pais));
}

void pais_delete(Pais* this)
{
    free(this);
}


int  pais_setId(Pais* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {

        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int pais_getId(Pais* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {

        *id = this->id;
         retorno = 0;
    }
    return retorno;
}


char  pais_setNombre(Pais* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre >= 0)
    {

        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}


char pais_getNombre(Pais* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {

        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;

}

int  pais_setRecuperados(Pais* this, int recuperados)
{
    int retorno = -1;
    if(this != NULL && recuperados >= 0)
    {

        this->recuperados = recuperados;
        retorno = 0;
    }
    return retorno;
}

int pais_getRecuperados(Pais* this, int* recuperados)
{
    int retorno = -1;
    if(this != NULL && recuperados != NULL)
    {

        *recuperados = this->recuperados;
         retorno = 0;
    }
    return retorno;
}

int  pais_setInfectados(Pais* this, int infectados)
{
    int retorno = -1;
    if(this != NULL && infectados >= 0)
    {

        this->infectados = infectados;
        retorno = 0;
    }
    return retorno;
}

int pais_getInfectados(Pais* this, int* infectados)
{
    int retorno = -1;
    if(this != NULL && infectados != NULL)
    {

        *infectados = this->infectados;
         retorno = 0;
    }
    return retorno;
}

int  pais_setMuertos(Pais* this, int muertos)
{
    int retorno = -1;
    if(this != NULL && muertos >= 0)
    {

        this->muertos = muertos;
        retorno = 0;
    }
    return retorno;
}

int pais_getMuertos(Pais* this, int* muertos)
{
    int retorno = -1;
    if(this != NULL && muertos != NULL)
    {

        *muertos = this->muertos;
         retorno = 0;
    }
    return retorno;
}

int proximoIdPais()
{
    static int ultimoId = 0;
    ultimoId++;
    return ultimoId;
}
