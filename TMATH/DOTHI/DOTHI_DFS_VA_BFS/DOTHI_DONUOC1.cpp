#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll a,b,c,d;
ll ktra[55][55][55];
struct siu{
      ll b1,b2,b3;
};
int main()
{
   cin>>a>>b>>c>>d;
   ktra[a][0][0]=1;

   queue<siu> cc;
   cc.push({a,0,0});

   while (cc.size())
   {
       siu moc=cc.front();
       cc.pop();
       ll dem=ktra[moc.b1][moc.b2][moc.b3]+1;
       siu tam;
       if (moc.b1>b-moc.b2) tam={moc.b1-(b-moc.b2),b,moc.b3};
       else tam={0,moc.b1+moc.b2,moc.b3};
       if (ktra[tam.b1][tam.b2][tam.b3]==0)
       {
           ktra[tam.b1][tam.b2][tam.b3]=dem;
           cc.push({tam.b1,tam.b2,tam.b3});
       }
       if (moc.b1>c-moc.b3) tam={moc.b1-(c-moc.b3),moc.b2,c};
       else tam={0,moc.b2,moc.b1+moc.b3};
       if (ktra[moc.b1][0][moc.b3]==0)
       {
           ktra[moc.b1][0][moc.b3]=dem;
           cc.push({moc.b1,0,moc.b3});
       }
       if (ktra[0][moc.b2][moc.b3]==0)
       {
           ktra[0][moc.b2][moc.b3]=dem;
           cc.push({0,moc.b2,moc.b3});
       }
       if (ktra[moc.b1][moc.b2][0]==0)
       {
           ktra[moc.b1][moc.b2][0]=dem;
           cc.push({moc.b1,moc.b2,0});
       }
       if (ktra[tam.b1][tam.b2][tam.b3]==0)
       {
           ktra[tam.b1][tam.b2][tam.b3]=dem;
           cc.push({tam.b1,tam.b2,tam.b3});
       }
       if (moc.b2>c-moc.b3) tam={moc.b1,moc.b2-(c-moc.b3),c};
       else tam={moc.b1,0,moc.b2+moc.b3};
       if (ktra[tam.b1][tam.b2][tam.b3]==0)
       {
           ktra[tam.b1][tam.b2][tam.b3]=dem;
           cc.push({tam.b1,tam.b2,tam.b3});
       }
       if (moc.b2>a-moc.b1) tam={a,moc.b2-(a-moc.b1),c};
       else tam={moc.b1+moc.b2,0,moc.b3};
       if (ktra[tam.b1][tam.b2][tam.b3]==0)
       {
           ktra[tam.b1][tam.b2][tam.b3]=dem;
           cc.push({tam.b1,tam.b2,tam.b3});
       }
        if (moc.b3>a-moc.b1) tam={a,moc.b2,moc.b3-(a-moc.b1)};
        else tam={moc.b1+moc.b3,moc.b2,0};
       if (ktra[tam.b1][tam.b2][tam.b3]==0)
       {
           ktra[tam.b1][tam.b2][tam.b3]=dem;
           cc.push({tam.b1,tam.b2,tam.b3});
       }
       if (moc.b3>b-moc.b2) tam={moc.b1,b,moc.b3-(b-moc.b2)};
        else tam={moc.b1,moc.b3+moc.b2,0};
       if (ktra[tam.b1][tam.b2][tam.b3]==0)
       {
           ktra[tam.b1][tam.b2][tam.b3]=dem;
           cc.push({tam.b1,tam.b2,tam.b3});
       }
       if (moc.b1==d || moc.b2==d || moc.b3==d)
       {
           cout<<ktra[moc.b1][moc.b2][moc.b3]-1;
           return 0;
       }


   }
   cout<<-1;

}