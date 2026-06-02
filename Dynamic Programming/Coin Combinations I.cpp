#include <bits/stdc++.h>

using namespace std;

int n, x;
long long dp[1000009];
long long c[1000009];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> x;
  
  for (int i = 0; i < n; i++) {cin >> c[i];}
  
  for (int i = 1; i < x+1; i++) {
  	for (int o = 0; o < n; o++) {
  		if (c[o] == i) {dp[i] += 1;}
  		if (i-c[o] >= 0) {dp[i] += dp[i-c[o]];}
  		dp[i] = dp[i]%1000000007;
	  }
  }
  
  //for (int i = 0; i < x+1; i++) {cout << dp[i] << " ";}
  
  cout << dp[x];
  
  return 0;
}


