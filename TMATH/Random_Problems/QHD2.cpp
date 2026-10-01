#include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define nmax 1000000
    vector<ll> vec;
    ll n,a[nmax],dem=0,k,s[nmax],dem1=0;
    int main()
    {
      cin>>n>>k;
      for(int i=1;i<=n;i++)
        {
            cin>>a[i];


        }
     for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {

            s[j] = s[j - 1] + a[j];
            if((s[j]==k) and (s[j-1]==0))
                continue;
            else if((s[j]==k) and (s[j-1]!=0))
                dem1++;
            }
           s[i]=0;
        }
        cout<<dem1;



    }
