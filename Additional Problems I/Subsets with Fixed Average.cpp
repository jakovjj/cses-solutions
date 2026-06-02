#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(ll i = 1; i <= (n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int ofs = 1.25e5;

int n, dp[250003], x, v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> x;
  
  dp[ofs] = 1;
  REP(i, n) {
  	cin >> v; v -= x;
	
	if (v <= 0) REP(j, ofs*2) {
		if (!dp[j]) continue;
		dp[j+v] = dp[j+v]+dp[j];
		if (dp[j+v] > mod) dp[j+v] -= mod;
	}
	else for (int j = ofs*2; j >= 1; j--) {
		if (!dp[j]) continue;
		dp[j+v] = dp[j+v]+dp[j];
		if (dp[j+v] > mod) dp[j+v] -= mod;
	}
  }
  
  cout << dp[ofs]-1;
  return 0;
}
