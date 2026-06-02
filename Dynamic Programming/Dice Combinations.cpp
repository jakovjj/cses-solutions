#include <bits/stdc++.h>

using namespace std;

long long n, r;
long long m = 1000000007;

long long dp[1000009];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n;
  dp[0] = 1;
  
  for (long long i = 1; i < n+1; i++) {
  	r = 0;
  	for (long long j = 1; j <=6 && (i-j) > -1; j++) {
  		r += (dp[i-j]%m);}
	  
	dp[i] = r%m;
  }
  
  //for (int i = 0; i < n+1; i++) {cout << dp[i] << " ";}
  
  cout << dp[n];
  
  return 0;
}


