#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int inf = 2147483647; const int mod = 1e9+7;

ll n, a, b, sub[100003], centroid, ocentroid, x, y, cnt;
vector<ll> adj[100003];

map<vector<ll>, ll> m;

int find_centroid(int node, int parent) {
	int maxsub = 0; int maxnode = 0;
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		if (sub[i] > maxsub) {
			maxsub = sub[i];
			maxnode = i;
		}
	}
	
	if (maxsub <= n/2) {
		if (maxsub == n/2 && !(n%2)) ocentroid = maxnode;
		return node;
	}
	return find_centroid(maxnode, node);
}

int subdfs(int node, int parent) {
	sub[node] = 1;
	for (auto i : adj[node]) {
		if (i == parent) continue;
		sub[node] += subdfs(i, node);
	}
	
	return sub[node];
}

int isohash(int node, int parent) {
	vector<ll> c;
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		c.push_back(isohash(i, node));
	}
	
	sort(c.begin(), c.end());
	if (m[c] == 0) m[c] = ++cnt;
	
	return m[c];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  testcases {
  	cin >> n;
  	
  	for (int i = 1; i < n; i++) {
  		cin >> a >> b;
  		adj[a].push_back(b); adj[b].push_back(a);
	}
	subdfs(1, 0);
	centroid = find_centroid(1, 0);
	x = isohash(centroid, 0);
	
	for (int i = 1; i <= n; i++) adj[i].clear();
	
	bool w = 0;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	
	ocentroid = 0; centroid = 0;
	subdfs(1, 0);
	centroid = find_centroid(1, 0);
	
	y = isohash(centroid, 0);
	if (x == y) w = 1;
	
	if (ocentroid != 0) {
		y = isohash(ocentroid, 0);
		if (x == y) w = 1;
	}
	
	for (int i = 1; i <= n; i++) adj[i].clear();
  	w ? cout << "YES\n" : cout << "NO\n";
  }
  return 0;
}

