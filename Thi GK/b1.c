#include <stdio.h>
int main(){
    double x,y,z;
    scanf("%lf %lf %lf",&x,&y,&z);
    if(0<x*y*z&&x*y*z<=45) printf("1.0");
    else if (45<x*y*z&&x*y*z<=60) printf("1.5");
    else if (60<x*y*z&&x*y*z<=80) printf("2.0");
    else if (80<x*y*z&&x*y*z<=120) printf("2.5");
    else if (120<x*y*z&&x*y*z<=180) printf("3.0");
    else printf("-1.0");
}