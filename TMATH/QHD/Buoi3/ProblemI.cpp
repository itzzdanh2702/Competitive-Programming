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

int n;
int a[MAXN];
int tmp;
int cnt = 0;
int st = oo, en = 0;
int mi = oo;
string S;

int main()
{
    FAST();
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tmp = __gcd(tmp, a[i]);
        if (a[i] == 1)
        {
            ++cnt;
        }
    }
    if (cnt > 0)
    {
        cout << n - cnt;
    }
    else
    {
        for (int i = 1; i <= n - 1; ++i)
        {
            int tmp1 = a[i];
            for (int j = i + 1; j <= n; ++j)
            {
                tmp1 = __gcd(a[j], tmp1);
                if ((tmp1 == 1) && (j - i + 1 < mi))
                {
                    st = i;
                    en = j;
                    mi = en - st + 1;
                }
            }
        }
        int tmp2;
        for (int i = st; i <= en - 1; ++i)
        {
            tmp2 = __gcd(tmp2, a[i]);
        }
        cout << tmp2;
        for (int i = en - 1; i >= st; --i)
        {
            if (__gcd(a[i], a[en]) == 1)
                return cout << en - st - (a[st] == tmp2) + n - 1, 0;
        }
    }
}