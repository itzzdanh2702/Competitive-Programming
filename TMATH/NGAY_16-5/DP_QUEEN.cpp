#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define fi first
#define se second
const ll nmax = 1e6 + 9;
const ll bmax = 1e9 + 6;
const ll mod = 1e9 + 7;
ll dong[100], cot[100], hh[100], qp[100];
ll n, dem;
void Try(int x)
{
    if (x == n)
        dem++; // Dem nghiem bai toan
    else
    { // Nguoc lai ta se thuc hien nhu note dang duoi
        for (ll i = 0; i < n; i++)
        {
            if (cot[i] == 0 && hh[x - i + n] == 0 && qp[i + x] == 0)
            {
                cot[i] = 1;
                hh[x - i + n] = 1;
                qp[i + x] = 1;
                Try(x + 1); // de thu lai cac truong hop khac
                qp[i + x] = 0;
                hh[x - i + n] = 0;
                cot[i] = 0;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    Try(0);
    cout << dem;
    return 0;
}
/*
Con hau di duoc ca hang ca cot ca cheo
=> Ta danh dau duong cheo chinh, phu va cot cua vi tri con hau dang dung
*/
