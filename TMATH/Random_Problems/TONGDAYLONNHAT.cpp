#include<bits/stdc++.h>
using namespace std;

long long n;
long long a[1000005];
long long X[1000005];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    X[1]=a[1];
    for(int i=2;i<=n;i++)
        X[i]=a[i]+max(X[i-1],0LL);
    long long ans=*max_element(X+1,X+n+1);
    cout<<ans;
}
