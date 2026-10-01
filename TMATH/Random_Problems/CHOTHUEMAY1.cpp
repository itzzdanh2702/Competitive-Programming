
#include<bits/stdc++.h>
using namespace std ;
long long n , s , a[100005] , kq = 0 , kq1 = 0 , h = 0 ;
bool check(long long k)
{
    h = 0 ;
    long long b[100005] ;
    for(int i = 1 ; i <= n ; i++)
    {
        b[i] = a[i] + i*k ;
    }
    sort(b + 1 , b + n + 1) ;
    for(int i = 1 ; i <= k ; i++)
    {
        h += b[i] ;
    }
    if(h <= s)
    {
        return true ;
    }
    return false ;
}
int main ()
{
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) , cout.tie(0) ;
    cin >> n >> s ;
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i] ;
    }
    long long low = 1 , high = n , mid ;
    while(low <= high)
    {
        mid = (low + high)/2 ;
        if(check(mid))
        {
            kq = mid ;
            kq1 = h ;
            low = mid + 1 ;
        }
        else
        {
            high = mid - 1 ;
        }
    }
    cout << kq << " " << kq1 ;
    return 0 ;
}
