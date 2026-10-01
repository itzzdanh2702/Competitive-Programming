#include <bits/stdc++.h>
#define nmax 10000001
using namespace std;
int n;
long long a,a1,dem=0,d;
bool nt[nmax];
int check(long long n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
long long d=0;
cin>>n;
for(int i=1;i<=n;i++)
{
      d=d+(n-1)/i;
}
  cout<<d%(1000000000+7);



}
