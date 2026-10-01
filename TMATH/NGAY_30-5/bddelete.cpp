#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
int cnt_even[MAXN], cnt_odd[MAXN];
int a[MAXN];
ll S;
ll P = 0,Q = 0;

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        S += a[i];
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i] % 2 == 0)
        {
            cnt_even[i] = cnt_even[i - 1] + 1;
            cnt_odd[i] = cnt_odd[i - 1];
        }
        else
        {
            cnt_even[i] = cnt_even[i - 1];
            cnt_odd[i] = cnt_odd[i - 1] + 1;
        }
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        if(a[i] & 1)
        {
            P += cnt_even[i]; 
            Q += cnt_odd[i - 1];
        }
        else 
        {
            Q += cnt_even[i - 1];
            P += cnt_odd[i];
        }
    }
    if(S & 1)
        return cout << P,0;
    cout << Q; 
}