#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll S;
ll n;
int main()
{
    freopen("ZERODIGIT.inp","r",stdin);
    freopen("ZERODIGIT.out","w",stdout);
    cin>>n;
    while((n/5)!=0)
    {
        S+=n/5;
        n/=5;
    }
    cout<<S;    
}