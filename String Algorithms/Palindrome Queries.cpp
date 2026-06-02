#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
const ll mod = 1e9+7; const ll inf = 1e18;

const ll p = 31;

ll n, m, a, b, k, e[200003], segtree[800003][2], t, tempa, tempb;
char s[200003], x;

void update(ll l, ll r, ll idx, bool bw, ll pos, ll v) {
	if (l > pos || r < pos) return;
	if (l == pos && r == pos) {segtree[idx][bw] = v; return;}
	
	ll mid = (l+r)/2;
	update(l, mid, idx*2, bw, pos, v);
	update(mid+1, r, idx*2+1, bw, pos, v);
	segtree[idx][bw] = (segtree[idx*2][bw]+segtree[idx*2+1][bw])%mod;
}

ll query(ll l, ll r, ll idx, bool bw, ll ql, ll qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return segtree[idx][bw];
	
	ll mid = (l+r)/2;
	return (query(l, mid, idx*2, bw, ql, qr)+query(mid+1, r, idx*2+1, bw, ql, qr))%mod;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  e[1] = 1; for (int i = 2; i <= n; i++) e[i] = (e[i-1]*p)%mod;
  
  for (int i = 1; i <= n; i++) {
  	cin >> s[i];
  	update(1, n, 1, 0, i, (s[i]*e[i])%mod);
  	update(1, n, 1, 1, i, (s[i]*e[n-i+1])%mod);
  }
  
  for (int i = 1; i <= m; i++) {
  	cin >> t;
  	if (t == 1) {
  		cin >> k >> x;
  		update(1, n, 1, 0, k, (x*e[k])%mod);
  		update(1, n, 1, 1, k, (x*e[n-k+1])%mod);
	}
	else {
		cin >> a >> b;
		tempa = a; tempb = n-b+1;
		
		if (tempa > tempb) (query(1, n, 1, 0, a, b) == (query(1, n, 1, 1, a, b)*e[tempa-tempb+1])%mod) ? cout << "YES\n" : cout << "NO\n";
		else ((query(1, n, 1, 0, a, b)*e[tempb-tempa+1])%mod == query(1, n, 1, 1, a, b)) ? cout << "YES\n" : cout << "NO\n";	
	}
  }
  

  return 0;
}


