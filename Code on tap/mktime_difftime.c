#include <stdio.h>
#include <time.h>

int main ()
{
   struct tm info;
   int x[10],y[10],day=0;
   time_t a_t,b_t;
   double diff_t,cost;
   
   scanf("%lf %d:%d %d-%d-%d %d:%d %d-%d-%d",&cost,&x[0],&x[1],&x[2],&x[3],&x[4],&y[0],&y[1],&y[2],&y[3],&y[4]);

   info.tm_year = x[4] -1900;
   info.tm_mon = x[3]-1;
   info.tm_mday = x[2];
   info.tm_hour = x[0];
   info.tm_min = x[1];
   info.tm_sec = 0;

   a_t = mktime(&info);

   info.tm_year = y[4] -1900;
   info.tm_mon = y[3]-1;
   info.tm_mday = y[2];
   info.tm_hour = y[0];
   info.tm_min = y[1];
   info.tm_sec = 0;
   info.tm_isdst = -1;

   b_t = mktime(&info);
   diff_t = difftime(b_t, a_t)/60/60;
   for(int i=1;;i++){
         if(i*24>diff_t){
            day=i;
            break;
         }
   }
   printf("%.2lf",day*(cost+0.125*cost+0.11*cost));
}