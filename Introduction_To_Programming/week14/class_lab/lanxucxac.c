#include<stdio.h> 
#include<stdlib.h> 
#include<time.h> 

const int N = 100; 
const int M = 13; 

int main()
{
    srand(time(NULL)); 
    int cnt[M]; 
    for(int i = 2 ; i <= 12 ; ++i){
        cnt[i] = 0; 
    }   
    for(int i = 0 ; i < 100 ; ++i){
        int n = rand() % 6 + 1;
        int m = rand() % 6 + 1;
        printf("%d %d %d\n",n,m,n + m); 
        ++cnt[n + m];  
    }
    for(int i = 2 ; i <= 12 ; ++i){
        printf("The element %d exists : %d time(s)\n",i,cnt[i]); 
    }
    return 0; 
}