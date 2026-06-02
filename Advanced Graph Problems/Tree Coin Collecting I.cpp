#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, q, dp[200003][20], up[200003][20], dist[200003], dep[200003], u, v, c, res, a, b, l;
vector<int> adj[200003];
queue<pair<int, int>> bfs;

void dfs(int x, int p, int d) {
	up[x][0] = p; dp[x][0] = min(dist[x], dist[p]); dep[x] = d;
	for (auto i : adj[x]) if (i != p) dfs(i, x, d+1);
}

int lca(int x, int y) {
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--) {
		if (dep[up[y][i]] >= dep[x]) {res = min(res, dp[y][i]); y = up[y][i];}
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; i--) {
		if (up[x][i] != up[y][i]) {
			res = min({res, dp[x][i], dp[y][i]});
			x = up[x][i];
			y = up[y][i];
		}
	}
	
	res = min({res, dp[x][0], dp[y][0]});
	return up[x][0];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  REP(i, n) {cin >> c; if (c) bfs.push({i, 1});}
  REP(i, n-1) {
  	cin >> u >> v;
  	adj[u].push_back(v);
  	adj[v].push_back(u);
  }
  
  while (!bfs.empty()) {
  	pair<int, int> x = bfs.front(); bfs.pop();
  	if (dist[x.first]) continue;
  	dist[x.first] = x.second;
  	for (auto i : adj[x.first]) bfs.push({i, x.second+1});
  }
  REP(i, n) dist[i]--;
  
  dfs(1, 0, 1);
  REP(i, 19) REP(j, n) {
  	dp[j][i] = min(dp[j][i-1], dp[up[j][i-1]][i-1]);
  	up[j][i] = up[up[j][i-1]][i-1];
  }
  
  REP(i, q) {
  	cin >> a >> b;
  	res = min(dist[a], dist[b]); l = lca(a, b);  	
  	cout << res*2-2*dep[l]+dep[a]+dep[b] << "\n";
  }

  return 0;
}


