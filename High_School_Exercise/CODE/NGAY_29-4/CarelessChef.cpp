#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long

int TC;
int n;
ll a[MAXN];
ll b[MAXN];

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    freopen("CarelessChef.inp","r",stdin);
    freopen("CarelessChef.out","w",stdout);
    FAST();
    cin >> TC;
    while(TC--)
    {
        ll cnt1 = 0, cnt2 = 0;
        cin >> n;
        for(int i = 1 ; i <= 2 * n ; ++i)
        {
            cin >> a[i];
            if(abs(a[i]) % 2 == 0)
            {
                ++cnt1;
            }
            else
            {
                ++cnt2;
            }
        }
        if((cnt1 % 2 == 0) && (cnt2 % 2 == 0))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }

    }
}

