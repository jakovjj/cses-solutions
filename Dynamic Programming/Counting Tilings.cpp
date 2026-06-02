#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, m, res, dp[1003][1027];

void solve(int b, int c, int bm, int f) {
	if (c == m && bm == (1<<n)-1) {if (f != 0) return; res = (res+dp[m][b])%mod; return;}
	if (bm == (1<<n)-1) {dp[c+1][f] = (dp[c+1][f]+dp[c][b])%mod; return;}
	
	for (int i = 0; i < n; i++) {
		if ((bm&(1<<i)) == 0) {
			solve(b, c, (bm|(1<<i)), f|(1<<i));
			if (i != n-1 && (bm&(1<<(i+1))) == 0) solve(b, c, ((bm|(1<<i))|(1<<(i+1))), f);		
			break;}
	}
	
	return;
}

int main() {
  cin >> n >> m;
  dp[1][0] = 1;
  for (int i = 1; i < m; i++) for (int mask = 0; mask < (1<<n); mask++) solve(mask, i, mask, 0);
  for (int mask = 0; mask < (1<<n); mask++) solve(mask, m, mask, 0);
  
  cout << res;
  return 0;
}


