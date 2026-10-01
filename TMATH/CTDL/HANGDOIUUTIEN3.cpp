#include<bits/stdc++.h>
using namespace std;
const int arr = 1000005;
int n, a[arr], k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);  
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        vector<int> v;
        deque<int> dq;
        while(v.size() < k && i <= n)
        {
            v.push_back(a[i]);
            if(v.size() == k) break;
            i++;
        }
        sort(v.begin(), v.end());
        for(int j = 0; j < v.size(); j++)
        {
            dq.push_back(v[j]);
        }
        while(dq.size() != 0)
        {
            if(dq.size() > 1) cout << dq.front() << ' ' << dq.back() << ' ';
            else cout << dq.front() << ' ';
            dq.pop_front();
            if(dq.empty()) break;
            dq.pop_back();
        }
    }
}