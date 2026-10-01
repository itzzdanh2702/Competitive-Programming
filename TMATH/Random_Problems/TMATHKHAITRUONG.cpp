#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll m,n,b[nmax],res=0;
struct so
{
    int x,y,z;
} a[nmax];
bool cmp(so a, so b){
 return a.y<b.y;
}
int main()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y,a[i].z=i;
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        if(m>a[i].x) m-=a[i].x,res+=a[i].x*a[i].y,b[a[i].z]=a[i].x;
        else if(m<=a[i].x) res+=m*a[i].y,b[a[i].z]=m,m=0;
        cout<<res<<endl;
        for(int i=1;i<=n;i++)
            cout<<b[i]<<endl;

}

