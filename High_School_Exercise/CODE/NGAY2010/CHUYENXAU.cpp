#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005 
string a,b;
int X[5005][5005];
 
int main()
{
    freopen("chuyenxau.INP","r" ,stdin);
    freopen("chuyenxau.OUT","w" ,stdout);
 
    cin>>a>>b;
 
    int n=a.size();
    int m=b.size();
 
    a=" "+a;
    b=" "+b;
 
    for(int i=1;i<=n;i++)
        X[i][0]=i;
 //abcd a
 //x[1][0]=1,x[2][0]=2,x[3][0]=3,x[4][0]=4;
 //x[0][1]=1;
    for(int i=1;i<=m;i++)
        X[0][i]=i;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                X[i][j]=X[i-1][j-1];
            else X[i][j]=min({X[i-1][j],X[i][j-1],X[i-1][j-1]})+1;
        }
    }
 
    cout<<X[n][m];
}
 