#include<stdio.h> 

#define max(a,b) (a > b) ? a : b

const int N = 100;

void sort(int a[],int size){
    int tmp; 
    for(int i = 1 ; i < size ; ++i){
        for(int j = 0 ; j <= i - 1 ; ++j){
            if(a[i] < a[j]){
                tmp = a[i]; 
                a[i] = a[j]; 
                a[j] = tmp; 
            }
        }
    }
}

int main()
{
    int n;  
    int a[N]; 
    scanf("%d",&n); 
    for(int i = 0 ; i < n ; ++i){
        scanf("%d",&a[i]);
    }   
    sort(a,n); 
    int idx = 0,cnt = 1; 
    int assign[N],count[N]; 
    for(int i = 0 ; i < n - 1; ++i){
        if(a[i] != a[i + 1]){
            assign[++idx] = a[i];
            count[idx] = cnt;
            cnt = 1;   
        }
        else{
            ++cnt; 
        }
    }
    assign[++idx] = a[n - 1];
    count[idx] = cnt;
    for(int i = 1 ; i <= idx ; ++i){
        printf("%d %d\n",assign[i],count[i]); 
    }
    return 0; 
}