#include <bits/stdc++.h>

using namespace std;

int n, x;
int c[1000009];
int dp[1000009];
int mod;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> x;

  int inf = 1000000009;
  
  for (int i = 1; i < x+1; i++) {dp[i]=inf;}
  for (int i = 0; i < n; i++) {cin>>c[i];}
  for (int i = 1; i < x+1; i++) {
  	for (int o = 0; o < n; o++) {
  		if (i-c[o] >= 0) {dp[i] = min(dp[i-c[o]]+1, dp[i]);}
	}
  }

  if (dp[x] == inf) {cout << "-1";}
  else {cout << dp[x];}
  
  return 0;
}


