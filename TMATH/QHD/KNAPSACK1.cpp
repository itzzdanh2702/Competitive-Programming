#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAX_K = 5005;

int K, N;
int Value[MAXN], Weight[MAXN];
int Max_Cost[2][MAX_K];

int main()
{
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> Weight[i] >> Value[i];
    for (int j = 0; j <= K; j++)
        Max_Cost[0][j] = 0;

    for (int i = 0; i < 2; i++)
        Max_Cost[i][0] = 0;
 
    int before = 0, current = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            Max_Cost[current][j] = Max_Cost[before][j];
            if (Weight[i] <= j)
                Max_Cost[current][j] = max(Max_Cost[current][j], Max_Cost[before][j - Weight[i]] + Value[i]);
        }
        current = 1 - current;
        before = 1 - before;
    }
    cout << max(Max_Cost[0][K],Max_Cost[1][K]);

    return 0;
}