#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
#define pii pair<ll, ll>
#define fi first
#define se second
const ll MOD = 1e9 + 7;
bool visited[nmax];
ll a, b, x;
ll kimgio,kimphut;
void FAST()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main()
{
    freopen("CLOCK.inp","r",stdin);
    freopen("CLOCK.out","w",stdout);
    FAST();
    cin >> a >> b >> x;
    float t = a+(b+x)/60;
    float p = (b+x)%60;
    float ans = t*30+p*0.5-6*p;
    cout<<min(abs(ans),360-abs(ans));
}