#include<bits/stdc++.h>
using namespace std;
#define ll long long

string n;
stack<char> a,b;
int main()
{

    cin>>n;
    ll t=0;

    for (ll i=0;i<n.size();i++)
    {
         if (n[i]!='>' && n[i]!='<' && n[i]!='-') a.push(n[i]);
         else if (n[i]=='>')
         {
         	if (!b.empty()){
             a.push(b.top());
             b.pop();
         }
         }
         else if (n[i]=='<')
         {
         	if (!a.empty()){
             b.push(a.top());
             a.pop();
         }
         }
         else if (n[i]=='-')
         {
            if (!a.empty()) a.pop();
         }
    }
    while (!b.empty())
    {
        a.push(b.top());
        b.pop();
    }
    while (!a.empty())
    {
        b.push(a.top());
        a.pop();
    }
    while (!b.empty())
    {
        cout<<b.top();
        b.pop();
    }


}
