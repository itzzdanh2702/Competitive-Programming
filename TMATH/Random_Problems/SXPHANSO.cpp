    #include <bits/stdc++.h>

    using namespace std;
    struct ps
    {
        long long tu, mau;
    };
    void rutgon(ps &x)
    {
        if(x.mau<0)
        {
            x.mau = -x.mau;
            x.tu = -x.tu;
        }
        long long tam = __gcd(x.tu, x.mau);
        x.tu/=tam, x.mau/=tam;
    }
    bool cmp(ps hao, ps dep)
    {
        return hao.tu*dep.mau<hao.mau*dep.tu;
    }
    long long m,n,k,j=0,ha[1005],mb[1005];
    ps ro[1000005];

    int main()
    {
         cin>>m>>n>>k;
         for (long long i=1;i<=m;i++) cin>>ha[i];
         for (long long i=1;i<=n;i++) cin>>mb[i];
         for (long long i=1;i<=m;i++)
         {
            for (long long r=1;r<=n;r++)
            {
                 j++;
                 ro[j].tu=ha[i];
                 ro[j].mau=mb[r];
                 rutgon(ro[j]);
            }
         }
         sort (ro+1,ro+j+1,cmp);
    //	 for (long long i=1;i<=j;i++)
    //	 {
    //	 	cout<<ro[i].tu<<" "<<ro[j].mau<<endl;
    //	 }
    //	 cout<<endl;
         long long v=0,z=1;
         ps chai;
         while (v<k)
         {
            chai.tu=ro[z].tu;chai.mau=ro[z].mau;
            if (z==1) v++;
            else if (ro[z].tu*ro[z-1].mau != ro[z].mau*ro[z-1].tu) v++;
            z++;
        }
        cout<<ro[z-1].tu<<" "<<ro[z-1].mau;
    }
