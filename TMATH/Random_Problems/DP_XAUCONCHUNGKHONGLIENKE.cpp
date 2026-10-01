#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 2500
ll m,n,dem=0,f[4005][4005],ma=-1e9;
string xau1,xau2;
char S[nmax],P[nmax];
int main()
{
    getline(cin,xau1);
    getline(cin,xau2);
    xau1=" "+xau1;

    xau2=" "+xau2;

    m=xau1.size();
    n=xau2.size();

    for(ll i=1;i<=m;i++)
    {
        for(ll j=1;j<=n;j++)
        {

            if(xau1[i]==xau2[j])
                f[i][j]=max(f[i][j],f[i-1][j-1]+1);
            else
            {
                f[i][j]=0;
                ma=max(ma,max(f[i-1][j],f[i][j-1]));
            }

        }
    }
    cout<<ma;





}
