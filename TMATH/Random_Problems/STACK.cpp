#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll a[nmax],n,x,b[nmax],dem1=0;
stack<ll> st;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

        if(a[i]==1) cin>>x,st.push(x),b[++dem1]=x;
       else if(a[i]==2) {
            if(st.size()!=0)
            cout<<st.size()<<" "<<st.top()<<endl;
       else cout<<"-1"<<endl;
       }
       else if(a[i]==3) {
            if(st.size()!=0)
        st.pop(),dem1--;
        else cout<<"-1"<<endl;
       }
       else if(a[i]==4)
       {
            if(st.size()!=0)
            {

           for(int i=1;i<=dem1;i++)
            cout<<b[i]<<" ";
            }
            else cout<<"-1"<<endl;
       }

    }
}
