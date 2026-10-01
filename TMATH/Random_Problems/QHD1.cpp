#include <bits/stdc++.h>
using namespace std;

long long n,a[1000006],X[1000006],Y[1000006],ans=-1e18;
int main()
{

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	X[1]=a[1];
	for(int i=2;i<=n;i++)
		X[i]=max(X[i-1],a[i]);
	Y[n]=a[n];
	for(int i=n-1;i>=1;i--)
		Y[i]=min(Y[i+1],a[i]);
	for(int i=2;i<n;i++)
		ans=max(ans,X[i-1]+a[i]-Y[i+1]);
	cout<<ans;
}
