#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while (t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for (int i=0; i<n; i++)
	        cin>>arr[i];
	    int count=0, child=n;
	    sort(arr, arr+n);
	    for (int i=0; i<n; i++){
	        if (child>0 && arr[i]<child){
	            count+=1;
	            child-=arr[i];
	        }
	    }
	    cout<<count<<endl;
	}
	return 0;
}