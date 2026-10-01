#include<bits/stdc++.h>
using namespace std;
long long n,s,i,j,dem=0,A[1000005],S=0,P=0;
int main()
{

    cin >> n;
 for ( i = 1; i <= n; i++)
  {

      S+=i;
  }
   for ( i = 1; i <= n; i++)
  {

   cout<<S-P;
  }
  if(dem==0) cout<<"-1";

}
