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

int TC;
int a, b;
string S;
pair<int, int> store[MAXN];
int kq = 0;
int dem = 0;
int st = 0;
int en = 0;
bool check = 0;
bool ok[MAXN];
bool ok1[MAXN];
int main()
{
        FAST();
        cin >> TC;
        while (TC--)
        {
                cin >> a >> b >> S;
                for (int i = 0; i < S.size(); ++i)
                {
                        if ((S[i] == '1') && (!check))
                        {
                                check = 1;
                                st = i;
                        }
                        else if ((S[i] == '1') && (check))
                        {
                                if ((S[i + 1] == '0') or (i == S.size() - 1))
                                {
                                        check = 0;
                                        en = i;
                                        ++dem;
                                        store[dem].fi = st;
                                        store[dem].se = en;
                                        st = 0;
                                        en = 0;
                                }
                        }
                }
                for (int i = 1; i <= dem; ++i)
                {
                        if (i == 1)
                        {
                                if (b * (store[i + 1].fi - store[i].se) <= a)
                                {
                                        kq += a + b * (store[i + 1].fi - store[i].se);
                                        ok[i + 1] = 1;
                                }
                                else
                                {
                                        kq += 2 * a;
                                        ok1[i] = 1;
                                }
                        }
                        else
                        {
                                if (b * (store[i + 1].fi - store[i].se) <= a)
                                {
                                        if (ok[i])
                                        {
                                                kq += b * (store[i + 1].fi - store[i].se);
                                        }
                                        else
                                        {
                                                kq += a + b * (store[i + 1].fi - store[i].se);
                                        }
                                        ok[i + 1] = 1;
                                }
                                else
                                {
                                        if (ok1[i])
                                                kq += a;
                                        else
                                                kq += 2 * a;
                                        ok1[i + 1] = 1;
                                }
                        }
                }
                cout << kq << '\n';
        }
}