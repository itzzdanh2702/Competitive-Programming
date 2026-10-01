#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
#define nmax 1000000
ll n, l[nmax], b[nmax], c[nmax],q[nmax],ma;
struct ds {
   ll x,y,z;
};
ds a[nmax];
bool cmp(const ds p , const ds q) {
    if(p.x!=q.x) return p.x<q.x;
	return p.y>q.y;
}
int main()
{
    //freopen("job.inp","r",stdin);
    //freopen("job.out","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    sort(a+1,a+n+1,cmp);
    for (int i = 1; i <= n; i++)
    {
        q[i] = a[i].z;
        ll l = 1, r = i - 1;
        while (l <= r)
        {
            ll mid = (l + r) / 2;
            if ((a[mid].y < a[i].x) and (q[i] < q[mid] + a[i].z))
            {
                q[i] = q[mid] + a[i].z;
                ma=max(ma,q[i]);
                l=mid+1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    cout<<ma;
    
}