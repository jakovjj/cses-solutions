#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
int a, b, r, tr, temp;
int dp[503][503];
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int mod = 1e9+7;
  
  cin >> a >> b;
  
  if (a > b) {temp = a; a = b; b = temp;}
  
  // Setting up known parts of DP
  for (int i = 0; i < a; i++) {dp[0][i] = 0;}
  for (int i = 0; i < b; i++) {dp[i][0] = 0;}
  for (int i = 1; i < a+1; i++) {dp[i][1] = i-1;}
  for (int i = 1; i < b+1; i++) {dp[1][i] = i-1;}
  for (int i = 1; i < min(a, b)+1; i++) {dp[i][i] = 0;}
  
  //Filling DP
  for (int i = 2; i < a+1; i++) {
  	for (int j = 2; j < b+1; j++) {
  			
  		if (i == j) {continue;}
  		r = 999999999;
  		
  		for (int t = 1; t < j-1; t++) {
  			tr = 1;
			
			tr += dp[i][t]; 
			//cout << "adding " << dp[i][t] << " ";
			tr += dp[i][j-t];
			//cout << "adding " << dp[i][j-t] << " so ";
			
			//dbg
			//cout << tr << " for " << i << ", " << j << " (" << t << " " << j-t << ")" <<  endl;
			
			r = min(r, tr);
		}
		
		for (int t = 1; t < i-1; t++) {
  			tr = 1;
			
			tr += dp[t][j]; 
			//cout << "adding " << dp[t][j] << " ";
			tr += dp[i-t][j];
			//cout << "adding " << dp[i-t][j] << " so ";
			
			//dbg
			//cout << tr << " for " << i << ", " << j << " (" << t << " " << i-t << ")" <<  endl;
			
			r = min(r, tr);
		}
		
		dp[i][j] = r;
		
	}
  }
  
  //DEBUG
  //for (int i = 1; i < a+1; i++) {cout << endl; for (int j = 1; j < b+1; j++) {cout << dp[i][j] << " ";}}
  
  //Result
  cout << dp[a][b];
  
  return 0;
}
 



