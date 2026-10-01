#include <bits/stdc++.h>

using namespace std;
struct ps
{
    long long tu, mau;
}
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
ps cong(ps x, ps y)
{
    ps t;
    t.mau = x.mau*y.mau;
    t.tu = x.tu*y.mau + x.mau*y.tu;
    rutgon(t);
    return t;
}
int main()
{
    cin>>a>>b>>c>>d;
    cout<<(a*d+b*c)/bd;
}
