#include<stdio.h>

#define ll long long

const int N = 1e5;
const int M = 5e5;
const int MOD = 1e9 + 7;

int main(){
    int n,a[N],d[M];
    ll cnt = 0;
    scanf("%d",&n);
    for(int i = 0 ; i < M; ++i){
        d[i] = 0;
    }
    for(int i = 0 ; i < n ; ++i){
        scanf("%d",&a[i]);
        cnt += d[a[i] - 1];
        cnt %= MOD;
        cnt += d[a[i] - 1];
        cnt %= MOD;
        ++d[a[i]];
    }
    printf("%lld",cnt);
    return 0;
}
