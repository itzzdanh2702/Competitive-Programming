#include <bits/stdc++.h>
#define ll long long
#define nmax 1000005
using namespace std;
ll n,k,a[nmax];
int main()
{
    freopen("D.inp","r",stdin);
    freopen("D.out","w",stdout);
    cin>>n>>k;
    for (ll i=1;i<=n;i++) cin>>a[i];
    if (k==1)
    {
        cout<<n<<'\n';
        for (ll i=1;i<=n;i++)
            cout<<a[i]<<' ';
    }
    else
    {
        for (ll i=n/k;i>=1;i--)
        {
            for (ll j=1;j<=n-i*k+1;j++)
            {
                ll dem=0;
                for (ll s=j;s<=i+j-1;s++)
                {
                    ll dem1=1;
                    for (ll d=1;d<k;d++)
                    {
                        if (a[s]==a[s+d*i])
                            dem1++;
                        else break;
                    }
                    if (dem1==k) dem++;
                    else break;
                }
                if (dem==i)
                {
                    cout<<i*k<<'\n';
                    for (ll d=j;d<=i+j-1;d++)
                        cout<<a[d]<<' ';
                    return 0;
                }
            }
        }
        cout<<-1;
    }
}
