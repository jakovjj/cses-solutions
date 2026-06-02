#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double n;
double sum;
ll dp[503][62655];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  ll mod = 1e9+7;
  cin >> n;
  sum = (n*(n+1))/4;
  
  if (floor(sum) != sum) {cout << "0"; return 0;}
  
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
  	for (int j = 0; j < sum+1; j++) {
  		
  		if (i <= j) {
  			dp[i][j] = dp[i-1][j] + dp[i-1][j-i];
		}
		else {dp[i][j] = dp[i-1][j];}	
  		
  		
  		dp[i][j] %= mod;
	  }
  }
  
  /*
  for (int i = 0; i < n; i++) {
  	for (int j = 0; j < sum+1; j++) {
  		cout << dp[i][j] << " ";
	  } cout << endl;
  }
  */
  
  cout << dp[int(n)-1][int(sum)];
  
  return 0;
}

//JJ

