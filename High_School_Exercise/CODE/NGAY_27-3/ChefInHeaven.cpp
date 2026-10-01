#include<bits/stdc++.h>
using namespace std;
#define ll long long
int TC;
int l;
string s;

void FAST()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
int main()
{
	FAST();
	cin>>TC;
	while(TC--)
	{
	    cin>>l;
	    cin>>s;
	    int ans1=0, ans2=0;
	    int ans=0;
	    for(int i=0; i<s.size(); i++)
	    {
	    	if(s[i]=='0') ans1++;
	    	else ans2++;
	    	if(ans2*2>=ans1+ans2)
	    	{
	    		ans=1;
	    		break;
			}
		}
		if(ans==0) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}