#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll max_value = 1e7;

bool is_prime[max_value + 1];
ll TC;
ll n;
ll dp[max_value + 1];
int smallest_divisor[max_value + 1];
bool d[max_value + 1];
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void sang()
{
    for (int i = 0; i <= max_value; ++i)
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

void extract(int n)
{
    int dem = 0;
    int tmp = n;
    int tmp1 = 0;
    int kq = 1;
    int tmp2 = 0;
    vector<int> prime_factor;
    
    while (tmp > 1)
    {
        int p = smallest_divisor[tmp];
        tmp2 = p;
        if (p != tmp1)
        {
            kq *= (dem + 1);
            d[tmp1] = 0;
            dem = 0;
        }
        if (d[p] == 0)
        {
            tmp1 = p;
            d[p] = 1;
           // cout << tmp1 << ' ';
        }
        ++dem;
        tmp /= p;
    }
    d[tmp2] = 0;
    if (tmp == 1)
    {
        kq *= (dem + 1);
    }
    cout << kq << '\n';
}

int main()
{
    FAST();
    sang();
    cin >> TC;
    while (TC--)
    {
        cin >> n;
        extract(n);
    }
}
// 5 3^2