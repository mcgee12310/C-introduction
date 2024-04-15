#include <stdio.h>
int main( void ){ 
    int x, y; 
    printf( "Enter a six digit integer: " );
    scanf( "%2d%d", &x, &y );
    printf( "The integers input were %d and %d\n", x, y );
return 0; /* indicates successful termination */
}