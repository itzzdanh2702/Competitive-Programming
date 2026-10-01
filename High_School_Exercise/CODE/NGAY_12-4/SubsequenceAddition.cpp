#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAXN = 2 * 100000 + 5;
int TC;
int a[MAXN];

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int main()
{
    FAST();
    //freopen("SubsequenceAddition.inp","r",stdin);
    //freopen("SubsequenceAddition.out","w",stdout);
    cin >> TC;
    while(TC--)
    {
        int n;
        bool check = 1;
        cin >> n;
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> a[i];
        }
        sort(a + 1 , a + n + 1);
        if(n == 1)
        {
            if(a[1] == 1)
            {
                cout << "YES" << '\n';
                continue;
            }
            else
            {
                cout << "NO" << '\n';
                continue;
            }
        }
        if(a[1] != 1)
        {
            cout << "NO" << "\n";
            continue;
        }
        ll sum = 1;
        for(int i = 2 ; i <= n ; ++i)
        {
            if(a[i] > sum)
            {
                check = 0;
            }
            else
            {
                sum += a[i];
            }
        }
        if(check == 1)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}
