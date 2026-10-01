#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x1, x2, x3;
int result = -1;

void dfs(int a, int b, int c, int depth) {
    if (a == b && b == c) {
        result = depth;
        return;
    }
    
    if (depth > 100) {
        return;
    }
    
    vector<int> order = {a, b, c};
    sort(order.begin(), order.end());
    
    dfs(order[0] + 3, order[1] + 5, order[2] + 7, depth + 1);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        cin >> x1 >> x2 >> x3;
        
        result = -1;
        dfs(x1, x2, x3, 0);
        
        cout << result << endl;
    }
    
    return 0;
}
