#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
#define MAXN 1000005
#define oo 1000000000
void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

static const char pool[] = "abcdefghijklmnopqrstuvwxyz";

int poolSize = sizeof(pool) - 1;
char getRandomChar()
{
    return pool[rand() % poolSize];
}
int main(int argc, char *argv[])
{
    FAST();
    while (true)
    {
        int passLength;
        int numberOfPasswords;
        srand(time(0));
        string pass;
        cin >> passLength;
        cin >> numberOfPasswords;
        for (int j = 0; j < numberOfPasswords; j++)
        {
            for (int i = 0; i < passLength; i++)
            {
                pass += getRandomChar();
            }
            cout << pass << endl;
            pass = "";
        }
    }
    system("PAUSE");
}