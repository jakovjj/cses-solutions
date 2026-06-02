#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
const ll inf = 1e18;

ll n, m, a, b, c, res, x, minf;
vector<ll> adj[503];
ll f[1003][1003], cap[1003][1003], p[1003];

bool bfs() {
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) {
		for (auto i : adj[q.front()]) {
			if (cap[q.front()][i]-f[q.front()][i] <= 0 || p[i] != 0) continue;
			p[i] = q.front();
			q.push(i);
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
  	cin >> a >> b >> c;
  	cap[a][b] += c;
  	
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  while(bfs()) {    	
  	minf = LLONG_MAX;
  	x = n;
  	while (x != 1) {
  		minf = min(minf, cap[p[x]][x]-f[p[x]][x]);
  		x = p[x];
	}
	x = n;
	while (x != 1) {
		f[p[x]][x] += minf;
		f[x][p[x]] -= minf;
		x = p[x];
	}
	
  	res += minf;
  	memset(p, 0, sizeof(p));
  }
  
  cout << res;
  return 0;
}


