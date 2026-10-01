/// Code by Duc Anh A2K51PBC
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll a[nmax],n,dem=0,dem1=0,chan[nmax],le[nmax],ans,ans1,h,kq,kq1;
vector<ll> v;
vector<ll> v1;
int main()
{
    cin>>n>>h;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i%2==0)
        {
            dem++;
            chan[dem]=a[i];
        }
       else if(i%2==1)
        {
            dem1++;
            le[dem1]=a[i];
        }
    }
    sort(chan+1,chan+dem+1);
    sort(le+1,le+dem1+1);
    for(int i=1;i<=h;i++)
    {
        auto it=lower_bound(le+1,le+dem1+1,i);      
        if(it-le!=dem1+1)
        ans=it-le-1;
        else 
        ans=dem1;
        
        auto it1=lower_bound(chan+1,chan+dem+1,h-i+1);
        if(it1-chan==dem+1)
        ans1=dem;
        else 
        ans1=it1-chan-1;
        kq=ans+ans1;
        kq1=n-kq;
        v.push_back(kq1);
    }
    sort(v.begin(),v.end());
    for(auto it:v)
    {
        if(it==v[0])
        
        {
            v1.push_back(it);
        }
    }
    cout<<v[0]<<" ";
    cout<<v1.size();
        
    }
    


    