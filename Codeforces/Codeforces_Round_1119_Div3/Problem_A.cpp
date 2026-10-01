#include<bits/stdc++.h> 
using namespace std;    

const int MAXN = 21; 

void FAST(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    FAST(); 
    int TC; 
    cin >> TC; 
    while(TC--){
        string S; 
        int a[MAXN + 1]; 
        int n,k;
        int ans = 0;  
        cin >> n >> k; 
        cin >> S; 
        S = " " + S; 
        for(int i = 1 ; i <= n ; ++i){
            a[i] = int(S[i] - 48); 
        }
        for(int i = 1 ; i <= n/k ; ++i){
            bool ok = 0; 
            for(int it = k * (i - 1) + 1 ; it <= k * i ; ++it){
                if(a[it] == 0){
                    ok = 1; 
                    break; 
                }
            }
            if(!ok){
                ++ans;
            }
        } 
        cout << ans << '\n'; 
    }
    return 0; 
}