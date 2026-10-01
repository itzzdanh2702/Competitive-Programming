#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int nx = 1e6+9;
int n, k, a[nx];
string gt[nx], res;
string operator + (string a, string b){
    while(a.size() < b.size()) a = "0" + a;
    while(a.size() > b.size()) b = "0" + b;
    string res = "";
    int du = 0;
    for (int i = a.size() - 1; i >= 0; i--){
        int tmp = (a[i] - '0') + (b[i] - '0') + du;
        res += tmp % 10 + '0';
        du = tmp / 10;
    }
    if (du) res += du + '0';
    while(res.size() > 1 and res[res.size()-1] == '0'){
        res.erase(res.size()-1, 1);
    }
    reverse(res.begin(), res.end());
    return res;
}
string operator * (string a, ll b){
    string res = "";
    int du = 0;
    for (int i = a.size() - 1; i >= 0; i--){
        int tmp = (a[i] - '0') * b + du;
        res += tmp % 10 + '0';
        du = tmp / 10;
    }
    if (du){
        while(du){
            res += du % 10 + '0';
            du /= 10;
        }
    }
    while(res.size() > 1 and res[res.size()-1] == '0'){
        res.erase(res.size()-1, 1);
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    gt[0] = "1";
    for (int i = 1; i <= 1e2; i++){
        gt[i] = gt[i-1] * i;
        cout << gt[i] << "\n";
    }
    assert(1 < 0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        res = res + gt[a[i]];
    }
    cout << (res == gt[k]) ? "Yes" : "No";
}