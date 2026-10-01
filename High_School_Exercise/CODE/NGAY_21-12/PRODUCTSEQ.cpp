#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const long long MOD = 1000000007;
#define nmax 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll n;
ll a[nmax];
bool check = 0;
int main()
{
    FAST();
    freopen("PRODUCTSEQ.inp","r",stdin);
    freopen("PRODUCTSEQ.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n/i;j++)
        {
            if(a[i*j]==a[i]*a[j])
            {
                continue;
            }
            else return cout<<"NO",0;
        }
    }
    cout<<"YES";
}

