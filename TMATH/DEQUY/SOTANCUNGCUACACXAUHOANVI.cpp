#include <bits/stdc++.h>
using namespace std;
#define ll long long
const long long MOD = 1000000007;
#define MAXN 100005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int n;
map<char, int> cnt;
string S;
int cnt1 = 0,cnt2 = 0;
int cnt3 = 0,cnt4 = 0;

int ham(int q)
{
    int dem = 0;
    int tmp = 5;
    while (q > 0)
    {
        dem += q/tmp;
        q /= tmp;
    }
    return dem;
}
int ham1(int q)
{
    int dem = 0;
    int tmp = 2;
    while (q > 0)
    {
        dem += q/tmp;
        q /= tmp;
    }
    return dem;
}
int main()
{
    FAST();
    cin >> n;
    cin >> S;
    for (int i = 0; i <= S.size() - 1; ++i)
    {
        ++cnt[S[i]];
    }
    for(auto x : cnt)
    {
        cnt1 += ham(x.second);
        cnt3 += ham1(x.second);
    }
    cnt2 = ham(n);
    cnt4 = ham1(n);
    ll tmp1 = cnt2 - cnt1;
    ll tmp2 = cnt4 - cnt3;
    if((tmp1 > 0) and (tmp2 > 0))
    {
        cout << tmp1;
    }
    else 
    {
        cout << 0;
    }

}