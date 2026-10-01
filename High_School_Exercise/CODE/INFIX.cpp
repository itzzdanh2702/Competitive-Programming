
#pragma GCC optimize ("O2")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
const long long MOD=1000000007;
#define MAXN 1000005


void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
}

int cal(char x)
{
    if(x=='(')
        return 0;
    if(x=='+' or x=='-')
        return 1;
    if(x=='*' or x=='/')
        return 2;
}

string s;
stack<char> S;
string ans;

int main()
{
  freopen("INFIX.INP" ,"r" ,stdin);\
  freopen("INFIX.OUT" ,"w" ,stdout);
    FAST();
    cin>>s;
    for(char x : s)
    {
        if(x=='(')
            S.push(x);
        else if('0'<=x and x<='9')
            ans+=x;
        else if(x==')')
        {
            while(!S.empty() and S.top()!='(')
            {
                ans+=S.top();
                S.pop();
            }
            if(!S.empty() and S.top()=='(')
                S.pop();
        }
        else
        {
            while(!S.empty() and cal(S.top())>=cal(x))
            {
                ans+=S.top();
                S.pop();
            }
            S.push(x);
        }
    }
    while(!S.empty())
    {
        ans+=S.top();
        S.pop();
    }
    cout<<ans;
}
