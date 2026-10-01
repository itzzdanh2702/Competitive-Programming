#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,tmp,kq=0;;
vector<ll> v;
int main()
{
//freopen("block.inp","r",stdin);
//freopen("block.out","w",stdout);
  v.push_back(-1);
  cin>>n;
  for (int i=1;i<=n;i++)
  {
      cin>>x;
      v.push_back(x);
  }
 
  while (v.size()>1)
  {
      ll mi=1e18;
      for (int i=1;i<v.size()-1;i++)
      {
          if (v[i]+v[i+1]<mi)
          {
              mi=v[i]+v[i+1];
              tmp=i;
          }
      }
     if (mi!=1e18) kq+=mi;
      v[tmp+1]=mi;
      v.erase(v.begin()+tmp);

  }
cout<<kq;
}

