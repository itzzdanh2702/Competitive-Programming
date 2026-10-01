#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000
ll a,b,x;
bool check(ll n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        return false;
    return true;
}
int main()
{
   cin>>a>>b>>x;
   a=a+a%x;
   b=b-b%x;
   ll p,q;
  cout<<(b-a)/x+1;


}

