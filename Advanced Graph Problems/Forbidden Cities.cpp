#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
 
int n, m, q, dep[200003], llv[200003], up[200003][20], a, b, c, u, v, cnt, st[200003], en[200003];
bool vis[200003], artic[200003];
vector<int> adj[200003];
 
void dfs(int node, int par) {
	st[node] = ++cnt; vis[node] = 1;
	up[node][0] = par;
	dep[node] = dep[par]+1;
	
	llv[node] = st[node]; int cntch = 0;
	for (auto i : adj[node]) {
		if (i == par) continue;
		if (!vis[i]) {dfs(i, node); cntch++; llv[node] = min(llv[node], llv[i]);}
		else llv[node] = min({llv[node], st[i]});
		
		artic[node] |= (st[node] <= llv[i] && par);
	}	
	
	if (node == 1 && cntch > 1) artic[node] = 1;
	en[node] = cnt;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> m >> q;
  REP(i, m) {cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);}
  cnt = 0; dfs(1, 0);
  
  REP(j, 19) REP(i, n) up[i][j] = up[up[i][j-1]][j-1];
  REP(i, q) {
  	cin >> a >> b >> c;  	
  	if (a == c || b == c) {cout << "NO\n"; continue;}
  	
  	if (!artic[c]) {cout << "YES\n"; continue;}
	if (!(st[a] >= st[c] && st[a] <= en[c]) && !(st[b] >= st[c] && st[b] <= en[c])) {cout << "YES\n"; continue;} 
	
	int ta = a; int tb = b;
	for (int i = 19; i >= 0; i--) if (dep[up[ta][i]] >= dep[c]+1) ta = up[ta][i];
	for (int i = 19; i >= 0; i--) if (dep[up[tb][i]] >= dep[c]+1) tb = up[tb][i];
	
	if ((st[ta] >= st[c] && st[ta] <= en[c]) && !(st[tb] >= st[c] && st[tb] <= en[c]) && llv[ta] < st[c]) {cout << "YES\n"; continue;}
	if (!(st[ta] >= st[c] && st[ta] <= en[c]) && (st[tb] >= st[c] && st[tb] <= en[c]) && llv[tb] < st[c]) {cout << "YES\n"; continue;}
	
	if (ta == tb) {cout << "YES\n"; continue;}
	if ((st[ta] >= st[c] && st[ta] <= en[c]) && (st[tb] >= st[c] && st[tb] <= en[c]) && llv[ta] < st[c] && llv[tb] < st[c]) {cout << "YES\n"; continue;} 
	
	cout << "NO\n";
  }
 
  return 0;
}
