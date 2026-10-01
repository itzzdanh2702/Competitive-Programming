#include<bits/stdc++.h>
using namespace std;
#define nmax 1000000

long long l[nmax],r[nmax],n,P[nmax],pos[nmax],f[nmax],kq[nmax];
int ma=-10;
string S[nmax];
struct HS
{
    string ten;
    int tin,the,tong,r;
};
HS a[nmax];
bool cmp(HS b,HS c)
{
    return b.tong>c.tong;

}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].ten>>a[i].tin>>a[i].the;
        a[i].tong=a[i].tin+a[i].the;

        f[a[i].tong]++;
        ma=max(ma,a[i].tong);
    }

    for(int i=ma;i>=1;i--)
        if(f[i]>0) kq[i]=kq[i+1]+1;
    else kq[i]=kq[i+1];
    for(int i=1;i<=n;i++)
    {
        cout<<a[i].ten<<" "<<kq[a[i].tong]<<endl;
    }
}
