#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll mod = 1e9+7; const ll inf = 1e18;

ll n, k, dp[503][250003], invmx;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {dp[i][0] = 1; dp[i][(i*(i-1))/2] = 1;}
  
  for (ll i = 1; i <= n; i++) {
  	invmx = i*(i-1)/2;
	for (ll j = 1; j <= invmx/2; j++) {
		if (j >= i) dp[i][j] = dp[i][j-1]+dp[i-1][j]-dp[i-1][j-i];
		else dp[i][j] = dp[i][j-1]+dp[i-1][j];
		
		if (dp[i][j] < 0) dp[i][j] += mod;
		dp[i][j] %= mod;
	}
	for (ll j = 1; j <= invmx; j++) dp[i][invmx-j] = dp[i][j];
  }
  
  cout << dp[n][k];

  return 0;
}


