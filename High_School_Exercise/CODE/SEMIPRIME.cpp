#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 10000005
ll dem=0,a,b,f[nmax];
string p;
bool nt[nmax];
void sang()
{
      nt[0]=nt[1]=false;
    for(int i=2;i<=nmax;i++) nt[i]=true;

    for(int i=2;i*i<=nmax;i++)
    {
        if(nt[i])
        {
            for(int j=i*i;j<=nmax;j+=i)
            {
                nt[j]=false;
            }
        }
    }
}
bool check(ll n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
    {
       if(n%i==0) return false;
    }
    return true;
}
ll tongchuso(string S)
{
    ll P=0;
    for(int i=0;i<=S.size()-1;i++)
    {
     P+=int(S[i]-48);
    }
    return P;
}
int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

    sang();
    cin>>a>>b;
    for(int i=1;i<=b;i++)
    {
        p=to_string(i);
        ll k=tongchuso(p);
        if(nt[k])
           f[i]=f[i-1]+1;
           else f[i]=f[i-1];
    }
    cout<<f[b]-f[a-1];


}
