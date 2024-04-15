#include <stdio.h>
#include <math.h>

typedef struct point{
    double x;
    double y;
} point_t;
typedef struct circle{
    point_t center;
    double radius;
} circle_t;

point_t input_point(){
    point_t tmp;
    printf("nhap thong so diem");
    scanf("%lf %lf",&tmp.x,&tmp.y); 
    return tmp;
}
circle_t input_circle(){
    circle_t tmp;
    printf("nhap thong so hinh tron");
    scanf("%lf %lf %lf",&tmp.center.x,&tmp.center.y,&tmp.radius);
    return tmp; 
}

int is_in_circle(const circle_t *c,const point_t *a){
    double x1=a->x;
    double y1=a->y;
    double x2=c->center.x;
    double y2=c->center.y;
    double r=c->radius;
    if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))<=r) return 1;
    else return 0 ;
}

int main(){
    circle_t c;
    point_t a;
    c=input_circle();
    a=input_point();
    printf("%d",is_in_circle(&c,&a));
}