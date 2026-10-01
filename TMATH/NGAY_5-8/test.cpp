#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pii pair<ll, ll>
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


ll a,b,c;
int TC; 
ll d[4]; 

void solve(ll x,ll y,ll z)
{
    // quy uoc x la so nho nhat
    ll tmp = (y - x)/4;
    z += 5 * tmp; 
    x += 7 * tmp; 
    y += 3 * tmp;
    if((x == y) && (y == z))
    {
        cout << tmp << '\n'; 
        return; 
    } 
    if(abs(x - z) % 3 == 0)
        cout << tmp + abs(x - z)/3;
    else 
        cout << tmp + abs(x - z); 
    cout << '\n'; 

}
int main(int argc, char const *argv[])
{
    FAST();
    // freopen("tmp.inp","r",stdin);
    // freopen("tmp.out","w",stdout);
    cin >> TC; 
    while(TC--)
    {
        cin >> a >> b >> c; 
        int tmp1 = a % 2;
        int tmp2 = b % 2;
        int tmp3 = c % 2;  
        if(((tmp1 != tmp2) || (tmp2 != tmp3) || (tmp3 != tmp1)) || ((a + b + c) % 3 != 0)) 
        {
            cout << "-1" << '\n'; 
            continue; 
        }
        int tmp4 = a % 4;
        int tmp5 = b % 4; 
        int tmp6 = c % 4; 
        if((tmp4 == tmp5) && (tmp4 != tmp6))
        {
            if(b > a)
            {
                solve(a,b,c); 
            }
            else 
            {
                solve(b,a,c); 
            }
        }
        else if ((tmp5 == tmp6) && (tmp5 != tmp4))
        {
            if(b > c)
            {
                solve(c,b,a); 
            }
            else 
            {
                solve(b,c,a); 
            }
        }
        else if ((tmp4 == tmp6) && (tmp4 != tmp5))
        {
            if(a > c)
            {
                solve(c,a,b); 
            }
            else 
            {
                solve(a,c,b); 
            }
        }
        else if ((tmp4 == tmp5) && (tmp5 == tmp6))
        {
            if(a == max({a,b,c}))
            {
                if(b == max(b,c))
                {
                    solve(c,b,a);
                    continue;
                }
                else if (c == max(b,c))
                {
                    solve(b,c,a);
                    continue;
                }
            }
            else if(b == max({a,b,c}))
            {
                if(a == max(a,c))
                {
                    solve(c,a,b);
                    continue;
                }
                else if (c == max(a,c))
                {
                    solve(a,c,b);
                    continue;
                }
            }
            else if(c == max({a,b,c}))
            {
                if(a == max(a,b))
                {
                    solve(b,a,c);
                    continue;
                }
                else if (b == max(b,c))
                {
                    solve(a,b,c);
                    continue;
                }
            }
            
        }        
    }
    

    return 0;
}