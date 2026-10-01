#include<bits/stdc++.h>
using namespace std ;
#define ll long long
long long n , k , a[200005] , kq = 0 ;
map<long long , long long> mp[10] ;
ll scs(long long k)
{
    ll dem = 0 ;
    while(k != 0)
    {
        dem++ ;
        k /= 10 ;
    }
    return dem ;
}
int main ()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> n >> k ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
        for(int j = 0 ; j <= 9 ; j++)
        {
            mp[j][(a[i]*(ll) pow(10 , j)) % k]++ ;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        ll h = scs(a[i]) , du = a[i]%k ;
        if(du == 0)
        {
            du = k ;
        }
        kq += mp[h][k - du] ;
        if((a[i]*(ll) (pow(10 , h)) + a[i])%k == 0)
        {
            kq-- ;
        }
    }
    cout << kq ;
    return 0 ;
}