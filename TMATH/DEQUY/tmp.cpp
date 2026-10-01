/// Author : manhlinh.a2k51.pbc
/// ..-. .- .-.. .-.. / .. -. / .-.. --- ...- . / .-- .. - .... / .- -. -.- .... .- -. ....
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000000000000
#define rs(x, a) memset(x, (a), sizeof x)
#define BIT(mask, i) (((mask) >> (i)) & 1)
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define FILE(X)                     \
    freopen(#X ".INP", "r", stdin); \
    freopen(#X ".OUT", "w", stdout);

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
string a;
long long res = 1000000000000;

int main()
{
    FAST();
    cin >> TC;
    while (TC--)
    {
        cin >> a;
        int zc = 0;
        int oc = count(a.begin(), a.end(), '1');
        long long ans = oo;
        /// Gọi X là dãy a cần biến thành (X có dạng 000...111...)
        for (int i = 0; i < a.size() - 1; i++)
        {
            if (a[i] == '0')
                zc += 1;  // số chữ số 0 đầu tiên của dãy X
            else
                oc -= 1;  // số chữ số 1 cuối cùng của dãy X
            int k = oc + zc + (a[i] == '1') + (a[i + 1] == '0'); // số phần tử trong dãy X
            if(i == 0)
            {
                cout << k;
                return 0;
            }
            long long temp = (a.size() - k) * (res + 1);         // chi phí xóa những số cần xóa
            /// Note: Nếu a[i]==1 và a[i+1]==0 thì ta swap 2 cái này với nhau
            if (a[i] > a[i + 1]) // Nếu a[i]==1 và a[i+1]==0 thì ta swap 2 cái này
                temp += res;
            ans = min(ans, temp);
        }
        cout << (ans == oo ? 0 : ans) << "\n";
    }
}
