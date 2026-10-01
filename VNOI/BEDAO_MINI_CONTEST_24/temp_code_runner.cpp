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

multiset<pair<int,int>> mu; 
bool check = 1;

int main()
{
    FAST(); 
    open_file();
    pair<int,int> tmp = {3,0}; 
    mu.insert({1,1});
    mu.insert({2,2}); 
    mu.insert({3,3});
    mu.insert({3,4}); 
    while(true)
    {
        auto it = mu.lower_bound(tmp);
        if((it == mu.end()) || ((*it).fi != tmp.fi))
            break; 
        mu.erase(it); 
    }
    for(auto x : mu)
        cout << x.fi << ' ' << x.se << '\n'; 
}