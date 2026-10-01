    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long 
    #define nmax 1000000
    ll dp[nmax];
    ll n;
    const ll mod=1e9+7;
    int main()
    {
        
        cin>>n;
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        if(n%2==0) cout<<dp[n];
        else cout<<dp[n]+1;

    }