#include <bits/stdc++.h>

using namespace std;

//---------- Define ------------
#define ll long long
#define ld long double
//------------------------------
#define pii pair <int, int>
#define pil pair <ll, ll>
#define fi first
#define se second
//------------------------------
#define tupi tuple <int, int, int>
//------------------------------
#define inf 0x3f3f3f3f

//----------- Const ------------
const ll nx = 1e6+9;
const ll bx = 4e6+9;
const ll mod = 1e9+7;
const ll oo = 1e9;

//------ Declare Variable ------
int n, a[nx], sum = 0;
vector <int> kq;
bool check[nx];

//---------- Function ----------

//------------ Main ------------
int main(){
   freopen("MakeSum.Inp", "r", stdin);
   freopen("MakeSum.Out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    check[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = sum; j >= 1; j--){
            if (j - a[i] >= 0){
                if (!check[j]) check[j] = check[j-a[i]];
            }
        }
    }
    for (int i = 1; i <= sum; i++){
        if (check[i]) kq.push_back(i);
    }
    cout << kq.size() << "\n";
    for (auto x : kq) cout << x << " ";
}
