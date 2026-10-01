#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
string S;
stack<ll> st;
vector<ll> ans;
ll k;
int main()
{
    cin>>S>>k;
    for(int i=0;i<S.size();i++)
    {
     if(st.empty()) st.push(S[i]-'0');
     else if((!st.empty()) and (S[i]>st.top()))
     {
        while((!st.empty()) and ((S[i]-'0')>st.top()) and (k>0))
        {
        st.pop();
        k--;
        }
        st.push(S[i]-'0');
     }

     }
     while((!st.empty()) and (k>0))
     {
        st.pop();
        k--;
     }
     while(!st.empty())
     {
        ans.push_back(st.top());
        st.pop();
     }
     for(int i=ans.size()-1;i>=0;i--)
     cout<<ans[i];
    }
