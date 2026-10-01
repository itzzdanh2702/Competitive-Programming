#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2 * 100005
#define fi first
#define se second
const ll oo = 1e9;

int n;
int tmp;
int a[MAXN];
int b[MAXN];
int dem = 0;
pair<int,int> p[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> p[i].fi;
        p[i].se = 1;
    }
    for(int i = n + 1 ; i <= 2 * n ; ++i)
    {
        cin >> p[i].fi;
        p[i].se = 2;
    }
    sort(p + 1, p + 2 * n + 1);
    for(int i = 1 ; i < 2 * n ; ++i)
    {
        if(p[i].se != p[i + 1].se)
        {
            ++dem;
            ++i;
        }
    }
    cout << dem;
}
