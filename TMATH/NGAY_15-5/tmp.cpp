//LaziChicken - 4/2023

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pli pair <ll, int>
#define pil pair <int, ll>
#define fi first
#define se second
#define dim 3
#define tupi tuple <int, int, int>
#define inf 0x3f

const ll nx = 1e6+9;
const ll bx = 1e3+9;
const ll mod = 1e9+7;

//--------------------------------
int n, a[nx], ans;
bool check = 0;

//--------------------------------
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        if (a[i] == 1){
            ans = i;
            if (i == n and a[1] == 2) check = 0;
            else if (a[i+1] == 2) check = 0;
            else check = 1;
        }
    }
    (check) ? cout << min(ans + 1, n - ans + 1) : cout << min(ans - 1, n - ans + 3);
}
/*
Note:

*/