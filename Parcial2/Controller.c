#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#include "utn.h"
#include "LinkedList.h"
#include "parser.h"
#include "Paises.h"


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
int controller_loadFromText(char* path , LinkedList* pArrayList)
{
    int retorno = -1;


    FILE* pFile = NULL;
    pFile = fopen(path,"r");

    if(parser_PaisFromText(pFile,pArrayList)==0){

        retorno = 0;
    }


    fclose(pFile);

    return retorno;
}

int asignarEstadistica(void* pPais)
{
    int retorno = -1;
    Pais* pais = pPais;

    int recuperadosAsignar = rand()%((50000-1000) + 1)+1000; //50k y 1000k
    int infectadosAsignar = rand()%((400000-2000) + 1)+2000; //400k y 2000k
    int muertosAsignar = rand()%((50000-1000) + 1)+1000; //1k y 50k

    if(pais != NULL)
    {
        pais_setRecuperados(pais, recuperadosAsignar);
        pais_setInfectados(pais, infectadosAsignar);
        pais_setMuertos(pais, muertosAsignar);

        retorno = 0;
    }

    return retorno;
}

int paisesExitosos(void* pPais)
{
    int retorno = -1;
    Pais* pais = pPais;
    int recuperados;

    if(pais != NULL)
    {
        pais_getRecuperados(pais, &recuperados);

        if(recuperados < 5000){

            retorno = 0;
        }

    }

    return retorno;
}

int paisesEnElHorno(void* pPais)
{
    int retorno = -1;
    Pais* pais = pPais;
    int recuperados;
    int infectados;

    if(pais != NULL)
    {
        pais_getRecuperados(pais, &recuperados);
        pais_getInfectados(pais, &infectados);

        if(infectados == recuperados * 3){

            retorno = 0;
        }

    }

    return retorno;
}

/** \brief Listar paises
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_List(LinkedList* pArrayList)
{

    int i;
    int id;
    char nombre[50];
    int recuperados;
    int infectados;
    int muertos;

    Pais* auxPais=NULL;

    system("cls");

    if(pArrayList != NULL){

        printf("%4s %18s %20s %20s %20s\n", "ID:", "Nombre:", "Recuperados:", "Infectados:", "Muertos:");

        for(i=0;i<ll_len(pArrayList);i++){

            auxPais = ll_get(pArrayList, i);

            pais_getId(auxPais,&id);
            pais_getNombre(auxPais,nombre);
            pais_getRecuperados(auxPais,&recuperados);
            pais_getInfectados(auxPais,&infectados);
            pais_getMuertos(auxPais,&muertos);


            printf("%4d %18s %20d %20d %20d\n",id,nombre,recuperados,infectados,muertos);
        }
    }

    return 1;
}



/** \brief Ordenar Paises por cantidad de infectados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ordenarPais(LinkedList* pArrayList)
{
    int retorno = -1;
    /*int infectados;
    int infectados2;*/
    int flagSwap;
    int i;
    int orden = 0;
    int flagAviso = 0;


    Pais* auxPais=NULL;
    Pais* auxPais2=NULL;
    Pais* auxSwap=NULL;

    if( pArrayList != NULL)
    {

        retorno = 0;
        do
        {
            if(flagAviso == 0){
                printf("\nOrdenando Lista ..\n");
                flagAviso = 1;
            }

            flagSwap = 0;
            for(i=0;i<ll_len(pArrayList) -1;i++)
            {

                auxPais = ll_get(pArrayList, i);
                auxPais2 = ll_get(pArrayList, i+1);

                if(auxPais != NULL && auxPais2 != NULL )
                {

                        if((auxPais->infectados > auxPais2->infectados && !orden) || (auxPais->infectados < auxPais2->infectados && orden)) //<------------
                        {
                            auxSwap = auxPais;
                          //printf("\n%s",auxSwap->nombre);

                            auxPais = auxPais2;
                            auxPais2 = auxSwap;

                            ll_set(pArrayList,i,auxPais);
                            ll_set(pArrayList,i+1,auxPais2);


                            flagSwap = 1;
                        }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}

/*int paisMasCastigado(LinkedList* this)
{
    int retorno = -1;
    int i;
    int cantidadMayorDeMuertos = 0;

    if(this != NULL){

        for(i=0;i<ll_len(this);i++){

            if(cantidadMayorDeMuertos < )
        }
    }

}*/



