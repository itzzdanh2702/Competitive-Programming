#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int a,b;
int sum = 0;
int tmp1[MAXN]; 
int tmp2[MAXN];

int main()
{
    FAST();
    cin >> a >> b; 
    if(a < b)
    {
        for(int i = 1 ; i <= a - 1; ++i)
        {
            tmp1[i] = i; 
        }
        for(int i = 1 ; i <= b; ++i)
        {
            tmp2[i] = -i;
        }
        for(int i = a ; i <= b ; ++i)
        {
            sum += i;
        }
        tmp1[a] = sum;
        for(int i = 1 ; i <= a ; ++i)
        {
            cout << tmp1[i] << ' ';
        }
        for(int i = 1 ; i <= b ; ++i)
        {
            cout << tmp2[i] << ' ';
        }
    }
    else 
    {
        for(int i = 1 ; i <= a; ++i)
        {
            tmp1[i] = i; 
        }
        for(int i = 1 ; i <= b - 1; ++i)
        {
            tmp2[i] = -i;
        }
        for(int i = b ; i <= a ; ++i)
        {
            sum += i;
        }
        tmp2[b] = -sum;
        for(int i = 1 ; i <= a ; ++i)
        {
            cout << tmp1[i] << ' ';
        }
        for(int i = 1 ; i <= b ; ++i)
        {
            cout << tmp2[i] << ' ';
        }
    }
    // cout << '\n';
    // int tmp = 0;
    // for(int i = 1 ; i <= a ; ++i)
    // {
    //     tmp += tmp1[i];
    // }
    // for(int i = 1 ; i <= b ; ++i)
    // {
    //     tmp += tmp2[i];
    // }
    // cout << tmp;
}