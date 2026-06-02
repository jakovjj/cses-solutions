#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a, b, f[503][503], p[503], x, minf;
bool visited[503];
vector<ll> adj[503];
vector<pair<ll, ll>> res;

bool bfs() {
	memset(p, 0, sizeof(p));
	queue<ll> q;
	q.push(1);
	
	while (!q.empty()) {
		for (auto i : adj[q.front()]) {
			if (f[q.front()][i] <= 0 || p[i] != 0) continue;
			p[i] = q.front();
			q.push({i});
		}	
		q.pop();
	}
	
	return p[n];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	f[a][b]++;
  	f[b][a]++;
	adj[a].push_back(b);
	adj[b].push_back(a);
  }
  
  while (bfs()) {
  	minf = LLONG_MAX;
  	x = n;
  	while (x != 1) {
  		minf = min(minf, f[p[x]][x]);
  		x = p[x];
	}
	x = n;
	
	while (x != 1) {
		f[p[x]][x]-=minf;
  		f[x][p[x]]+=minf;
  		x = p[x];
	}
  }
  
  queue<ll> q; q.push(1);
  while (!q.empty()) {
  	if (visited[q.front()]) {q.pop(); continue;}
  	visited[q.front()] = 1;
  	
  	for (auto i : adj[q.front()]) {
  		if (p[i] == 0) res.push_back({q.front(), i});
  		else q.push(i);
	}
	q.pop();
  }
  
  cout << res.size() << "\n";
  for (auto i : res) cout << i.first << " " << i.second << "\n";

  return 0;
}


