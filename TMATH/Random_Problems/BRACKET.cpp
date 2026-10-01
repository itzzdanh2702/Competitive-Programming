#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll P=0;
stack<ll> st;
string S;
int main()
{
    getline(cin,S);
    for(int i=0;i<=S.size()-1;i++)
    {
        if((S[i]=='(') or (S[i]=='[') or (S[i]=='{'))
            st.push(S[i]);
        else if((S[i]==')') and (st.top()=='('))
                {
                    st.pop();
                    P++;
                }
        else if((S[i]==']') and (st.top()=='['))
                {
                    st.pop();
                    P+=2;
                }
        else if ((S[i]=='}') and (st.top()=='{'))
                {
                    st.pop();
                    P+=3;
                }
         else cout<<"NO";

        }
    if(st.size()==0)
    cout<<"YES"<<" "<<P;
}
