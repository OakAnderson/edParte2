#include <stdlib.h>
#include "circulo.h"

#define PI 3.14159

typedef struct circulo{
    Ponto* centro;
    float r;
} Circulo;

Circulo* circ_cria( float x, float y, float r )
{
    Circulo* c = ( Circulo* ) malloc ( sizeof( Circulo ) );
    c->centro = pto_cria( x, y );
    c->r = r;

    return c;
}

void circ_libera( Circulo* c )
{
    pto_libera( c->centro );
    free( c );
}

float circ_area( Circulo* c )
{
    return PI * c->r * c->r;
}

int circ_interior( Circulo* c, Ponto* p )
{
    float d = pto_distancia(c->centro, p);
    return ( d < c->r );
}