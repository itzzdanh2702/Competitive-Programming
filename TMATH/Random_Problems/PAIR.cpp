#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
string a[nmax],b[nmax];
pair<string,string> s[nmax];
ll n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
        s[i].first=a[i];
        s[i].second=b[i];
        cout<<s[i].second<<" "<<s[i].first<<endl;
    }
}
