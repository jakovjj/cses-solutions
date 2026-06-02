#include <bits/stdc++.h>
using namespace std;
 
int n, a, b, c, q, res, t, lca, pos, oa, ob, segtree[800003], subtree[200003], dep[200003], id[200003], hp[200003], clr[200003], up[200003];
vector<int> adj[200003];
 
int dfs(int node, int parent) {
	up[node] = parent;
	subtree[node] = 1;
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		dep[i] = dep[node]+1;
		subtree[node] += dfs(i, node);
	}
	
	return subtree[node];
}
 
//hld -> euler tour
void hld(int node, int top) {	
	id[node] = c++;
	hp[node] = top;
	
	int heavychild = -1; int maxsts = -1;
	for (auto i : adj[node]) {
		if (i == up[node]) continue;
		if (subtree[i] > maxsts) {maxsts = subtree[i]; heavychild = i;}
	}
	
	if (heavychild != -1) hld(heavychild, top);
	
	for (auto i : adj[node]) {
		if (i == up[node] || i == heavychild) continue;
		hld(i, i);
	}
	
	return;
}
 
void update(int p, int updclr) {
	
	p+=n;
	segtree[p] = updclr;
	p/=2;	
	while (p > 0) {
		segtree[p] = max(segtree[p*2], segtree[p*2+1]);
		p/=2;
	}
	
	return;
}
 
void query(int l, int r) {
	l+=n; r+=n; r++;
	while (l < r) {
		if (l&1) res = max(res, segtree[l++]);
		if (r&1) res = max(res, segtree[--r]);
		l/=2; r/=2;
	}
	
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> clr[i];
  for (int i = 1; i <= n-1; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
	adj[b].push_back(a);
  }
 
  dep[1] = 1;
  dfs(1, 0);
  hld(1, 1);
  
  for (int i = 1; i <= n; i++) update(id[i], clr[i]);
  
  for (int i = 1; i <= q; i++) {
  	cin >> t >> a >> b;
  	if (t == 1) update(id[a], b);
  	else if (t == 2) {
		res = 0;
		
		while(hp[a] != hp[b]) {
			if (dep[hp[a]] > dep[hp[b]]) swap(a, b);
			query(id[hp[b]], id[b]);
			b = up[hp[b]];
		}
		if (dep[a] > dep[b]) swap(a, b);
		query(id[a], id[b]);
		
		cout << res << " ";
	}
  }
 
  return 0;
}
