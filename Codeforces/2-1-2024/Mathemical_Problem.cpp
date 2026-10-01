#include<bits/stdc++.h>

using namespace std;

#define ll long long
const int MAXN = 1e5 + 5;
const ll oo = 1e9;

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int TC;
int N;
vector<string> v[100];


string form_string(char fi,char mid,char en,int length)
{
    string tmp;
    tmp += fi;
    for(int i = 0 ; i < (length - 3)/2 ; ++i)
        tmp += '0';
    tmp += mid;
    for(int i = 0 ; i < (length - 3)/2 ; ++i)
        tmp += '0';
    tmp += en;
    return tmp;
}

void process()
{
    v[1].push_back("1");
    v[3].push_back("169"),v[3].push_back("196"),v[3].push_back("961");
    for(int i = 5 ; i <= 99 ; i += 2)
    {
        for(auto x : v[i - 2])
        {
            v[i].push_back(x + "00");
        }
        v[i].push_back(form_string('1','6','9',i));
        v[i].push_back(form_string('9','6','1',i));
    }

}

int main()
{
    FAST();
    cin >> TC;
    process();
    while(TC--)
    {
        cin >> N;
        for(auto x : v[N])
        cout << x << '\n';
    }

}
