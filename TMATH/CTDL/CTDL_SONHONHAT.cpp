#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
ll a[nmax],n,k;
string S,P;
stack<ll> st;
vector<ll> v;
int main()
{
    cin>>k;
    cin>>S;
    for(int i=0;i<S.size();i++)
    {
        if((S[i]>='0') and (S[i]<='9'))
        P+=S[i];
    }
    ll q=P.size()-k;
    for(int i=0;i<P.size();i++)
    {
     if(st.empty()) st.push(P[i]-'0');
     else if((P[i]-'0')>=st.top())
        {
            st.push(P[i]-'0');
        }
    else if (!st.empty() and ((P[i]-'0')<st.top())) 
        {
            while((!st.empty()) and (q>0) and ((P[i]-'0')<st.top()))
            {
             st.pop();
             q--;
            }
            st.push(P[i]-'0');
        }
     }
    
     while((!st.empty()) and (q>0))
     {
        st.pop();
        q--;
     }
    while(!st.empty())
    {
        v.push_back(st.top());
        st.pop();
    }
    for(int i=k-1;i>=0;i--)
    {
        cout<<v[i];
    }
}