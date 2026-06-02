#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 1; i <= (n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
const ll mod = 1e9+7; const ll ofs = 10000;
ll n, x, t[103], dp[103][103][15003], ans;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> x;
  FOR(i, 0, n-1) cin >> t[i];
  sort(t, t+n);

  dp[0][0][ofs] = 1;
  FOR(i, 0, n) FOR (j, 0, n) FOR (k, 0, x+ofs) {
  	if (!dp[i][j][k]) continue;
  	//i -> prefix, j -> open intervals, k -> cost (offset for neg)
  	if (j && t[i]+k <= x+ofs) dp[i+1][j-1][k+t[i]] = (dp[i+1][j-1][k+t[i]]+(j*dp[i][j][k])%mod)%mod;
  	dp[i+1][j+1][k-t[i]] = (dp[i+1][j+1][k-t[i]]+dp[i][j][k])%mod;
  	dp[i+1][j][k] = (dp[i+1][j][k]+((j+1)*dp[i][j][k])%mod)%mod;
  }
  
  FOR (i, 0, x+ofs) ans = (ans+dp[n][0][i])%mod;
  cout << ans;
  return 0;
}
