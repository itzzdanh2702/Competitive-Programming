#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,res[nmax];
stack<pair > st;
int main()
{
   int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        if (!st.size()) cout << -1 << " ";
        else{
            while(st.size()){
                if (st.top().fi <= a[i]){
                    st.pop();
                }
                else break;
            }
            if (st.size()) cout << st.top().se << " ";
            else cout << -1 << " ";
        }
        st.push({a[i], i});
    }
}
}
