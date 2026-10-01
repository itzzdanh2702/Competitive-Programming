#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, k, ans, a[100000];
bool check(ll m)
{
	ll s=0, dem=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>m) return false;
		if(s+a[i]>m)
		{
			s=a[i];
			dem++;
			if(dem>k) return false;
		}
		else s+=a[i];
	}
	dem++;
	if(dem>k) return false;
	return true;
}
ll chathao()
{
    ll left=1,right=1e9;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        if(check(mid))
        {
            right=mid-1;
            ans=mid;
        }
        else left=mid+1;
    }
    return ans;
}
int main()
{

	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
    cout<<chathao();
}
