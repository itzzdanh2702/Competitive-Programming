#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
string S;
ll dem,res=0,n,a[nmax];
map<char,ll> mp;
vector<ll> v1;
vector<char> v;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>a[i];
    res+=a[i]/2;
    a[i]%=2;
    if((a[i]==1) and (a[i-1]==1))
    {
        res++;
        a[i]=0;
        a[i-1]=0;
    }
}
cout<<res;
}
