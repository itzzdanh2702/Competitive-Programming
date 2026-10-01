#include<bits/stdc++.h>
using namespace std;
#define ll long long
string m[1000005];
ll a,b,c,d;
int main()
{
   cin>>a>>b>>c>>d;
   if(float(a/__gcd(a,b)/(b/__gcd(a,b)))<float(c/__gcd(c,d)/(d/__gcd(c,d))))
    cout<<"1";
   else cout<<"0";
}
