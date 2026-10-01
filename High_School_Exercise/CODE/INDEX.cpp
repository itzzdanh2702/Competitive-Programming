#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,ans[nmax],ans1[nmax],ma=-1e9;
stack<ll> bentrai;
stack<ll> benphai;
int main()
{
     freopen("INDEX.INP","r",stdin);
    freopen("INDEX.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    for(int i=1;i<=n;i++)
    {
        ll dem=0;
        if((bentrai.empty()) and (a[i+1]==a[i]+1)) bentrai.push(a[i]);
        else if((!bentrai.empty()) and (a[i]==bentrai.top()+1))
        {
            bentrai.push(a[i]);
        }
        else
        {
            while((!bentrai.empty()) and (bentrai.top()>a[i]))
            {
                dem++;
                bentrai.pop();
            }
            if(!bentrai.empty()) bentrai.pop();
            ans[i]=dem;
        }
    }
    for(int i=n;i>=1;i--)
    {
        ll dem=0;
        if((benphai.empty()) and (a[i-1]==a[i]-1)) benphai.push(a[i]);
        else if((!benphai.empty()) and (a[i]==benphai.top()-1))
        {
            benphai.push(a[i]);
        }
        else
        {
            while((!benphai.empty()) and (benphai.top()>a[i]))
            {
                dem++;
                benphai.pop();
            }
            if(!benphai.empty()) benphai.pop();
            ans1[i]=dem;
        }
    }
    for(int i=1;i<=n;i++)
        ma=max(ma,ans[i]*ans1[i]);
        cout<<ma;
}
