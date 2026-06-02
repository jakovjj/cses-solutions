#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;
const int x = 100001;

int n, m, a, b, llv[200003], id[200003], cnt, top[200003], res[100003], sccpart[100003];
char c;
set<int> adj[200003], scc[200003], sccadj[200003], sccadjtemp[200003];
stack<int> s;

bool w, visited[200003], onstack[200003];

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = 1; onstack[node] = 1; s.push(node);
	id[node] = ++cnt; llv[node] = cnt;
	
	for (auto i : adj[node]) {dfs(i); if (onstack[i]) llv[node] = min(llv[node], llv[i]);}
	
	if (llv[node] == id[node]) {
		while (true) {
			onstack[s.top()] = 0; scc[id[node]].insert(s.top());;
			if (scc[id[node]].count(s.top()+x) || scc[id[node]].count(s.top()-x)) w = 0;
			for (auto i : adj[s.top()]) sccadjtemp[id[node]].insert(i);
			sccpart[s.top()] = id[node];
			if (s.top() == node) {s.pop(); break;} 
 			s.pop();
		}
	}
	return;
}

void topsort(int node) {
	if (visited[node]) return;
	visited[node] = 1;
	
	for (auto i : sccadj[node]) topsort(i);
	for (auto i : scc[node]) {
		if (i > x && res[i-x] == -1) res[i-x] = 1;
  		if (i < x && res[i] == -1) res[i] = 0; 
	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  w = 1;
  for (int i = 1; i <= n; i++) {
  	cin >> c >> a; if (c == '+') a+=x;
  	cin >> c >> b; if (c == '+') b+=x;
  	(a > x) ? adj[a-x].insert(b) : adj[a+x].insert(b);
  	(b > x) ? adj[b-x].insert(a) : adj[b+x].insert(a);
  }
  
  for (int i = 1; i <= m; i++) {dfs(i+x); dfs(i);}
  if (!w) {cout << "IMPOSSIBLE"; return 0;}  
  for (int i = 1; i <= m*2; i++) for (auto k : sccadjtemp[i]) sccadj[i].insert(sccpart[k]);
  
  memset(visited, 0, sizeof(visited)); memset(res, -1, sizeof(res));
  for (int i = 1; i <= m*2; i++) {topsort(i);}
  
  for (int i = 1; i <= m; i++) (res[i] == 1) ? cout << "+ " : cout << "- ";
  return 0;
}


