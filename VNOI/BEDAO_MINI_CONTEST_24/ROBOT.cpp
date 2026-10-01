#include<bits/stdc++.h>
using namespace std; 

#define ll long long 
const int MAXN = 1e5 + 5; 

void FAST()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0); 
}

void open_file()
{
    freopen("task.inp","r",stdin); 
    freopen("task.out","w",stdout); 
}

int TC; 
int n,k; 
int x,y,z,t;
int xuoi[MAXN][4]; 
char mo[MAXN],huong[] = {'L','R','U','D'};

int dist(int x1,int y1,int z1,int t1)
{
    return abs(z1 - x1) + abs(t1 - y1); 
}

int main()
{
    //open_file(); 
    FAST();
    cin >> TC; 
    while(TC--)
    {
        bool check = 0; 
        cin >> n >> k; 
        cin >> x >> y >> z >> t; 
        for(int i = 1 ; i <= n ; ++i)
        {
            cin >> mo[i]; 
            for(int j = 0 ; j <= 3 ; ++j)
            {
                if(mo[i] == huong[j])
                {
                    xuoi[i][j] = xuoi[i - 1][j] + 1; 
                }
                else 
                {
                    xuoi[i][j] = xuoi[i - 1][j]; 
                }
            }   
        }
        for(int st = 1 ; st <= n - k + 1 ; ++st)
        {
            int en = st + k - 1; 
            int tmp_st = x,tmp1_st = y; 
            tmp_st -= (xuoi[st - 1][0] + xuoi[n][0] - xuoi[en][0]); 
            tmp_st += (xuoi[st - 1][1] + xuoi[n][1] - xuoi[en][1]);
            tmp1_st -= (xuoi[st - 1][2] + xuoi[n][2] - xuoi[en][2]);
            tmp1_st += (xuoi[st - 1][3] + xuoi[n][3] - xuoi[en][3]);
            if(dist(tmp_st,tmp1_st,z,t) <= k)
            {
                check = 1; 
                break;
            }
        }
        if(check)
            cout << "YES";
        else 
            cout << "NO";
        cout << '\n';
    }
}