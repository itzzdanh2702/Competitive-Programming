#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;
ll X[100];
ll a, b, c, d;
int main()
{
  
    cin >> b >> c >> d;
    X[1] = b;
    for(int i = 2 ; i <= d ; ++i)
    {
        X[i] = X[i - 1] * b + c;
    }
    cout << X[d];

    return 0;
}
