#include<bits/stdc++.h> 

using namespace std;

#define ll long long

const int MAXN = 181;  

void open_file()
{
	freopen("task.inp","r",stdin); 
	freopen("task.out","W",stdout); 
}

void FAST()
{
	ios_base::sync_with_stdio(0); 
	cin.tie(0); 
	cout.tie(0); 
}
	
int b[4]; 
int time[7],per[7],pre_sub[7]; 
long double score[MAXN]; 	

int main()
{
	open_file();
	FAST();
	for(int i = 1 ; i <= 3 ; ++i) 
	{
		cin >> b[i]; 
		for(int sub = 1 ; sub <= b[i] ; ++sub)
		{
			long double ans = 0; 
			int e[7],tmp[7];
			cin >> time[sub] >> per[sub] >> pre_sub[sub];
			if(pre_sub[sub] > 0)
			{
				bool check[7];  
				for(int i = 1 ; i <= pre_sub[sub] ; ++i)
				{
					cin >> e[i]; 
					check[e[i]] = 1; 
				} 
				int total_per = per[sub]; 
				// for lai tat ca cac sub truoc do, luu lai diem toi uu vao tmp 
				// luu lai diem toi uu neu lay sub hien tai
				// for thoi gian score[i] = max(score[i],tmp[i])
				for(int k = 1 ; k < sub ; ++k)
				{
					if(!check[k])
					{	
						for(int i = 1 ; i <= 180 ; ++i)
						{	
							if(time[k] <= i)
								tmp[k] = max(tmp[k],per[i] + tmp[i - time[k]]); 
						}
					}
					else 
						total_per += per[k];
				}
				// 
				for(int i = 1 ; i <= 180 ; ++i)
				{
					if(i >= )
				}
				score[sub] = max()
			}
			for(int i = 1 ; i <= 180 ; ++i)
			{
				if(time[sub] <= i)
				{
					int ma = max(tmp[])
					score[i] = max(score[i],total_per + 
				}
			}
		}		
	}
}