#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

ll n, q, a, b, up[19][200003], tree[200003], cnt, cyccnt, depth[200003];
ll segment[200003], cyclenum[200003], cyclesize[200003];

bool onstack[200003], visited[200003];
vector<ll> s;

void dfs(int node) {	
	if (visited[node]) return;
	visited[node] = 1; onstack[node] = 1;
	s.push_back(node);
	
	if (onstack[up[0][node]]) {
		cnt++; cyccnt = 0;
		while (true) {			
			segment[s.back()] = cnt;
			cyclenum[s.back()] = ++cyccnt;
			tree[s.back()] = s.back();
			onstack[s.back()] = 0;
				
			if (s.back() == up[0][node]) {s.pop_back(); break;}
			s.pop_back();
		}
		cyclesize[cnt] = cyccnt;
		
		return;
	}
	dfs(up[0][node]);
	
	s.pop_back(); onstack[node] = 0;
	return;
}

void treedfs(int node) {
	if (tree[node]) return;
	treedfs(up[0][node]);
	tree[node] = tree[up[0][node]];
	depth[node] = depth[up[0][node]]+1;
	segment[node] = segment[up[0][node]];
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> up[0][i];  
  for (int i = 1; i <= n; i++) {s.clear(); dfs(i);}
  for (int i = 1; i <= n; i++) treedfs(i);
  
  depth[0] = -1;
  for (int i = 1; i <= n; i++) {if (tree[i] == i) up[0][i] = 0;}
  for (int i = 1; i <= 18; i++) for (int j = 1; j <= n; j++) up[i][j] = up[i-1][up[i-1][j]];
  
  for (int i = 1; i <= q; i++) {
  	cin >> a >> b;
  	
  	if (segment[a] != segment[b]) {cout << "-1\n"; continue;}
  	if (tree[a] != tree[b] && tree[b] != b) {cout << "-1\n"; continue;}
  	
  	if (tree[a] != tree[b]) {
  		if (cyclenum[tree[a]] > cyclenum[tree[b]]) cout << depth[a]+cyclesize[segment[a]]-(cyclesize[segment[a]]-cyclenum[tree[a]]+cyclenum[tree[b]]) << "\n";
		else cout << depth[a]+cyclesize[segment[a]]-(cyclenum[tree[b]]-cyclenum[tree[a]]) << "\n";
	}
	else {
		cnt = 0;
		for (int i = 18; i >= 0; i--) if (depth[up[i][a]] >= depth[b]) {cnt += (1<<i); a = up[i][a];}
		if (a != b) {cout << "-1\n"; continue;}
		cout << cnt << "\n";
	}
  }

  return 0;
}


