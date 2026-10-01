#include<stdio.h> 

const int N = 100; 
int main()
{
    int n; 
    scanf("%d",&n); 
    if(n < 1 || n > 100){
        printf("INVALID"); 
    }
    else{
        int sum = 0; 
        int a[N]; 
        for(int i = 0 ; i < n ; ++i){
            scanf("%d",&a[i]); 
            if(a[i] % 3 == 0){
                sum += a[i]; 
            }
        }   
        printf("%d",sum); 
    }
    
}