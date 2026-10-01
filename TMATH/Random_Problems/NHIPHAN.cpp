#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 100000
ll a[nmax],length,n;
void xuat()
{
    for(int k=1;k<=length;k++)
        {
            cout<<a[k];

        } cout<<endl;
}
void gen(int n)
{
    for(int i=0;i<=1;i++)
    {
        a[n]=i;
        if(n==length) xuat();
        else gen(n+1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>length;
    gen(1);
}
