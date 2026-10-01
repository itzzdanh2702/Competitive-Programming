#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[100005], s[100005], k, sum = 0 ;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
           {
             if(s[j]%k==0)
           }
           s[i]=s[i]-a[i+1];
    }
}
