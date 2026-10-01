#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax];
string S;
stack<ll> st;

int main()
{
    cin>>S;
    for(int i=0;i<=S.size()-1;i++)
    {
        if((S[i]>='0') and (S[i]<='9'))
        {
            st.push(int(S[i]-'0'));
        }
        else if(S[i]=='*')
        {

            int a=st.top();
            st.pop();
            int b=int(S[i+1]-'0');
            st.push(a*b);

            i++;
        }
        else if(S[i]=='/')
        {

             int a=st.top();
            st.pop();
            int b=int(S[i+1]-'0');
            st.push(int(a/b));

            i++;
        }
        else if(S[i]=='-')
        {
            st.push(-int(S[i+1]-'0'));
            i++;
        }
    }
    ll Q=0;
    for(int i=1;i<=st.size();i++)
    {
        cout<<st.top();
        st.pop();
    }
    cout<<Q;
}
