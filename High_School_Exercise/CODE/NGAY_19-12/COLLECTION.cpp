#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll,ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
ll a[nmax];
bool visited[nmax];
ll m,n,dem;
char s[nmax];
void FAST()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

int main()
{
    FAST();
    //freopen("COLLECTION.inp","r",stdin);
    //freopen("COLLECTION.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(i!=a[i]) dem++;
    }
    cout<<dem;
}