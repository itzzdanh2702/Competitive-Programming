#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
priority_queue<ll,vector<ll>,greater<ll>> pq;
ll n,a[nmax],S=0,p,q;
int main()
{
   
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pq.push(a[i]);
    }
    
    for(int i=1;i<=n-1;i++)
    {
        if(!pq.empty())
        {
        p=pq.top();
        pq.pop();
        }
        if(!pq.empty())
        {
        q=pq.top();
        pq.pop();
        }
       
        S+=p+q;
        pq.push(p+q);
        
    }
    cout<<S;
}