#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

int n, m, a, b, res, f[503][503], x, p[503], minf;
bool w;
vector<int> adj[503], oadj[503], ans;

bool bfs() {
	queue<int> q;
	q.push(1);
	
	while(!q.empty()) {
		for (auto i : adj[q.front()]) {
			if (p[i] != 0 || f[q.front()][i] <= 0) continue;
			p[i] = q.front();
			q.push(i);
		}	
		q.pop();
	}
	
	return p[n];
}

void dfs(int node) {
	if (w) return;
	
	ans.push_back(node);
	if (node == n) {
		cout << ans.size() << "\n";
		for (auto i : ans) cout << i << " ";
		cout << "\n";
		w = 1;
		return;
	}
	
	for (auto i : oadj[node]) {
		if (f[node][i] == 0) {f[node][i]--; dfs(i); break;}
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
  	cin >> a >> b;
  	f[a][b] = 1;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  	oadj[a].push_back(b);
  }	

  while (bfs()) {
  	x = n;
  	minf = INT_MAX;
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
  	
  	res += minf;
  	memset(p, 0, sizeof(p));
  }
	
  cout << res << "\n";
  for (int i = 1; i <= res; i++) {ans.clear(); w = 0; dfs(1);}
  
  return 0;
}


