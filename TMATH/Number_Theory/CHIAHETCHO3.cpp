#include<bits/stdc++.h>
using namespace std;
#define ll long long
string S;
ll dem=0,p=0,Q=0,q,m=0,dem1=0,dem2=0;
int main()
{
 cin>>S;

 for(int i=0;i<=S.size()-1;i++)
 {
    Q+=int(S[i]-48);

 }
 p=Q%3;
 if((S.size()==1) and (p%3!=0)) cout<<"-1";
 else if(p%3==0) cout<<"0";
 else
 {
 for(int i=0;i<=S.size()-1;i++)
 {

     if(int(S[i]-48)%3==p)
        {
           dem++;
           break;
        }
    if(int(S[i]-48)%3==1)
    {
        dem1++;
    }
    if(int(S[i]-48)%3==2)
    {
        dem2++;
    }
 }
 if(dem!=0) cout<<dem;
 if(dem==0)
 {
     if(p==1)
     {
         if((dem2>=2) and (dem2!=S.size()))
            cout<<"2";
             else cout<<"-1";
     }
     else if(p==2)
     {
         if((dem1>=2) and(dem1!=S.size()))
         {
             cout<<"2";
         }
          else cout<<"-1";
     }
 }


 }



}
