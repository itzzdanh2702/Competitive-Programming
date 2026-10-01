#include<bits/stdc++.h>
#define ll long long

ll const nmax=1e6+5;
ll const mod=1e9+7;

using namespace std;

ll n,m,a[nmax],b[nmax],cnt=0;

int main() {
    freopen("MULARR.inp","r",stdin);
    freopen("MULARR.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(ll i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    for(ll i=n;i>=1;i--){
        a[i]+=cnt;
        if(a[i]%b[i]!=0)
        {
            if(a[i]<b[i])
            {
                cnt+=b[i]-a[i];
            }
            else if(a[i]>b[i])
            {
                ll k=(a[i]/b[i]*b[i])+b[i];
                cnt+=k-a[i];
            }
        }
    }
    cout << cnt;
}