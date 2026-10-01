#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long n, k;
long long X[1000005];
long long Y[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    X[0] = 1;
    Y[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i <= k)

            X[i] += Y[i - 1];
        else
            X[i] += ((Y[i - 1] - Y[i - k - 1]) + (long long)MOD * MOD) % MOD;
        Y[i] = Y[i - 1] + X[i];
        X[i] %= MOD;
        Y[i] %= MOD;
    }
    cout << X[n];
}

/*

*/
