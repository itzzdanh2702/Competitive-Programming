#include<bits/stdc++.h>
#define str string
#define chr char
#define ll long long
#define fi first
#define se seconds

ll const nmax=1e6+5;
ll const mod=1e9+7;

using namespace std;

ll n,k,a[nmax],dp[1005][1005],mi=1e18,res=0;
chr s;
priority_queue<int> pq;

ll get(str a){
    if(a[1]=='+') return 1;
    else return 2;
}

int main(){
//    freopen("THAMLAM.inp","r",stdin);
//    freopen("THAMLAM.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    while(cin >> s){
        if(s=='+'){
            int x;
            cin >> x;
            pq.push(x);
        }
        else{
            while(!pq.empty()){
                ll tmp=pq.top();
                pq.pop();
                if(pq.top()!=tmp) break;
            }
        }
    }
    cout << pq.size() << '\n';
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}
