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

int TC, N;
int a[MAXN];
ll cnt[MAXN], store[9];
ll L, R;

void prepare()
{
    store[0] = 1;
    for (int i = 1; i <= 8; ++i)
        store[i] = store[i - 1] * 10;
}

int digit(int n)
{
    int dem = 0;
    while (n > 0)
    {
        ++dem;
        n /= 10;
    }
    return dem;
}

ll combine(int x, int y)
{
    return x * store[cnt[y]] + a[y];
}

int bin_search1(int l, int r, int pos)
{
    int tmp_pos = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (combine(a[mid], pos) >= L)
        {
            r = mid - 1;
            tmp_pos = mid;
        }
        else
            l = mid + 1;
    }
    return tmp_pos;
}

int bin_search2(int l, int r, int pos)
{
    int tmp_pos = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (combine(a[mid], pos) <= R)
        {
            l = mid + 1;
            tmp_pos = mid;
        }
        else
            r = mid - 1;
    }
    return tmp_pos;
}

int main(int argc, char const *argv[])
{
    prepare(); 
    FAST();
    cin >> TC;
    while (TC--)
    {
        ll ans = 0;
        cin >> N >> L >> R;
        int pos1 = N, pos2 = N;
        for (int i = 1; i <= N; ++i)
            cin >> a[i];
        sort(a + 1, a + N + 1);
        for (int i = 1; i <= N; ++i)
            cnt[i] = digit(a[i]);
        for (int i = 1; i <= N; ++i)
        {
            int tmp_pos1 = bin_search1(1, pos1, i);
            int tmp_pos2 = bin_search2(tmp_pos1, pos2, i);
            if ((tmp_pos1 == 0) || (tmp_pos2 == 0) || (tmp_pos2 < tmp_pos1)) 
                continue;
            else
            {
                ans += tmp_pos2 - tmp_pos1 + 1;
                pos1 = tmp_pos1;
                pos2 = tmp_pos2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}