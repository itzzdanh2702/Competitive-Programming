#include<bits/stdc++.h>
using namespace std; 

#define ll long long 
#define fi first 
#define se second
const int MAXN = 1e5 + 5; 

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0); 
}

void open_file()
{
    freopen("task.inp","r",stdin); 
    freopen("task.out","w",stdout); 
}

int q; 
ll id = 0,cnt = 0; 
multiset<pair<ll,ll>> mu; 

int main()
{
    //open_file(); 
    FAST(); 
    cin >> q; 
    while(q--)
    {
        ll type,x;
        cin >> type >> x; 
        if(type == 1)
        {
            ++id; 
            mu.insert({x - cnt,id}); 
        }
        else if (type == 2)
        {
            cnt += x; 
        }
        else 
        {
            while(true)
            {
                auto it = mu.lower_bound({x - cnt,0});
                if((it == mu.end()) || ((*it).fi != x - cnt))
                    break; 
                mu.erase(it); 
            }
        }
    }
    vector<pair<ll,ll>> v;
    for(auto k : mu)
    {
        v.push_back({k.se,k.fi});
    }
    sort(v.begin(),v.end());
    cout << v.size() << '\n';  
    for(auto k : v)
    {
        cout << k.se + cnt << ' '; 
    } 
}