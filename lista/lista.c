#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct lista
{
    int info;
    struct lista* prox;
} Lista;


/*Função que cria uma lista vazia */
Lista* lst_cria( void )
{
    return NULL;
}

/* Inserção no início: retorna a lista atualizada */
void lst_insere( Lista** l, int i )
{
    Lista* novo = ( Lista* ) malloc ( sizeof( Lista ) );
    novo->info = i;
    novo-> prox = *l;
    *l = novo;
}

/* Função imprime: imprime os valores dos elementos */
void lst_imprime( Lista* l )
{
    Lista* p;   //Variável auxiliar para percorrer a lista

    printf("[");

    for( p = l; p != NULL; p = p->prox )
    {
        printf("%d, ", p->info);
    }
    printf("]\n");
}

/* Função vazia: retorna 1 se vazia ou 0 se não vazia */
int lst_vazia( Lista* l )
{
    return ( l != NULL );
}

/* Função busca: busca um elemento na lista */
Lista* lst_busca( Lista* l, int v )
{
    Lista* p;
    for( p = l; p != NULL; p = p->prox )
    {
        if( p->info == v)
        {
            return p;
        }
    }
    return NULL;
}

/* Função retira: retira o elemento da lista */
void lst_retira( Lista** l, int v )
{
    Lista* ant = NULL;  //Ponteiro para o elemento anterior
    Lista* p = *l;       //Ponteiro para percorrer a lista

    /* Procura elemento na lista, guardando anterior */
    while( p != NULL && p->info != v )
    {
        ant = p;
        p = p->prox;
    }
    
    /* Verfica se achou o elemento */
    if( p == NULL )
    {
        printf("Elemento não encontrado.\n "); //Não achou, retorna a lista original
    }

    /* Retira o elemento */
    if( ant == NULL )
    {
        /* Retira o elemento do início */
        *l = p->prox;
    }
    else
    {
        /* Retira o elemento do meio da lista */
        ant->prox = p->prox;
    }
    free( p );
}

/* Função libera: Função que libera o espaço alocado pela lista */
void lst_libera( Lista* l )
{
    Lista* p;
    for( p = l; p!= NULL; p = p->prox )
    {
        free( p );
    }
}

/* Função insere ordenado: Função que insere um elemento
** a uma lista de forma ordenada */
Lista* lst_insere_ordenado( Lista* l, int v )
{
    Lista* novo;
    Lista* ant = NULL;  //Ponteiro para o elemento anterior
    Lista* p = l;       //Ponteiro para percorrer a lista

    /*Procura posição de inserção */
    while (p != NULL && p->info < v)
    {
        ant = p;
        p = p->prox;
    }

    /*Cria novo elemento */
    novo = ( Lista* ) malloc ( sizeof(Lista) );
    novo ->info = v;

    /*Encadeia elemento */
    if( ant == NULL )
    {
        novo->prox = l;     //Insere no início
        l = novo;
    }

    else
    {
        novo->prox = ant->prox; //Insere no meio da lista
        ant->prox = novo;
    }

    return l;
}