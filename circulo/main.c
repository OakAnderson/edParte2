#include <stdio.h>
#include "circulo.h"
#include "ponto.h"

int main( void )
{
    Circulo* a = circ_cria( 5.0, 5.5, 6.5 );
    Ponto* b = pto_cria( 5.6, 6.2 );

    float area = circ_area( a );
    printf( " A área do círculo é %.2f\n", area );

    int inside = circ_interior( a, b );
    if( inside )
    {
        printf( "O ponto está dentro do círculo\n" );
    }
    else
    {
        printf( "O ponto não está dentro do círculo\n" );
    }

    pto_libera( b );
    circ_libera( a );
    
    return 0;
}