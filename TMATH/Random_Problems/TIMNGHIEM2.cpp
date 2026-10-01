#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll l=1,r=1000000,Q,k,a,b,c,d,y,t;
ll BS(ll l,ll r,ll y)
{

    while(l<=r)
    {
        ll mid=(l+r)/2;
        if(mid*mid*mid*a+b*mid*mid+c*mid+d==y)
            return mid;
        else
        {
            if(mid*mid*mid*a+b*mid*mid+c*mid+d<y)
                l=mid+1;
            else if (mid*mid*mid*a+b*mid*mid+c*mid+d>y)
                r=mid-1;
        }
    }
    return 0;
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>a>>b>>c>>d>>y;
       cout<<BS(1,1000000,y)<<endl;
    }
}
