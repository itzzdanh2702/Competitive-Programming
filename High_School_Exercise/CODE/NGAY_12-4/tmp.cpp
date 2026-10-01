#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int l, r;
        cin >> l >> r;
        int max_size = 1;
        while((l << max_size) <= r)
            max_size++;
        int ans2 = (r / (1 << (max_size - 1)) - l + 1);
        if(max_size > 1)
            ans2 += (max_size - 1) * max(0, (r / (1 << (max_size - 2)) / 3 - l + 1));
        cout << max_size << " " << ans2 << endl;
    }
}