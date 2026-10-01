#include<bits/stdc++.h> 

using namespace std; 

void FAST(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
}

int main(){
    FAST(); 
    int TC; 
    cin >> TC; 
    while(TC--){
        int n,cnt_odd = 0,cnt_even = 0,dem = 0; 
        cin >> n;
        int a[n + 1];  
        vector<int> even; 
        for(int i = 1 ; i <= n ; ++i){
            cin >> a[i];
            if(a[i] % 2 == 0){
                ++cnt_even;
                even.push_back(a[i]);  
            }
            else{
                ++cnt_odd; 
            }
        }
        sort(even.begin(),even.end()); 
        for(int i = 1 ; i < even.size() ; ++i){
            if(even[i] - even[i - 1] == 2){
                ++dem; 
            }
        }
        cout << max(cnt_odd,cnt_even - dem) << '\n';
    }
}