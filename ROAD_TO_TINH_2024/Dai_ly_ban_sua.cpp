#include<bits/stdc++.h>

using namespace std;

#define ll long long

const int MAXM = 5e5 + 5;
const int MAXN = 1e5 + 5;
const ll oo = 1e18;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n,m;
int x[MAXN];
int s,f,c,r;
ll kq = -oo;

bool check(ll mid)
{
    int cnt = 0;
    ll fuel;
    bool check = 0;
    for(int i = s + 1 ; i <= f ; ++i)
    {
        if(i == s + 1)
        {
            if(c * (x[i] - x[s]) > mid)
                return false;
            fuel = mid - c * (x[i] - x[s]);
        }
        else
        {
            if(fuel < c * (x[i] - x[i - 1]))
            {
                if(mid < c * (x[i] - x[i - 1]))
                    return false;
                fuel = mid;
                ++cnt;
            }
            else
                fuel -= c * (x[i] - x[i - 1]);
        }
    }
    if(cnt > r)
        return false;
    return true;
}

void sub1()
{
    ll ans;
    ll l = 1, r = 1e16;
    while(l <= r)
    {
        ll mid = (l + r)/2;
        if(check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    kq = max(kq,ans);
}

/*
5 3
1 3 8 12 15
1 3 10 0
2 4 5 1
1 5 10 1
*/
int main()
{
    FAST();
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i)
        cin >> x[i];
    for(int i = 1 ; i <= m ; ++i)
    {
        cin >> s >> f >> c >> r;
        sub1();
    }
    cout << kq;
}
