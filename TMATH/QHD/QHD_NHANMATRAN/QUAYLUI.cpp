#include <iostream>
using namespace std;

int *a;
int N, temp = 0;

bool thoa_man(int i, int n) // quy tắc là sau <= trước quan trọng mỗi cái này
{
    if (n == 0)
        return true;
    else
    {
        if (i <= a[n - 1])
            return true;
        else
            return false;
    }
}

void inra(int n)
{
    for (int i = 0; i <= n; i++)
        cout << a[i] << "  ";
    cout << endl;
}

void chon_so_hang(int n = 0)
{
    for (int i = N; i >= 1; i--)
    {
        if (thoa_man(i, n))
        {
            a[n] = i;
            temp += i;
            if (temp == N)
                inra(n);
            else if (temp < N)
                chon_so_hang(n + 1);
            temp -= i;
        }
    }
}

int main()
{
    cin >> N;
    a = new int[N];
    chon_so_hang();

    return 0;
}