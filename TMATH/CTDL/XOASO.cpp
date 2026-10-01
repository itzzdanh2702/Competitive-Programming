#include<bits/stdc++.h>
using namespace std;
#define nmax 1000000
#define ll long long
ll n,a[100005],res=0;
stack <ll> st;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1 ; i<=n ; i++) cin >> a[i];
    st.push(a[1]);
    for (int i=2 ; i<=n ; i++)
    {
        while (st.size() > 1 && st.top() < a[i])
        {
            ll tmp = st.top();
            st.pop();
            if (st.top() > tmp)
            {
                res++;
                continue;
            }
            st.push(tmp);
            break;
        }
        if (st.size() && st.top() > a[i] && a[i] < a[i+1] && i<n)
            res++;
            
        else st.push(a[i]);
    }
    cout<<n-res;
}