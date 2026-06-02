#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, flow[103][103], maxflow[103][103], pt[103];
char mat[53][53];
bool vis[103];
vector<int> adj[103];

bool bfs() {
	bool reached = 0; vis[0] = 1;
	queue<int> q; q.push(0);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == 101) {reached = 1; continue;}
		for (auto i : adj[x]) if (!vis[i] && flow[x][i] < maxflow[x][i]) {vis[i] = 1; pt[i] = x; q.push(i);} 		
	}
	return reached;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  REP(i, n) {
  	cin >> maxflow[0][i];
  	adj[0].push_back(i);
  	adj[i].push_back(0);
  }
  REP(i, n) {
  	cin >> maxflow[n+i][101];
  	adj[n+i].push_back(101);
  	adj[i].push_back(101);
  }
  memset(mat, '.', sizeof(mat));
  
  REP(i, n) REP(j, n) {
  	adj[i].push_back(n+j);
  	adj[n+j].push_back(i);
  	maxflow[i][n+j] = 1;
  }
  
  while (bfs()) {
  	int x = 101;
  	while (x) {
  		flow[pt[x]][x]++;
  		flow[x][pt[x]]--;
		x = pt[x];	
	}
  	memset(vis, 0, sizeof(vis));
  }
  
  bool w = 1;
  REP(i, n) if (flow[0][i] != maxflow[0][i]) w = 0;
  REP(i, n) if (flow[n+i][101] != maxflow[n+i][101]) w = 0;
  REP(i, n) REP(j, n) if (flow[i][n+j]) mat[i][j] = 'X';
  if (!w) {cout << "-1"; return 0;}
  
  REP(i, n) {
  	REP(j, n) cout << mat[i][j];
  	cout << "\n";
  }

  return 0;
}


