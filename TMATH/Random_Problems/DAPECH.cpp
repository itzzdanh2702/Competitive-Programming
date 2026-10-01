                #include<bits/stdc++.h>
                using namespace std;
                #define nmax 10000000
                int a,b,k,t=0,dem=0;
                 int d[100000]={0},c[nmax],p[nmax],S=0;
                int main()
                {

                 cin>>a>>b>>k;
                 for (int i=1;i<=a;i++)
                 for (int e=1;e<=b;e++) {
                  int x;cin>>x;
                  dem++;
                  c[dem]=x;
                 }
                 sort(c+1,c+dem+1);
                 long long dem1=1,dem2=0;
                 for(int i=1;i<=dem;i++)
                 {
                     if(c[i]==c[i+1])
                        dem1++;
                     else {
                         dem2++;
                         p[dem2]=dem1;
                        dem1=1;

                     }
                 }
                 sort(p+1,p+dem2+1,greater<int>());
                 for(int i=1;i<=k;i++)
                    S+=p[i];
                 cout<<S;
                }
