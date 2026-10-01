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

ll TC;
ll a[MAXN];
int main()
{
    //freopen("GAME.inp", "r", stdin);
    //freopen("GAME.out", "w", stdout);
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll dem1 = 0, dem2 = 0, dem3 = 0;
        ll n, x, y;
        cin >> n >> x >> y;
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
        }

        for (int i = 1; i <= n; ++i)
        {
            if ((a[i] % x == 0) and (a[i] % y == 0))
            {
                ++dem3;
                continue;
            }
            else if (a[i] % x == 0)
            {
                ++dem1;
                continue;
            }
            else if (a[i] % y == 0)
            {
                ++dem2;
                continue;
            }
        }
        if (dem3 % 2 == 0)
        {
            dem1 += dem3 / 2;
            dem2 += dem3 / 2;
            if (dem1 > dem2)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        else
        {
            dem1 += dem3 / 2 + 1;
            dem2 += dem3 / 2;
            if (dem1 > dem2)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}
/*
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,a,x=0,y=0;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		x=max(x,a);
		y=__gcd(y,a);
	}
	if((x/y - n)%2)
		cout<<"Alice\n";
	else
		cout<<"Bob\n";
	return 0;
}*/
/*
6 3 2
1 3 5 6 11 11
11/
*/
