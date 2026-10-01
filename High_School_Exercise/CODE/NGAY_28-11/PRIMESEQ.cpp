#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll a,b;
bool check(ll n)
{
    if(n==2) return false;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    cin>>a>>b;
}