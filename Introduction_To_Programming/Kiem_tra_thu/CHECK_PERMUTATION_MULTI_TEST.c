#include<stdio.h>

int main(){
    int TC;
    scanf("%d",&TC);
    while(TC--){
        int n,check = 0;
        scanf("%d",&n);
        int a[n],d[n + 1];
        for(int i = 1 ; i <= n ; ++i){
            d[i] = 0;
        }
        for(int i = 0 ; i < n ; ++i){
            scanf("%d",&a[i]);
            if(a[i] <= 0 || a[i] > n){
                check = 1;
                continue;
            }
            ++d[a[i]];
        }
        if(check){
            printf("0\n");
            continue;
        }
        for(int i = 1 ; i <= n ; ++i){
            if(d[i] != 1){
                check = 1;
                break;
            }
        }
        if(check){
            printf("0\n");
            continue;
        }
        printf("1\n");
    }
    return 0;
}
