#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000005
ll n,x,k;

int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll dem=0;
    for(int i=n-1;i>=0;i--)
    {

        auto it= upper_bound(a.begin(),a.end()-dem,a[i]);
        cout<<distance(a.begin(),it)<<" ";
        dem++;
    }


}
