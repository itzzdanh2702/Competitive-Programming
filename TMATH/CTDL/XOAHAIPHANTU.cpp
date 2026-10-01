#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define nmax 1000000
string S,T;
ll n;
map<char,ll> mp;
vector<ll> v;
int main()
{
    cin>>n;
    while(n--)
    {
        ll dem=0;
        getline(cin,S);
        getline(cin,T);
        S=""+S;
        T=""+T;
        for(int i=1;i<=S.size();i++)
        {
            mp[S[i]]=i;
        }
        for(int i=1;i<=T.size();i++)
        {
            if(mp[T[i]]!=0)
            {
             v.push_back(mp[T[i]]);
            }
            else 
            {
               cout<<"-1"<<endl;
               v.clear();
               break;
            }
        }
        if(v.size()!=0)
        {
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<v[i+1])
            {
              continue;
            }
            else 
            {
                dem++;
            }
        }
        cout<<dem<<endl;

    }
    }
}