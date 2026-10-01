#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define mod 1000000007
string S;
ll q,dem=0,n,p,ma;
int main()
{
    freopen("STEP.inp","r",stdin);
    freopen("STEP.out","w",stdout);
    cin>>n;
    while(n>0)
    {
        S=to_string (n);
        for(int i=0;i<=S.size()-1;i++)
        {
            p=int(S[i]-48);
            ma=max(ma,p);
        }
        n=n-ma;

        dem++;
        ma=-1e9;
    }
    cout<<dem;

}
