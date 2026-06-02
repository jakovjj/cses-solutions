#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll n, sum, dp[5008][5008];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  for (int i = 0; i < n; i++) {cin >> dp[i][i]; sum+=dp[i][i];}
  for (int k = 1; k < n; k++) {
  	for (int i = 0; i < n-k; i++) {
  		int j = i+k;
  		dp[i][j] = max(  (dp[i][i]-dp[i+1][j]), (dp[j][j]-dp[i][j-1])  );
	  }}	
  cout << (sum+dp[0][n-1])/2;
  
  return 0;
}

