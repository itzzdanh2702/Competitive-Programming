#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n;
stack<char> st;
string S,ans;
bool uutien(char p)
{
    if((p=='+') or (p=='-'))
        return 1;
     if(p=='*' or p=='/')
        return 2;
}
int main()
{
    cin>>S;
    for(int i=0;i<=S.size()-1;i++)
    {
        if((S[i]>='0') and (S[i]<='9'))
            ans+=S[i];
        if(S[i]=='(')
        {
            st.push(S[i]);
        }
        else if(S[i]==')')
        {
        while((!st.empty()) and (st.top()!='('))
            {
            ans+=st.top();
            st.pop();
            }
        if((!st.empty()) and (st.top()=='('))
            st.pop();
        }
        else
        {
            while((!st.empty()) and (uutien(st.top())>=uutien(S[i])))
                  {
                      ans+=st.top();
                      st.pop();
                  }
                  st.push(S[i]);
        }



    }
    while(!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    cout<<ans;
}
