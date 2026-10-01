#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n;
bool isprime[nmax];
void sang()
{
    for(int i=1;i<=nmax;i++)
        isprime[i]=true;
    isprime[0]=isprime[1]=false;

    for(int i=2;i*i<=nmax;i++ )
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=nmax;j+=i)
                isprime[j]=false;
        }
    }
}
int main()
{
    sang();

    cin>>n;
    if(isprime[n])
        cout<<"YES";
    else cout<<"NO";
}
