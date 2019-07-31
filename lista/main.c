#include <stdio.h>
#include "lista.h"

int main( void )
{
    Lista* l;           //Declara uma lista não iniciada
    l = lst_cria( );    //Inicia a lista vazia

    lst_insere( &l, 23 );    //Insere o elemento 23
    lst_insere( &l, 45 );    //Insere o elemento 45
    lst_insere( &l, 56 );    //Insere o elemento 56
    lst_insere( &l, 78 );    //Insere o elemento 78

    lst_imprime( l );       //Mostra [23, 45, 56, 78,]

    lst_retira( &l, 78 );    //Retira o elemento 78
    lst_imprime( l );       //Mostra [23, 45, 56,]

    lst_retira( &l, 45 );    //Retira o elemento 45
    lst_imprime( l );       //Mostra[23, 56,]

    lst_libera( l );        //Libera a memória

    return 0;
}