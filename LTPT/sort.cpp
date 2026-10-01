#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2 * 100000
#define fi first
#define se second
const int oo = 1e9;

int a[MAXN];
int n;

int main()
{
    cin >> n;
    for(int i = 1 ; i <= n ; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1 , a + n + 1);
    for(int i = 1 ; i <= n ; ++i)
    {
        cout << a[i] << ' ';
    }
}
