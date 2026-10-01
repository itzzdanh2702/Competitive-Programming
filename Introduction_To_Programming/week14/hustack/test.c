#include<stdio.h> 

#define max(a,b) (a > b) ? a : b

const int N = 100;
const int oo = 1e9; 

int main()
{
    int n,ma = -oo,max_element = -oo,cnt = 0;  
    int a[N]; 
    scanf("%d",&n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d",&a[i]);
        if(a[i] == 0)
            ++cnt;  
        else{
            ma = max(ma,cnt); 
            cnt = 0; 
        }
    }   
    ma = max(ma,cnt); 
    printf("Day co do dai 0 dai nhat la: "); 
    printf("%d\n",ma); 
    return 0; 
}