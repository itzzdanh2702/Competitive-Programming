#include <iostream>
#include <map>
#include <unordered_set>

using namespace std;

int main() {
    // Sử dụng map với multiset là giá trị để lưu nhiều giá trị cho cùng một key.
    map<int, unordered_multiset<int>> myMap;

    // Chèn nhiều giá trị vào cùng một key trong map.
    myMap[1].insert(10);
    myMap[1].insert(20);
    myMap[1].insert(30);

    // Chèn thêm giá trị cho cùng một key.
    myMap[1].insert(25);

    // In ra tất cả các giá trị cho key là 1.
    cout << "Cac gia tri cho key 1: ";
    for (const int& value : myMap[1]) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}
