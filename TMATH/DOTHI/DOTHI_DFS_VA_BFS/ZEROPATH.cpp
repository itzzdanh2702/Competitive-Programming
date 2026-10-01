#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000

ll dem=0,p;

vector<ll> v;

bool check[nmax];
void dequy(int n)
{
    if(check[n]) return;
    check[n]=true;
    for(int i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            dequy((i-1)*(n/i+1));
        }
    }
}
int main()
{
    memset(check,false,sizeof(check));
    cin>>p;
    for(int i=1;i*i<=p;i++)
    {
        if(p%i==0)
        {
            dequy((i-1)*(p/i+1));
        }
    }
    for(int i=0;i<=p;i++)
    {
        if(check[i])
        {
            dem++;
            v.push_back(i);
        }
    }
    cout<<dem<<endl;
    for(auto x:v)
    {
        cout<<x<<' ';
    }

}