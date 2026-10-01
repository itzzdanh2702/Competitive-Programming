#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,a[nmax],f1[nmax],f2[nmax],f3[nmax],f4[nmax],f5[nmax],w1,w2;
int main()
{
    f1[0]=-100005;
    f2[0]=-100005;
    f3[0]=-100005;
    f4[0]=-100005;
    f5[0]=-100005;
    cin>>n>>w1>>w2;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        f1[i]=max(f1[i-1],a[i]*w1);
        f2[i]=max(f2[i-1],f1[i-1]+a[i]*w2);
        f3[i]=max(f3[i-1],f2[i-1]+a[i]);
        f4[i]=max(f4[i-1],f3[i-1]+a[i]*w2);
        f5[i]=max(f5[i-1],f4[i-1]+a[i]*w1);
    }
    cout<<f5[n];
}
