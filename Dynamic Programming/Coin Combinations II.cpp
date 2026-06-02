#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, x, c;
int dp[1000005];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int mod = 1000000007;
  
  cin >> n >> x;
  
  for (int i = 0; i < n; i++) {
  	cin >> c;
  	for (int l = 1; l < x+1; l++) {
  		if (c == l) {dp[l]++;}
  		else if (l-c >= 0) {dp[l]+=dp[l-c];}
  		dp[l]%=mod;
	}
  }
  
  cout << dp[x]%mod;
  
  return 0;
}

//JJ

