#include<bits/stdc++.h>
using namespace std;
#define ll long long 

string S[6],a[3];
bool check(string a[3])
{
    string tam[6];
    for(int i=0;i<3;i++)
    tam[i]=a[i];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            tam[i+3]+=a[j][i];
        }
    }
    sort(tam,tam+6);
    for(int i=0;i<6;i++) 
    if(tam[i]!=S[i]) return false;
    return true;
}
int main()
{
    //freopen("B.inp","r",stdin);
    //freopen("B.out","w",stdout);
    for(int i=0;i<6;i++)
    {
        cin>>S[i];
    }
    for(int i=0;i<6;i++)
    {
        a[0]=S[i];
        for(int j=0;j<6;j++)
        {
            if(j==i) continue;
            a[1]=S[j];
        for(int k=0;k<6;k++)
        {
            if((k==i) or (k==j)) continue;
            a[2]=S[k];
            if(check(a))
            {
                for(int i=0;i<3;i++) cout<<a[i]<<endl;
                return 0;
            }
        }
        }
    }
    cout<<"0";
   
}