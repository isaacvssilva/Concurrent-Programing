/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  -
 *
 *        Version:  1.0
 *        Created:  01/12/2022 08:16:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Isaac Vinicius, isaacvinicius2121@alu.ufc.br
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t t1;   /*identificador da thread 1*/
pthread_t t2;   /*identificador da thread 2*/

/*espera passar 10 segundos*/
void task1(){
    for(int i = 0; i<10; i++){
        sleep(1);
        printf("Tarefa 1: passaram %d segundos\n", i+1);
    }
}

/*espera passar 20 segundos*/
void task2(){
    for(int i = 0; i<20; i++){
        sleep(1);
        printf("Tarefa 2: passaram %d segundos\n", i+1);
    }
}

int main(){
    printf("inicio\n");
    /*parametros: address da thread, atributo, nome da funcao, parametro da thread a criacao*/
    pthread_create(&t1, NULL, (void*) task1, NULL);

    /*parametros: address da thread, atributo, nome da funcao, parametro da thread a criacao*/
    pthread_create(&t2, NULL, (void*) task2, NULL);

    /*bloquea a main ate t1 terminar. parametros: thread, motivo do termino*/
    pthread_join(t1, NULL);

    /*bloquea a main ate t2 terminar. parametros: thread, motivo do termino*/
    pthread_join(t2, NULL);

    printf("Fim\n");
    return(0);
}