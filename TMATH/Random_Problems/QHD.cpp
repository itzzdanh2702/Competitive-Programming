#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long a[1000000], m, n, x,ma,b[1000000];

int main()
{
    cin>>n;
	for(int i=1;i<=n;i++)
    {
     cin>>a[i];
     b[i]=a[i];
    }
    sort(b+1,b+n+1,greater<ll>());
    cout<<b[1]+b[2]-b[n];


}
