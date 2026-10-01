#include <bits/stdc++.h>
#define nmax 10000005
using namespace std;
bool b[nmax];
void sang()
{
    memset(b,true,sizeof(b));
    b[0]=b[1]=false;
    for (long long i=2;i*i<=nmax;i++)
    {
        if (b[i])
        {
            for (long long j=i*i;j<=nmax;j+=i) b[j]=false;
        }
    }
}
long long m,n,j=0,a[10000005];
int main()
{
    sang();
    cin >> m;
    for (long long i=1;i<=m;i++)
    {
        cin>>n;
        if (b[n])
        {
            j++;
            a[j]=n;
        }
    }
    if (j==0)
    {
        cout<<-1;
        return 0;
    }
    sort(a+1,a+j+1);
    if (j%2==1)
    {
          j--;
          for (long long i=2;i<=j;i+=2) cout<<a[i]<<" ";
          cout<<a[j+1]<<" ";
          for (long long i=j-1;i>=1;i-=2) cout<<a[i]<<" ";
    }
    else
    {
        j--;
        for (long long i=1;i<=j;i+=2) cout<<a[i]<<" ";
        cout<<a[j+1]<<" ";
          for (long long i=j-1;i>=2;i-=2) cout<<a[i]<<" ";
    }
}
