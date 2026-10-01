#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll n;
ll fi, se, thir;
ll a[nmax];
bool check;
vector<ll> v, v1;
bool d[nmax];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll tmp = 2;
    d[1] = true;
    d[2] = true;
    v1.push_back(a[1]);
    v1.push_back(a[2]);
    for (int i = 3; i <= n; i++)
    {
        if (a[i] - a[tmp] == a[2] - a[1])
        {
            tmp = i;
            d[i] = true;
            v1.push_back(a[tmp]);
        }
    }
    // for(auto x: v1)
    // cout<<x<<' ';
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == false)
        {
            v.push_back(a[i]);
        }
    }
    // for(auto x:v)
    // cout<<x<<' ';
    bool check = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1)
            break;
        else if (v[i + 1] - v[i] == v[1] - v[0])
        {
            continue;
        }
        else
        {
            check = 0;
            break;
        }
    }
    /**/
    // cout<<v.size()<<' ';
    if (check == 1)
    {
        for (auto x : v1)
            cout << x << ' ';
        cout << endl;
        for (auto x : v)
            cout << x << ' ';
        return 0;
    }
    else
    {
        vector<ll> v;
        vector<ll> v1;
        bool check = 1;
        memset(d, false, sizeof(d));
        d[1] = true;
        d[3] = true;
        v.push_back(a[1]);
        v.push_back(a[3]);
        ll tmp1 = 3;
        for (int i = 4; i <= n; i++)
        {
            if (a[i] - a[tmp1] == a[3] - a[1])
            {
                tmp1 = i;
                d[i] = true;
                v1.push_back(a[tmp1]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (d[i] == false)
            {
                v.push_back(a[i]);
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            if (i == v.size() - 1)
                break;
            else if (v[i + 1] - v[i] == v[1] - v[0])
            {
                continue;
            }
            else
            {
                check = 0;
                break;
            }
        }
        if (check == 1)
        {
            for (auto x : v1)
                cout << x << ' ';
            cout << endl;
            for (auto x : v)
                cout << x << ' ';
            return 0;
        }
        else
        {
            vector<ll> v;
            vector<ll> v1;
            bool check = 1;
            memset(d, false, sizeof(d));
            d[2] = true;
            d[3] = true;
            ll tmp1 = 3;
            v1.push_back(a[2]);
            v1.push_back(a[3]);
            for (int i = 4; i <= n; i++)
            {
                if (a[i] - a[tmp1] == a[3] - a[2])
                {
                    tmp1 = i;
                    d[i] = true;
                    v1.push_back(a[tmp1]);
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (d[i] == false)
                {
                    v.push_back(a[i]);
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                if (i == v.size() - 1)
                    break;
                else if (v[i + 1] - v[i] == v[1] - v[0])
                {
                    continue;
                }
                else
                {
                    check = 0;
                    break;
                }
            }
            if (check == 1)
            {
                for (auto x : v1)
                    cout << x << ' ';
                cout << endl;
                for (auto x : v)
                    cout << x << ' ';
                return 0;
            }
            else
                cout << "-1";
        }
    } 
}
