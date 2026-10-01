#include<bits/stdc++.h>
using namespace std;
int main()
{
 long long n,mu=0,dem=0;
 cin>>n;
  for(long long i=2;i<=sqrt(n);i++)
  {
      mu=0;
      {
          while(n%i==0)
          {
              n=n/i;
              mu++;

          }
      }
      if(mu>0)
      {
         dem++;

      }

  }
  if(n>1)
   dem++;
   cout<<dem;
}
