#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll const nmax=1e6+6;
ll const mod=1e9+7;

ll somu(ll a,ll x){
    if(x==0) return 1;
    ll tam=(somu(a,x/2))%mod;
    if(x%2==0) return ((tam%mod)*(tam%mod))%mod;
    else return ((tam*tam)%mod*(a%mod))%mod;
}

ll n,k,m,gt[nmax];

int main()
{
    //freopen("CKN.inp","r",stdin);
   // freopen("CKN.out","w",stdout);
    gt[0]=1;
    for(int i=1;i<=5000;i++){
        gt[i]=(gt[i-1]%mod*i)%mod;
    }

        cin>>n;
        cout << (gt[n]*somu(gt[n-2]*gt[2]%mod,mod-2)+1)%mod;
    }
