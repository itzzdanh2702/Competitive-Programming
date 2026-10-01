#include<bits/stdc++.h>
using namespace std;
#define ll long long
string S;
ll k,P=0,dem=0;
int ma;
bool check(ll n)
{
    ll dem1=0;
    for(int i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll j=n/i;
            if(j==i) dem1++;
            else dem1+=2;
        }
    }
    if(dem1==2) return true;
    else return false;
}
int tinhtong(string S)
{
    ll P=0;
    int ma=0;
     for(int i=0;i<=S.size()-1;i++)
    {
        P+=int(S[i]-48);
        ma=max(int(S[i]),ma);
    }
    return P*10+int(ma-48);

}

int main()
{
    ll p;
    cin>>p;
    for(int i=1;i<=p;i++)
    {

        cin>>S;
         if(S.size()==1)
         {
             if(check(stoll(S)))
                cout<<"YES";
             else cout<<"NO";

         }
         else
         {
             if(check(tinhtong(S)))
             {
                cout<<"YES"<<endl;

             }
             else cout<<"NO"<<endl;
         }

    }

}
