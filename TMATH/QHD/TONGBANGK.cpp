#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll n,k;
ll cnt = 0;
ll a[MAXN];
ll pre[MAXN];

int main()
{
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    } 
    for(int i = 1 ; i <= n - 1 ; ++i)
    {
        for(int j = i + 1 ; j <= n ; ++j)
        {
            if(pre[j] - pre[i - 1] == k)
            {
                ++cnt;
            }
        }
    }
    cout << cnt;

}
/*

#include <iostream>
using namespace std;
 
const int MAX = 10000;
int dem[MAX];
int main(){
    int N;
    cout << "\nNhap n = ";
    cin >> N;
    int n = N; // Tao ban sao cua N
    if(n > MAX){
        printf("Ban nhap so lon hon %d", MAX);
        return 0;
    }
    for(int i = 0; i <= n; i++) dem[i] = 0;
    for(int i = 2; i <= n; i++){
        while(n % i == 0){
            ++dem[i];
            n /= i;
        }
    }
    for(int i = 0; i <= N; i++){
        if(dem[i]){
            cout << i << " ^ " << dem[i] << "\n";
        }
    }
}
*/