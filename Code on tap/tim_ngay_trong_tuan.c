#include <stdio.h>
int dayofweek(int d, int m, int y){
   static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   y -= m < 3;
   return (y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;
}
int main(){
   int d,m;
   scanf("%d %d",&d,&m);
   if(
      m>12||
      d>31&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12)||
      d>30&&(m==4||m==6||m==9||m==11)||
      d>28&&m==2
   ){
      printf("INVALID");
      return 0;
   } 
   int day = dayofweek(d, m, 2023);
   switch(day){
      case 1:{
         printf("MON");
         break;
      } 
      case 2:{
         printf("TUE");
         break;
      } 
      case 3:{
         printf("WED");
         break;
      } 
      case 4:{
         printf("THU");
         break;
      } 
      case 5:{
         printf("FRI");
         break;
      } 
      case 6:{
         printf("SAT");
         break;
      } 
      case 0:{
         printf("SUN");
         break;
      } 
   }
   return 0;
}