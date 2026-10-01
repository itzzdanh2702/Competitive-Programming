#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 3e4 + 5;
const ll MOD = 1e9 + 7;
const ll oo = 1e18;
int n;
bool isprime[MAXN];
ll a[MAXN];
vector<int> v;

void sang()
{
    isprime[0] = isprime[1] = false;
    for(int i = 2 ; i <= sqrt(MAXN) ; ++i)
    {
        if(isprime[i])
        {
            for(int j = i * i ; j <= MAXN ; j += i)
            {
                isprime[j] = false;
            }
        }
    }
}
void phantich(int n)
{
    for(int i = 2 ; i <= sqrt(n) ; ++i)
    {
        if(n % i == 0)
        {
            v.push_back(i);
            while(n % i == 0)
            {
                n/=i;
            }
        }
    }
    if(n > 1)
    {
        v.push_back(n);
    }
}

ll nhan(ll a,ll b)
{
    if(b == 0)
    {
        return 1;
    }
    ll tmp = nhan(a,b/2);
    if(b & 1)
    {
        return ((((tmp % MOD) * (tmp % MOD)) % MOD) * (a % MOD)) % MOD;
    }
    return ((tmp % MOD) * (tmp % MOD)) % MOD;
}
void kadane()
{
    ll sum = 0;
    ll ma = -oo;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        sum = max(sum,sum + a[i]);
        ma = max(ma,sum);
    }
    cout << ma;
}
void longest_subsequence()
{
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    ll ans = -oo;
    ll b[MAXN];
    for(int i = 1 ; i <= n ; ++i)
    {
        b[i] = oo;
    }
    for(int i = 1 ; i <= n ; ++i)
    {
        ll it = lower_bound(b + 1 , b + n + 1,a[i]) - b;
        b[it] = a[i];
        ans = max(ans,it);
    }
    cout << ans;

}
void solve()
{
    int n, med;
    cin >> n >> med;

    vector<int> v(n);
    int pos;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        if(v[i] == med) {
            pos = i;
        }
    }

    map<int,int> m;
    m[0] = 1;
    int sum = 0;
    for(int i = pos+1; i < n; i++) {
        if(v[i] > med) sum++;
        else sum--;
        m[sum]++;
    }

    ll ans = m[0];
    sum = 0;
    for(int i = pos-1; i >= 0; i--) {
        if(v[i] > med) sum++;
        else sum--;
        ans += m[-sum];
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("tmp1.inp","r",stdin);
    //freopen("tmp1.out","w",stdout);
    //cin >> n;
    //kadane();
    //longest_subsequence();
    solve();
}
///thuat toan kadane
///bai toan tim day con tang dai nhat
