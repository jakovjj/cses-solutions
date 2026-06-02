#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const ll inf = 1e16; const int mod = 1e9+7;
 
ll n, a, b, p;
vector<ll> adj[100003], l;
vector<pll> res;
 
void dfs(int node, int parent) {
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		dfs(i, node);
	}
	
	if (adj[node].size() == 1) l.push_back(node);
	
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  for (int i = 1; i < n; i++) {cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
  dfs(1, 0);
  
  if (l.size()%2) l.push_back(l.back());
  
  p = 0;
  cout << l.size()/2 << "\n";
  while (p < l.size()/2) {
  	cout << l[p] << " " << l[p+l.size()/2] << "\n";
  	p++;
  }
  
 
  return 0;
}

