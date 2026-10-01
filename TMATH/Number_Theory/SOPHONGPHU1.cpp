#include<bits/stdc++.h>
using namespace std;
long long n,s=0,i,j,P=1,k,dem=0,t;

bool check(long long n)
{
if(n<2) return false;
for(int i=2;i*i<=n;i++)
    if(n%i==0)
    return false;
return true;
}
bool check1(string n)
{
    string P;
    for(int i=0;i<=n.size()-1;i++)
        {
            P+=n[i];
            if(check(stoll(P))) dem++;
        else break;
        }
        if(dem==n.size()) return true;
        else return false;
}
int main()
{

}

}
