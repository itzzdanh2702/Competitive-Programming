#include <bits/stdc++.h>
using namespace std;

string S;
int Z[1000005];

int main()
{
    cin >> S;

    int n = (int)S.size();
    for (int i = 1, l = 0, r = 0; i < n; i++)
    {
        if (i <= r)
            Z[i] = min(Z[i - l], r - i + 1);
        while (i + Z[i] < n && S[Z[i]] == S[i + Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
    }

    for (int i = 0; i < n; i++)
        if (i + Z[i] >= n)
            cout << i << ' ';
    cout << n << '\n';
}