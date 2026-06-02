#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q, bg[200003], en[200003], segtree[800003], v[200003], a, b, t, x;
vector<ll> adj[200003];

void dfs(ll node, ll parent) {
	bg[node] = ++t;
	for (auto i : adj[node]) {
		if (i == parent) continue;
		dfs(i, node);
	}
	en[node] = t;
	
	return;
}

void update(ll l, ll r, ll idx, ll pos, ll vl) {
	if (l == pos && r == pos) {segtree[idx] = vl; return;}
	if (l > pos || r < pos) return;
	
	ll mid = (l+r)/2;
	update(l, mid, idx*2, pos, vl);
	update(mid+1, r, idx*2+1, pos, vl);
	
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
	
	return;
}

ll query(ll l, ll r, ll idx, ll ql, ll qr) {
	if (l >= ql && r <= qr) {return segtree[idx];}
	if (l > qr || r < ql) {return 0;}
	
	ll mid = (l+r)/2;
	return query(l, mid, idx*2, ql, qr)+query(mid+1, r, idx*2+1, ql, qr);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> v[i];
  
  t = 0;
  for (int i = 1; i < n; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  dfs(1, 0);
  for (int i = 1; i <= n; i++) update(1, n, 1, bg[i], v[i]);
  
  for (int i = 1; i <= q; i++) {
  	cin >> a >> b;
  	if (a == 1) {
  		cin >> x;
  		v[b] = x;
		update(1, n, 1, bg[b], v[b]); 
	}
	else if (a == 2) {
		cout << query(1, n, 1, bg[b], en[b]) << "\n";
	}
  }

  return 0;
}

