#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100];
ll cnt  = 0;
int main()
{
    int k = 1;
    int n = 100 ;
    srand(time(NULL));
    for(int i = 0 ; i < n ; ++i)
    {
        a[i] = rand() % 1;
    }
    cout<< k << endl << n << endl;
    for(auto x : a)
    {
        cout<<x<<' ';
        cnt++;
    }
    cout<<endl;

}
