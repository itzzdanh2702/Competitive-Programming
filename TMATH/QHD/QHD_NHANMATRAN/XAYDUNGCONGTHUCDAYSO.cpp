#include <bits/stdc++.h>
using namespace std;
// Hàm nhân 2 ma trận A và B
vector<vector<long long>> multiply(vector<vector<long long>> A, vector<vector<long long>> B)
{
    int n = A.size();
    int m = A[0].size();
    int p = B[0].size();
    vector<vector<long long>> C(n, vector<long long>(p));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            for (int k = 0; k < m; k++)
            {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 1000000007;
            }
        }
    }
    return C;
}

// Hàm tính A mũ k đệ quy
vector<vector<long long>> power(vector<vector<long long>> A, long long k)
{
    int n = A.size();
    vector<vector<long long>> I(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        I[i][i] = 1;
    }
    if (k == 0)
    {
        return I;
    }
    if (k == 1)
    {
        return A;
    }
    vector<vector<long long>> half = power(A, k / 2);
    vector<vector<long long>> result = multiply(half, half);
    if (k % 2 == 1)
    {
        result = multiply(result, A);
    }
    return result;
}

int main()
{
    long long b, c, d;
    cin >> b >> c >> d;

    vector<vector<long long>> A = {{b, c}, {0, 1}};
    vector<vector<long long>> B = {{b}, {1}};
    vector<vector<long long>> C = multiply(power(A, d - 1), B);

    cout << C[0][0] % 1000000007 << endl;
}
