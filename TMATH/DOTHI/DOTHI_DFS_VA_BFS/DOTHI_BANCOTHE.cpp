#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, ll>
#define fi first
#define se second
char S[100][100], P[100][100];
bool visited[100][100];
ll dp[100][100];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
void bfs(ll i, ll j)
{
    queue<pii> qu;
    qu.push({i, j});
    visited[i][j]=true;
    while (!qu.empty())
    {
        pii top = qu.front();
        qu.pop();
        for (int k = 0; k < 4; k++)
        {
            ll i1 = top.fi + dx[k];
            ll j1 = top.se + dy[k];
            if (!visited[i1][j1])
            {
                if ((i1 >= 0) and (i1 <= 3) and (j1 >= 0) and (j1 <= 3))
                {   
                    if (S[i1][j1] != P[i1][j1])
                    {
                        dp[i1][j1] = dp[top.fi][top.se] + 1;
                    }
                    else
                    {
                        dp[i1][j1] = dp[top.fi][top.se];
                        return;
                    }
                }
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> S[i][j];
        }
        cout<<endl;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> P[i][j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (S[i][j] == P[i][j])
            {
                visited[i][j] = true;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!visited[i][j])
            {
                if (S[i][j] == '1')
                {
                    bfs(i,j);
                    
                }
            }
        }
    }
}