#include <stdio.h>
#include "matriz.h"

void atribui( Matriz* mat )
{
    int m = mat_linhas( mat ), n = mat_colunas( mat );
    float valor;

    for( int i = 0; i < m; i++ )
    {
        for( int j = 0; j < n; j++ )
        {
            printf("Posição [%d, %d]: ", i+1, j+1);
            scanf( " %f", &valor );

            mat_atribui( mat, i, j, valor );
        }
    }
}


int main( void )
{
    Matriz* m = mat_cria( 3, 3 );

    atribui( m );

    printf( "%f.2\n", mat_acessa( m, 0, 0 ) );

    mat_mostra( m );

    mat_libera( m );

    return 0;
}