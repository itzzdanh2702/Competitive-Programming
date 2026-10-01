#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n,f[nmax],b[nmax];
vector<ll> a;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>b[i];
            a.push_back(b[i]);
        }

    for(int i=0;i<a.size();i++)
         {

             a.erase(a.begin()+i);
             for(int i=0;i<a.size();i++)
                cout<<a[i]<<" ";
             cout<<endl;
             a.insert(a.begin()+i,b[i]);
         }
         //5
         //1 2 3 4 5
}



