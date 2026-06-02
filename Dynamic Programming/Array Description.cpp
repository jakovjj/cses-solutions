#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int r;
int x[100006];
 
long long odp[119];
long long dp[119];
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> m;
  for (int i = 0; i < n; i++) {cin >> x[i];}
    
  for (int i = 0; i < n; i++) {
  	for (int j = 1; j < m+1; j++) {
  		dp[j] = 0;
  		
  		if (x[i] == j && i == 0) {dp[j]=1;}
  		else if (x[i] == 0 && i == 0) {dp[j]=1;}
  		
  		else if (x[i] == j or x[i] == 0) {
  		  	dp[j] += odp[j];
			if (dp[j] > 1000000007) {dp[j] -= 1000000007;}  	
  			dp[j] += odp[j-1];
  			if (dp[j] > 1000000007) {dp[j] -= 1000000007;}  	
  			dp[j] += odp[j+1];
  			if (dp[j] > 1000000007) {dp[j] -= 1000000007;}   
		  }
		
	  }
	  //for (int i = 1; i < m+1; i++) { cout << dp[i] << " ";} cout << endl;
	  for (int z = 1; z < m+1; z++) {odp[z] = dp[z]%1000000007;} 
	  }
  
  r = 0;
  for (int j = 1; j < m+1; j++) {r+=dp[j]; if (r > 1000000007) {r -= 1000000007;}}
  cout << r;
  
  return 0;
}
 
//JJ


