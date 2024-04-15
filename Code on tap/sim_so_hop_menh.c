#include <stdio.h>
int main(){
    int n,a;
    char x[11];
    fgets(x,sizeof(x),stdin); scanf("%d",&n);
    switch(n){
        case 1:{
            for (int i=1;i<=9;i++){
                if(x[i]=='9'){
                    a=0;
                    printf("%d",a);
                    break;
                } 
            }
            if (a==0) break;
            else{
                a=0;
                for (int i=1;i<=9;i++){
                    if(x[i]=='6'||x[i]=='7'||x[i]=='2'||x[i]=='5'||x[i]=='8'){
                        a=1;
                        printf("%d",a);
                        break;
                    }
                     
                }
                if (a==0) printf("0");  
                break;
            }
        }
        case 2:{
            for (int i=1;i<=9;i++){
                if(x[i]=='6'||x[i]=='7'){
                    a=0;
                    printf("%d",a);
                    break;
                } 
            }
            if (a==0) break;
            else{
                a=0;
                for (int i=1;i<=9;i++){
                    if(x[i]=='0'||x[i]=='1'||x[i]=='3'||x[i]=='4'){
                        a=1;
                        printf("%d",a);
                        break;
                    }   
                }
                if (a==0) printf("0");  
                break;
            }
        }
        case 3:{
            for (int i=1;i<=9;i++){
                if(x[i]=='5'||x[i]=='2'||x[i]=='8'){
                    a=0;
                    printf("%d",a);
                    break;
                } 
            }
            if (a==0) break;
            else{
                a=0;
                for (int i=1;i<=9;i++){
                    if(x[i]=='0'||x[i]=='1'||x[i]=='6'||x[i]=='7'){
                        a=1;
                        printf("%d",a);
                        break;
                    }   
                }
                if (a==0) printf("0");  
                break;
            }
        }
        case 4:{
            for (int i=1;i<=9;i++){
                if(x[i]=='0'||x[i]=='1'){
                    a=0;
                    printf("%d",a);
                    break;
                } 
            }
            if (a==0) break;
            else{
                a=0;
                for (int i=1;i<=9;i++){
                    if(x[i]=='9'||x[i]=='3'||x[i]=='4'){
                        a=1;
                        printf("%d",a);
                        break;
                    }   
                }
                if (a==0) printf("0");  
                break;
            }
        }
        case 5:{
            for (int i=1;i<=9;i++){
                if(x[i]=='3'||x[i]=='4'){
                    a=0;
                    printf("%d",a);
                    break;
                } 
            }
            if (a==0) break;
            else{
                a=0;
                for (int i=1;i<=9;i++){
                    if(x[i]=='2'||x[i]=='5'||x[i]=='8'||x[i]=='9'){
                        a=1;
                        printf("%d",a);
                        break;
                    }   
                }
                if (a==0) printf("0");  
                break;
            }
        }
    }
}