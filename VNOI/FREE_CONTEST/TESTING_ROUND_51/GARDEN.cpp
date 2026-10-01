#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
const int MAXN = 1e5 + 5; 

int n,L;
int a[MAXN],b[MAXN];

struct cmp
{
    bool operator()(pair<int, int> a,pair<int, int> b) const 
    {
        if(a.fi != b.fi)
        return a.fi > b.fi;
        return a.se < b.se; 
    }
};
priority_queue<pii,vector<pii>,cmp> pq;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("GARDEN.inp","r",stdin);
	freopen("GARDEN.out","w",stdout); 
	cin >> n >> L;
	for(int i = 1 ; i <= n ; ++i)
	{
		cin >> a[i] >> b[i];
		pq.push({a[i],b[i]});
	}	
	while((!pq.empty()) && (L > 0))
	{
		pii tmp = pq.top(); 
		pq.pop(); 
		int tmp1 = (pq.top().fi - tmp.fi)/tmp.se + 1;
		if(L - tmp1 <= 0)
		{
			tmp.fi += L * tmp.se;
			pq.push(tmp); 
			L = 0;
		}
		else  
		{
			L -= tmp1;
			tmp.fi += tmp1 * tmp.se;                              
			pq.push(tmp); 
		}
		// Ta co : 
	}
	cout << pq.top().fi; 
	return 0;
}