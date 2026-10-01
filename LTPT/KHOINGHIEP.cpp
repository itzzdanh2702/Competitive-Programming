#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2 * 100000
#define fi first
#define se second
const int oo = 1e9;

int n;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int mi = oo;
pair<int,int> p[MAXN];

void solve()
{
    bool check = 1;
    int ans = 0;
    int cnt = 0,cnt1 = 0;
    for(int i = 1 ; i <= n ; ++i)
        c[i] = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        if(b[i] == 1)
        {
            ans += p[i].se;
            ++cnt1;
        }
        else
        {
            ++cnt;
            c[cnt] = p[i].fi;
        }
    }
    for(int i = 1 ; i <= cnt ; ++i)
    {
        if(c[i] <= cnt1)
            ++cnt1;
        else
        {
            check = 0;
            break;
        }
    }
   if(check)
   mi = min(ans,mi);
   if(ans == 49)
   {
       for(int i = 1 ; i <= n ; ++i)
       {
       cout << b[i] << ' ';
       }

   }

}
void quaylui(int k)
{
    for(int i = 0 ; i <= 1 ; ++i)
    {
        b[k] = i;
        if(k == n)
            solve();
        else
            quaylui(k + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
        cin >> p[i].fi >> p[i].se;
    sort(p + 1, p + 1 + n);
    quaylui(1);
    cout << mi;
}
