#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n;
using namespace std;

int main()
{
    freopen("LIS.inp","r",stdin);
    freopen("LIS.out","w",stdout);
     cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;

    vector<int> f(n+1), b(n+1, INT_MAX);
    b[0] = INT_MIN;
    int kq = 0;
    for (int x: a) {
        int k = lower_bound(b.begin(), b.end(), x) - b.begin();
        b[k] = x;
        kq = max(kq, k);
    }

    cout << kq;
    return 0;
}
