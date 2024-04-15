#include<stdio.h>
int main ()
{
	int min=0,hour=0,n=0;
	int in[1000],out[1000];
	scanf("%d",&n);
	for(int i=0;i<2*n;i+=2){
	    scanf("%d:%d",&in[i],&in[i+1]);
	}
	for(int i=0;i<2*n;i+=2){
	    scanf("%d:%d",&out[i],&out[i+1]);
	}
	for(int i=0;i<2*n;i+=2){
	    min=min+out[i+1]-in[i+1];
	    hour=hour+out[i]-in[i];
	    if(min<0) {
	        hour-=1;
	        min+=60;
	    }
	}
	while(min>=60){
	    hour+=1;
	    min-=60;
	}
	printf("%d:%d",hour,min);
}