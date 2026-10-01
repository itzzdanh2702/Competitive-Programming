#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll n;
ll a[MAXN], ans[MAXN];
ll cnt = 0;
ll dem = 0;
ll pos[MAXN];
int merge(ll l, ll r, ll a[], ll mid)
{
    ll cnt = 0;
    vector<ll> x(a + l, a + mid + 1);
    vector<ll> y(a + mid + 1, a + r + 1);
    ll left = 0, rleft = 0;
    while ((left < x.size()) and (rleft < y.size()))
    {
        if (x[left] <= y[rleft])
        {
            a[l] = x[left];
            ++l;
            ++left;
        }
        else
        {
            ans[pos[y[rleft]]] += x.size() - left;
            a[l] = y[rleft];
            ++l;
            ++rleft;
        }
    }
    while (left < x.size())
    {
        a[l] = x[left];
        ++l;
        ++left;
    }
    while (rleft < y.size())
    {
        a[l] = y[rleft];
        ++l;
        ++rleft;
    }
    return cnt;
}
void mergeSort(ll l, ll r, ll a[])
{
    if (l < r)
    {
        ll mid = (l + r) / 2;
        mergeSort(l, mid, a);
        mergeSort(mid + 1, r, a);
        merge(l, r, a, mid);
    }
}

int main()
{
    FAST();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pos[a[i]] = i;
    }

    mergeSort(0, n - 1, a);
    for (int i = 0; i <= n-1; i++)
        cout << ans[i] << ' ';
    
}

