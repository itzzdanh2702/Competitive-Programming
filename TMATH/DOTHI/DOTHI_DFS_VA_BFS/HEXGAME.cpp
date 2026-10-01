#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector <int> vi, ans;
map <vector <int>,int> d,d2;
string code[] = {"3027416859", "0413852796", "1520486379", "0263159748"};

vector <int> xoay(vector <int> a, string code)
{
    vector <int> b(a);
    for (int i = 0 ; i <= 9 ; i++)
        b[i] = a[code[i] - '0'];
    return b;
    }

void bfs(vector <int> s)
{
    queue <vector <int>> q;
    d[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        vector <int> u = q.front();
        q.pop();
        if (d[u] > 13) break;
        for (int i = 0 ; i < 2 ; i++)
        {
            vector <int> v = xoay(u,code[i]);
            if (d[v] == 0)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void bfs2(vector <int> s)
{
    queue <vector <int>> q;
    d2[s] = 1;
    if (d[s] > 0)
    {
        cout << d[s] - 1;
        exit(0);
    }
    q.push(s);
    while (!q.empty())
    {
        vector <int> u = q.front();
        q.pop();
        if (d2[u] > 13) break;
        for (int i = 2 ; i < 4 ; i++)
        {
            vector <int> v = xoay(u,code[i]);
            if (d[v] > 0)
            {
                cout << d[v] + d2[u] - 1;
                exit(0);
            }
            if (d2[v] == 0)
            {
                d2[v] = d2[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for (int i = 1 ; i <= 10 ; i++)
    {
        int u;
        cin >> u;
        vi.push_back(u);
    }
    ans = {1, 2, 3, 8, 0, 0, 4, 7, 6, 5};
    bfs(vi);
    bfs2(ans);
    return 0;
}