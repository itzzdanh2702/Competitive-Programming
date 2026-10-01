#include<bits/stdc++.h>
using namespace std;
#define nmax 1000000
#define ll long long
string  S,ans;
stack<ll> st;
ll res;
int main()
{
    cin>>S;
    for(int i=0;i<=S.size()-1;i++)
    {
        if((ans[ans.size()-1]==')') and (S[i]=='('))
            ans.erase(ans.size()-1,1);
        else ans+=S[i],cout<<ans<<endl;
    }
    res=ans.size();
    for(int i=0;i<=S.size()-1;i++)
    {
        if(S[i]=='(') st.push(S[i]);
        else
        {
            if(st.empty()) return cout<<"NO",0;
            else st.pop();
        }
    }
    if(st.empty()) cout<<"YES"<<" "<<res;
    else cout<<"NO";
}
//((()(())))
