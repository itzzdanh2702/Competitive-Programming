#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 100000
#define fi first
#define se second
#define pii pair<ll,ll>
pair<ll,ll> p[nmax];
vector<ll> ans1;
vector<ll> a;
vector<ll> b;
pii tom[nmax];
ll n,ans[nmax];
ll cmp(pii x,pii y)
{
	if (x.fi!=y.fi)
    return (x.fi<y.fi);
    else return (x.se>y.se);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>p[i].fi>>p[i].se;


    }
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
    {
        a.push_back(p[i].fi);
        b.push_back(p[i].se);
    }
    for(int i=0;i<a.size();i++)
    {
        auto it=lower_bound(a.begin()+i,a.end(),b[i]);

        if(it-a.begin()!=a.size())
        {
            cout<<it-a.begin();
        }
        else
        {

            ans1.push_back(max(ans[i-1],b[i]-a[i]));
            if(!a.empty())
            a.erase(a.begin()+i);


        }
    }


}
