#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 10000000
ll n;
int tonguoc(ll n)
{
    ll S=1;
    for(int i=2;i*i<=n;i++)
    {

        if((n%i==0) and (n/i!=i))
            S=S+i+n/i;

        else if((n%i==0)and (n/i==i))
            S+=i;
    }
    return S;
}
bool check(ll n)
{
    if(tonguoc(n)>n) return true;
    else return false;
}
int main()
{
    cin>>n;
   if(check(n)) cout<<"1";
   else cout<<"0";
}
