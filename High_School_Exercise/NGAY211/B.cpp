#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll n;
vector<ll> v;
int main()
{
    cin>>n;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            v.push_back(i);
            ll p=n/i;
            if(p==i) continue;
            else v.push_back(p);
        }
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";
}