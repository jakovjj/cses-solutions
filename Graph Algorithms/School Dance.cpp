#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

int n, m, k, a, b, f[1008][1008], x, p[1008], minf;
vector<pii> res;
set<int> adj[1008];

bool bfs() {
	queue<int> q; q.push(1);
	
	while (!q.empty()) {
		for (auto i : adj[q.front()]) {
			if (p[i] != 0 || f[q.front()][i] <= 0) continue;
			p[i] = q.front();
			q.push(i);
		}
		q.pop();
	}
	
	return p[n+m+2];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
  	cin >> a >> b;
  	a+=1; b+=1+n;
  	
  	f[a][b]=1;
  	adj[a].insert(b);
  	adj[b].insert(a);
  } 
  
  //1 -> source | n+m+2 -> sink
  for (int i = 1; i <= n; i++) {adj[1].insert(i+1); f[1][i+1]=1;}
  for (int i = 1; i <= m; i++) {adj[i+1+n].insert(n+m+2); f[i+1+n][n+m+2]=1;}
  
  while (bfs()) {
	x = n+m+2;
	minf = INT_MAX;
	while (x != 1) {
		f[p[x]][x]--;
		f[x][p[x]]++;
		x = p[x];
	}
	
	memset(p, 0, sizeof(p));
  }
  
  for (int i = 1; i <= n; i++) {
  	for (auto j : adj[i+1]) if (f[i+1][j] == 0) res.push_back({i, j-n-1});
  }
  
  cout << res.size() << "\n";
  for (auto i : res) cout << i.first << " " << i.second << "\n";

  return 0;
}


