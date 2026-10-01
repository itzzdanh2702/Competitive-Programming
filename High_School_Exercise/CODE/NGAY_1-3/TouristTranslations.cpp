#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string s;
    cin >> s;
    string capital = s;
    for (int i = 0; i < s.length(); i++)
    {
        capital[i] = toupper(s[i]);
    }
    string english_small = "abcdefghijklmnopqrstuvwxyz";
    string english_capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (t--)
    {
        string translate;
        cin >> translate;
        for (int i = 0; i < translate.length(); i++)
        {
            if (translate[i] == '_')
            {
                cout << " ";
            }
            else if (translate[i] == '?' || translate[i] == '!' || translate[i] == ',' || translate[i] == '.')
            {
                cout << translate[i];
            }
            else
            {
                int index = english_small.find(translate[i]);

                if (index == -1)
                {
                    index = english_capital.find(translate[i]);
                    cout << capital[index];
                }
                else
                {   
                    cout << s[index];
                }
            }
        }
        cout << endl;
    }

    return 0;
}