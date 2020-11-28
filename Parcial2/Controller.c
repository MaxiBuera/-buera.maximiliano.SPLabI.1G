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



/** \brief Listar paises
 *
 * \param pArrayList LinkedList*
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
    Pais* auxPais = NULL;

    int idStr;
    char nombreStr[51];
    int recuperadosStr;
    int infectadosStr;
    int muertosStr;


    if(pArrayList != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayList);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Nombre,Recuperados,Infectados,Muertos\n");
            for(i=0; i<len; i++)
            {
                auxPais = (Pais*) ll_get(pArrayList, i);
                pais_getId(auxPais, &idStr);
                pais_getNombre(auxPais, nombreStr);
                pais_getRecuperados(auxPais, &recuperadosStr);
                pais_getInfectados(auxPais, &infectadosStr);
                pais_getMuertos(auxPais, &muertosStr);

                fprintf(pFile, "%d,%s,%d,%d,%d\n", idStr, nombreStr, recuperadosStr, infectadosStr,muertosStr);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}




