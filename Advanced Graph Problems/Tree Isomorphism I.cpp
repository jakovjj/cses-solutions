#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

int n, a, b;
vector<int> adj[100003];
map<vector<int>, int> m;
int x, y, cnt;

int encode(int node, int parent) {
	vector<int> c;
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		c.push_back(encode(i, node));
	}
	
	sort(c.begin(), c.end());
	
	int h;
	if (!m[c]) m[c] = ++cnt;
	h = m[c];
	
	return h;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  testcases {
  	cin >> n;
  	
  	for (int i = 1; i <= n; i++) adj[i].clear();
  	for (int i = 1; i < n; i++) {cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
  	x = encode(1, 0);
  	for (int i = 1; i <= n; i++) adj[i].clear();
	for (int i = 1; i < n; i++) {cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);}
	y = encode(1, 0);
	
	(x == y) ? cout << "YES\n" : cout << "NO\n";
  }

  return 0;
}
