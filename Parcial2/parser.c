#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "LinkedList.h"
#include "parser.h"
#include "Paises.h"


/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_PaisFromText(FILE* pFile , LinkedList* pArrayList)
{

    int retorno = -1;

    char id[4096];
    char nombre[4096];
    char recuperados[4096];
    char infectados[4096];
    char muertos[4096];


    Pais* auxPais;

    if(pFile != NULL && pArrayList != NULL){

        fseek ( pFile , 32L , SEEK_SET );

        while(!feof(pFile)){

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,recuperados,infectados,muertos);
            auxPais = pais_newParametros(id,nombre,recuperados,infectados,muertos);
            ll_add(pArrayList,auxPais);
        }
        retorno=0;
    }


    return retorno;
}

