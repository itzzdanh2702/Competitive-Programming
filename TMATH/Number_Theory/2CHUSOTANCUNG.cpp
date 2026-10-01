#include<bits/stdc++.h>
using namespace std;
long long n,a;
string q;
int main()
{
    cin>>n;
    q=to_string(n);
    a=n%100;
    if(q.size()>=2)
    {
        if(a<10) cout<<"0"<<a%10;
    else cout<<a;
    }
    else cout<<"-1";
}

