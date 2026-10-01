#include<bits/stdc++.h>

using namespace std;

#define ll long long

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

int n; 
ll S = 0; 
ll a,b;

int main()
{
	FAST(); 
	open_file(); 
	cin >> n; 
	for(int i = 1 ; i <= n ; ++i)
	{
		
		cin >> a >> b; 
		S += ((b + a) * (b - a + 1))/2;
	}
	cout << S;
}