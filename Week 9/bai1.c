/* Viết hàm tính động năng của một vật ke= mv2/2, với m là khối lượng (kg) và v là tốc độ (m/s) */
#include <stdio.h>
double kineticEnergy(double m, double v){
    return m*v*v/2;
    }
void main(){
    double m, v;
    do {
        printf("Enter mass:"); 
        scanf("%lf",&m);
        printf("Enter speed:"); 
        scanf("%lf",&v);
        printf("Kinetic Energy of element is:%.2lf \n", kineticEnergy(m,v));
    } 
    while (m>0 && v >=0);
    }