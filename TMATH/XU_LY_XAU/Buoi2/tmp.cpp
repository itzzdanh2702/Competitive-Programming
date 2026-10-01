#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t; // Số bộ test
    cin >> t;

    for (int i = 0; i < t; i++) {
        int N, K; // Độ dài N và số K
        cin >> N >> K;

        string S; // Xâu S
        cin >> S;

        // Đếm số lần xuất hiện của các kí tự trong xâu S
        vector<int> char_count(26, 0);
        for (char c : S) {
            char_count[c - 'a']++;
        }

        string P = S; // Xâu P ban đầu bằng xâu S

        // Thay thế kí tự trong xâu P bằng số K lần kí tự đó
        for (int j = 0; j < 26; j++) {
            char c = 'a' + j;
            int replacement = min(K, char_count[j]);
            for (int k = 0; k < replacement; k++) {
                P += c;
            }
        }

        // In xâu P
        cout << P << endl;
    }

    return 0;
}
