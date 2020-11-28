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

/** \brief Ordenar Paises por cantidad de infectados
 *
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int ordenarPais(LinkedList* pArrayList)
{
    int retorno = -1;
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
