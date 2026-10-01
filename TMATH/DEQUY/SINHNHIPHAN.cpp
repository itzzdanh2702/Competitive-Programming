#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

long long power(long long a, long long b)
{
    long long result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (result * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }
    return result;
}

long long modInverse(long long a)
{
    return power(a, MOD - 2);
}
long long combination(int n, int k)
{
    if (k > n - k)
    {
        k = n - k;
    }
    long long result = 1;
    for (int i = 0; i < k; i++)
    {
        result = (result * (n - i)) % MOD;
        result = (result * modInverse(i + 1)) % MOD;
    }
    return result;
}

int main()
{
    int N, M;
    cin >> N >> M;

    long long result = 1;

    for (int i = 2; i * i <= M; i++)
    {
        if (M % i == 0)
        {
            int count = 0;
            while (M % i == 0)
            {
                count++;
                M /= i;
            }
            result = (result * combination(N + count - 1, count)) % MOD;
        }
    }

    if (M > 1)
    {
        result = (result * combination(N + 1 - 1, 1)) % MOD;
    }

    cout << result << endl;

    return 0;
}
