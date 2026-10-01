#include <bits/stdc++.h>
using namespace std;
#define nmax 1000007
#define ll long long
struct bum
{
    long long c,h,x;
};
bool cmp(bum a,bum b)
{
    return (a.x<b.x);
}
bum a[nmax];
ll n,q,b[1001][1001],c[nmax],dem=0;
ll chat(ll n)
{
    ll left=1,right=dem;
    while(left<=right)
    {
        ll mid=(left+right)/2;
        if(a[mid].x==n) return mid;
        if(a[mid].x>n) right=mid-1;
        if(a[mid].x<n) left=mid+1;
    }
    return -1;
}
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cin>>b[i][j];
            dem++;
            a[dem].x=b[i][j];
            a[dem].h=i;
            a[dem].c=j;
        }
    sort(a+1,a+n*n+1,cmp);
    while(q--)
    {
        ll e;
        cin>>e;
        cout<<a[chat(e)].h<<" "<<a[chat(e)].c<<endl;
    }
}