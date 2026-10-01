#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second

ll const nmax=1e6+5;
ll const mod=1e9+7;

ll n,m,a[nmax],b[nmax];
vector<int> v[nmax];
queue<int> q;
bool check[nmax];

int main()
{
    int t;
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++) a[i]=i;
    while(m--)
    {
        for(int i=1;i<=n;i++)
        {
            int x;
            cin >> x;
            b[i]=a[x];
        }
        for(int i=1;i<=n;i++){
            a[i]=b[i];
        }
    }
    while(t--)
    {
        int l,r;
        cin >> l >> r;
        if(a[r]==l) cout << "YES\n";
        else cout << "NO\n";
    }
}