#include <bits/stdc++.h>
using namespace std;
long long n, dem = 0;
int main()
{
    long long a, b;
    ifstream in1("BT1.INP");
    in1 >> a;
    in1.close();
    ifstream in2("BT2.INP");
    in2 >> b;
    in2.close();
    ofstream out("BT3.OUT");
    out << a + b;
}