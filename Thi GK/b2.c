#include <stdio.h>
int main(){
    int d,m;
    scanf("%d-%d",&d,&m);
    switch(m){
        case 1:{
            if(1<=d&&d<=19) printf("Ma Ket");
            if(20<=d&&d<=31) printf("Bao Binh");
            break;
        }
        case 2:{
            if(1<=d&&d<=18) printf("Bao Binh");
            if(19<=d&&d<=29) printf("Song Ngu");
            break;
        }
        case 3:{
            if(1<=d&&d<=20) printf("Song Ngu");
            if(21<=d&&d<=31) printf("Bach Duong");
            break;
        }
        case 4:{
            if(1<=d&&d<=20) printf("Bach Duong");
            if(21<=d&&d<=30) printf("Kim Nguu");
            break;
        }
        case 5:{
            if(1<=d&&d<=20) printf("Kim Nguu");
            if(21<=d&&d<=31) printf("Song Tu");
            break;
        }
        case 6:{
            if(1<=d&&d<=21) printf("Song Tu");
            if(22<=d&&d<=30) printf("Cu Giai");
            break;
        }
        case 7:{
            if(1<=d&&d<=22) printf("Cu Giai");
            if(23<=d&&d<=31) printf("Su Tu");
            break;
        }
        case 8:{
            if(1<=d&&d<=22) printf("Su Tu");
            if(23<=d&&d<=31) printf("Xu Nu");
            break;
        }
        case 9:{
            if(1<=d&&d<=22) printf("Xu Nu");
            if(23<=d&&d<=30) printf("Thien Binh");
            break;
        }
        case 10:{
            if(1<=d&&d<=23) printf("Thien Binh");
            if(24<=d&&d<=31) printf("Bo Cap");
            break;
        }
        case 11:{
            if(1<=d&&d<=22) printf("Bo Cap");
            if(23<=d&&d<=30) printf("Nhan Ma");
            break;
        }
        case 12:{
            if(1<=d&&d<=21) printf("Nhan Ma");
            if(22<=d&&d<=31) printf("Ma Ket");
            break;
        }
    }
}