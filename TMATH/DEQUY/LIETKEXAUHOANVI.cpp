#include <bits/stdc++.h>
using namespace std;

string S, T;
int n;
char kq[16];
int d[16];
int cnt = 0;
int cnt1 = 0;

void xuat()
{
    for (int j = 1; j <= S.size(); ++j)
        cout << kq[j] << ' ';
    cout << endl;
}
void dequy(int i)
{
    for (int j = 1; j <= cnt; ++j)
        if (d[T[j]] > 0)
        {
            kq[i] = T[j];
            d[T[j]]--;
            if (i < S.size() - 1)
                dequy(i + 1);
            else if (i == S.size() - 1)
            {
                xuat();
            }   
            d[T[j]]++;
        }
}
int main()
{
    cin >> S;
    for (int i = 0; i < S.size(); ++i)
    {
        d[S[i]]++;
    }
    sort(S.begin(), S.end());
    S = " " + S;
    for (int i = 1; i <= S.size(); ++i)
    {
        if (S[i] != S[i - 1])
        {
            ++cnt;
            T[cnt] = S[i];
        }
    }
    dequy(1);
}