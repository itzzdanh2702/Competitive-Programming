#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,f[nmax],t;
int main()
{
    cin>>t;
for(int j=1;j<=t;j++)
    {
        f[nmax]=1;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        f[n]=1;
        for(int i=n-1;i>=1;i--)
        {
            if(((a[i]>=0) and (a[i+1]<=0)) or ((a[i]<=0) and (a[i+1]>=0)))
                f[i]=f[i+1]+1;
            else f[i]=1;
        }
        for(int i=1;i<=n;i++)
            cout<<f[i]<<" ";
            cout<<endl;
    }
}

