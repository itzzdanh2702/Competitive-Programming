#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,A[nmax],f[nmax];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>A[i];
        f[0]=0;
     for(int i=1;i<=n;i++)
     {
         if(A[i]>A[i-1])
            f[i]=f[i-1]+1;
         else f[i]=f[i-1];
     }
     cout<<f[n];
}
