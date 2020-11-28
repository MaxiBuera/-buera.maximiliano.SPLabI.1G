#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utn.h"
#include "Paises.h"
#include "LinkedList.h"
#include "Controller.h"
#include "informes.h"


int main()
{
    int option = 0;
    srand (time(NULL));  // esta linea va al inicio de main
    //int aleatorio;

    LinkedList* listaPaises = ll_newLinkedList();
    LinkedList* listaPaisesEstadistica = ll_newLinkedList();
    LinkedList* listaPaisesExitosos = ll_newLinkedList();
    LinkedList* listaPaisesEnElHorno = ll_newLinkedList();


    do{
        getValidInt("\n\n1- Cargar Lista\n2- Imprimir Lista\n3- Asignar Estadisticas\n4- Filtrar por paises exitosos\n5- Filtrar por paises en el horno\n6- Ordenar por nivel de infeccion\n7- Mostrar mas castigado\n8- Salir\n","No valida\n",&option,1,8,1);

        switch(option)
        {
            case 1:
                if(!controller_loadFromText("pandemia.csv",listaPaises)){
                    printf("\nPaises Cargados ...\n");
                }
                break;
            case 2:
                if(ll_len(listaPaises)!=0){
                    controller_List(listaPaises);
                }
                else{
                    printf("\nNo hay paises en la lista");
                }
                break;
            case 3:
                if(ll_len(listaPaises)!=0){

                    listaPaisesEstadistica = ll_map(listaPaises, asignarEstadistica);
                    if(listaPaisesEstadistica != NULL)
                    {
                        controller_List(listaPaisesEstadistica);
                    }
                    else
                    {
                        printf("Error\n");
                    }
                }
                else{
                    printf("\nNo hay paises en la lista");
                }
                break;
            case 4:
                if(ll_len(listaPaises)!=0){

                    listaPaisesExitosos = ll_filter(listaPaisesEstadistica, paisesExitosos);
                    if(listaPaisesExitosos != NULL)
                    {
                        //controller_List(listaPaisesExitosos);
                        controller_saveAsText("listaPaisesExitosos.csv",listaPaisesExitosos);
                          printf("\nArchivo Generado");
                    }
                    else
                    {
                        printf("Error\n");
                    }
                }
                else{
                    printf("\nNo hay paises en la lista");
                }
                break;
            case 5:
                if(ll_len(listaPaises)!=0){

                    listaPaisesEnElHorno = ll_filter(listaPaisesEstadistica, paisesEnElHorno);
                    if(listaPaisesEnElHorno != NULL)
                    {
                        //controller_List(listaPaisesEnElHorno);
                        controller_saveAsText("listaPaisesEnElHorno.csv",listaPaisesEnElHorno);
                        printf("\nArchivo Generado");
                    }
                    else
                    {
                        printf("Error\n");
                    }
                }
                else{
                    printf("\nNo hay paises en la lista");
                }
                break;
            case 6:
                if(ll_len(listaPaises)!=0){
                    ordenarPais(listaPaises);
                    controller_List(listaPaises);
                }
                else{
                    printf("\nNo hay paises en la lista");
                }
                break;
            case 7:
                if(ll_len(listaPaises)!=0){
                    //
                }
                else{
                    printf("\nError");
                }
                break;


        }
    }while(option != 10);
    return 0;
}
