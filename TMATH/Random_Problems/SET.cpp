#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,A[nmax],B[nmax],k;
set<ll> ms;
set<ll> ms1;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        {
            cin>>A[i];
            ms.insert(A[i]);

        }
    for(int i=1;i<=k;i++)
        cin>>B[i];


    for(int j=1;j<=k;j++)
    {
    ms.erase(B[j]);
    for(int i=1;i<=n-1;i++)
    {
      ms1.insert(A[i+1]-A[i]);


    }
     cout<<*ms1.rbegin();
     ms.insert(B[j]);
    }
    }



