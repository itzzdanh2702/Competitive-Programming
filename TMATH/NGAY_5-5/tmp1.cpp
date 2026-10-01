#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll max_value = 5 * 1e6 + 1;

bool is_prime[max_value];
int TC;
int a, b;
int dp[max_value];
int smallest_divisor[max_value];

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void sang()
{
    for (int i = 0; i < max_value; ++i)
    {
        smallest_divisor[i] = 0;
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= max_value; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= max_value; j += i)
            {
                is_prime[j] = false;
                if (smallest_divisor[j] == 0)
                    smallest_divisor[j] = i;
            }
    for (int i = 2; i <= max_value; ++i)
        if (is_prime[i])
            smallest_divisor[i] = i;
}

int extract(int n)
{
    int dem = 0;
    int tmp = n;
    while (tmp > 1)
    {
        int p = smallest_divisor[tmp];
        ++dem;
        tmp /= p;
    }
    return dem;
}

int main()
{
    FAST();
    sang();
    memset(dp, 0, sizeof(dp));
    cout << (1000000000000 / 9997) % 9997;
}
