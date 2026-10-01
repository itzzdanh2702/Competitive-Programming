#include<bits/stdc++.h>
using namespace std;
string s;
stack<string> S;
int main()
{
  freopen("PREFIX.INP","r",stdin);
  freopen("PREFIX.OUT","w",stdout);
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

    cin>>s;
    for(int i=0;i<=s.size()-1;i++)
    {
        if('a'<=s[i] and s[i]<='z')
            S.push(string(1,s[i]));
        else{
            string Y=S.top();
            S.pop();
            string X=S.top();
            S.pop();
            S.push(s[i]+X+Y);
        }
    }
    cout<<S.top();
}
