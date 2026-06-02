#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(ll i = 1; i <= (n); i++)
#define FOR(i, a, b) for (ll i = a; i <= (b); i++)
const ll inf = 1e18;

ll pref[550003][61], ans, n, q, b, x, seg[550003][61], mn[61];

void upd(int l, int r, int idx, int qx) {
	if (l > qx || r < qx) return;
	if (l == qx && r == qx) {seg[idx][b] = x; return;}
	int m = (l+r)/2;
	upd(l, m, idx*2, qx); upd(m+1, r, idx*2+1, qx);
	seg[idx][b] = min(seg[idx*2][b], seg[idx*2+1][b]);
}

void query(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr) {FOR(i, 0, 60) mn[i] = min(mn[i], seg[idx][i]); return;}
	int m = (l+r)/2;
	query(l, m, idx*2, ql, qr); query(m+1, r, idx*2+1, ql, qr);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  for (int i = 0; i <= 60; i++) REP(j, 550000) seg[j][i] = inf;
  
  REP(i, n) {
  	cin >> x; b = 63-__builtin_clzll(x);
	upd(1, n, 1, i);
 	
  	FOR(j, 0, 60) {
  		pref[i][j] = pref[i-1][j];
		if (b <= j) pref[i][j] += x;	
	}
  }
  
  ll l, r;
  REP(i, q) {
  	cin >> l >> r;
  	
  	FOR(j, 0, 60) mn[j] = inf; b = 0; ans = 1;
  	query(1, n, 1, l, r);
  	
  	while (true) {
  		while (ans >= (1ll<<(b+1ll))-1ll) {b++; ans = pref[r][b-1]-pref[l-1][b-1]+1;}
  		if (mn[b] <= ans) ans += x;	
  		else break;
	}

  	cout << ans << "\n";
  }

  return 0;
}
