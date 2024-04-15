#include <stdio.h>
/* function main begins program execution */
int main( void ){ 
    char z[ 9 ]; 
    printf( "Enter string: " );
    scanf( "%s[aeiou]", &z ); /* search for set of characters */
    printf( "The input was \"%s\"\n", z );
return 0; 
}