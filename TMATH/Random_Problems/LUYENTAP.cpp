#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nmax 1000000
ll dem=0;
string S,P;
bool check(string Q)
{

    string G;
    G="";
    for(int i=Q.size()-1;i>=0;i--)
    {
        G+=Q[i];
    }
    if(G==Q) return true;
    else return false;

}
int main()
{
    cin>>S;
    dem=1;
    for(int i=1;i<=S.size()-1;i++)
    {
        if(S[i]==S[i-1]) dem++;
    }

    if((check(S)) and (dem!=S.size()))  cout<<S.size()-1;
    else if(dem==S.size())   cout<<"0";
    else cout<<S.size();
}
