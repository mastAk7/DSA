#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    int n,m,k;
	    cin>>n>>m>>k;
	    
	    int ans = 0;
	    
	    if(k%m == 0){
	        ans = m*(n - k/m);
	    } else{
	        ans = m*(n - k/m - 1);
	    }
	    if(k%n == 0){
	        ans = max(ans,n*(m - k/n));
	    } else{
	        ans = max(ans,n*(m - k/n - 1));
	    }
	    cout<<ans<<endl;
	}
}
