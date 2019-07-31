#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"

typedef struct matriz
{
    int lin, col;
    float** v;
} Matriz;


Matriz* mat_cria( int m, int n )
{
    Matriz* mat = ( Matriz* ) malloc ( sizeof( Matriz ) );

    if( m < 0 || n < 0 )
    {
        printf( "Impossível criar uma matriz com esses valores\n" );
        exit( 1 );
    }

    mat->lin = m;       //Guarda os valores das linhas e das colunas
    mat->col = n;

    mat->v = ( float** ) malloc ( m*sizeof( float* ) ); //Aloca as linhas
    for( int i = 0; i < m; i++ )        //Aloca as colunas
    {
        mat->v[i] = ( float* ) malloc ( n*sizeof( float ) );
    }

    if( mat == NULL )
    {
        printf( "Memória insuficiente\n" );
        exit( 1 );
    }

    for( int i = 0; i < m; i++)     //Limpa a memória atribuindo 0.0 a todos os espaços
    {
        for( int j = 0; j < n; j++ )
        {
            mat->v[i][j] = 0.0;
        }
    }

    return mat;     //Retorna a estrutura de uma matriz
}

void mat_libera( Matriz* mat )
{
    for( int i = 0; i < mat->lin; i++ )     //Libera o espaço das colunas
    {
        free( mat->v[i] );
    }

    free( mat->v );     //Libera o espaço das linhas
}

float mat_acessa( Matriz* mat, int i, int j )
{
    if( i > mat->lin || i < 0 )     //Verifica se o valor informado para a linha é válido
    {
        printf( "Impossível acessar a linha do valor informado\n" );
        exit(1);
    }

    else if ( j > mat->col || j < 0) //Verifica se o valor informado para a coluna é válido
    {
        printf( "Impossível acessar a coluna do valor informado\n" );
        exit(1);
    }

    return mat->v[i][j];        //retorna o valor da posição
}

void mat_atribui( Matriz* mat, int i, int j, float v )
{
    if( i > mat->lin || i < 0 )     //Verifica se o valor informado para a linha é válido
    {
        printf( "Impossível acessar a linha do valor informado\n" );
        exit(1);
    }

    else if ( j > mat->col || j < 0)    //Verifica se o valor informado para a coluna é válido
    {
        printf( "Impossível acessar a coluna do valor informado\n" );
        exit(1);
    }
    
    mat->v[i][j] = v;       //Atribui o valor passado na posição passada
}

int mat_linhas( Matriz* mat )
{
    return mat->lin;    //Retorna o número de linhas
}

int mat_colunas( Matriz* mat )
{
    return mat->col;    //Retorna o número de colunas
}

void mat_mostra( Matriz* mat )
{
    printf("\n");
    for( int i = 0; i < mat->lin; i++ )
    {
        for( int j = 0; j < mat->col; j++ )
        {
            printf( "%4.4f ", mat_acessa( mat, i, j ) );
        }
        printf("\n");
    }
    printf("\n");
}