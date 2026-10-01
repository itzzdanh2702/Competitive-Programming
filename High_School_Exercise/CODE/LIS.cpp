#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n;
using namespace std;

int main()
{
     cin >> n;
    vector<int> a(n);
    for (int i=1;i<=n;i++) cin >> a[i];

    vector<int> f(n+1), b(n+1, INT_MAX);
    b[0] = INT_MIN;
    int kq = 0;
    for (int i=1;i<=n;i++) {
        int k = lower_bound(b.begin(), b.end(), a[i])-b.begin() ;
        b[k] = a[i];
        kq = max(kq, k);

    }
    cout<<kq;


    return 0;
}
