#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000005
ll n,x,k;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    freopen("NEXTNUM.inp","r",stdin);
    freopen("NEXTNUM.out","w",stdout);
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
        for(int i=0;i<n;i++)
        {
        auto it= upper_bound(a.begin()+i,a.end(),a[i]);
        if(distance(a.begin(),it)==n)
            cout<<"-1"<<" ";
        else
        cout<<*it<<" ";
        }

}
