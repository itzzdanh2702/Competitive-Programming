#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n; // Số lượng người bạn
    cin >> n;
    
    vector<int> A(n); // Số người giàu hơn
    vector<int> B(n); // Số người nghèo hơn
    
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> B[i];
    }
    
    vector<pair<int, int>> wealthAndPoverty(n);
    for (int i = 0; i < n; ++i) {
        wealthAndPoverty[i] = make_pair(A[i] - B[i], i);
    }
    
    sort(wealthAndPoverty.begin(), wealthAndPoverty.end());
    
    int numInvited = 0;
    long long totalWealth = 0;
    
    for (int i = 0; i < n; ++i) {
        int idx = wealthAndPoverty[i].second;
        if (totalWealth + A[idx] >= B[idx]) {
            numInvited++;
            totalWealth += A[idx];
        } else {
            break;
        }
    }
    
    cout << numInvited << endl;
    
    return 0;
}
