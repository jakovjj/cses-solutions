#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast","unroll-loops")
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
const ll inf = 1e18;

ll n, k, a[3003], pref[3003], c[3003][3003], dp[3003], dpn[3003];
void solve(int l, int r, int ql, int qr) {
	if (l > r) return;
	
	int mid = (l+r)/2;
	ll res = inf; int idx = -1;
	
	FOR(i, ql, min(qr, mid)) {
		ll x = dp[i-1]+c[i][mid];
		if (x <= res) {
			res = x;
			idx = i;
		}
	}
	
	dpn[mid] = res;
	solve(l, mid-1, ql, idx);
	solve(mid+1, r, idx, qr);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> k;
  REP(i, n) {cin >> a[i]; pref[i] = pref[i-1]+a[i];}
  REP(i, n) FOR(j, i, n) c[i][j] = (pref[j]-pref[i-1])*(pref[j]-pref[i-1]);
  REP(i, n) dp[i] = c[1][i];
  
  REP(i, k-1) {
  	solve(1, n, 1, n);
  	REP(j, n) {dp[j] = dpn[j]; dpn[j] = 0;}
  }
  
  cout << dp[n];

  return 0;
}


