#include<stdio.h> 

int main()
{
    int t; 
    scanf("%d",&t); 
    for(int i = 1 ; i <= t ; ++i){
        if(i < 30){
            printf("%d: %s - %s\n",i,"Green","Red"); 
        }
        else if (i >= 30 && i <= 34){
            printf("%d: %s - %s\n",i,"Yellow","Green"); 
        }
        else if (i >= 35 && i <= 64){
            printf("%d: %s - %s\n",i,"Red","Green"); 
        }
        else if (i >= 65 && i <= 69){
            printf("%d: %s - %s\n",i,"Red","Yellow"); 
        }
        else{
            printf("%d: %s - %s\n",i,"Green","Red"); 
        }

    }
}