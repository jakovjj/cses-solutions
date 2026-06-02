#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpr make_pair
#define mtp make_tuple
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); *o_set.find_by_order(i);
const int mod = 1e9+7; const int inf = 2147483647;

int n, m, a, b;
bool visited[50003];
vector<int> adj[50003];
bitset<50003> reach[50003];

void dfs(int node) {
	if (visited[node]) return;
	visited[node] = 1;
	
	reach[node].set(node);
	
	for (auto i : adj[node]) {
		dfs(i);
		reach[node] |= reach[i];
	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  }
  
  for (int i = 1; i <= n; i++) dfs(i);
  
  for (int i = 1; i <= n; i++) {
  	cout << reach[i].count() << " ";
  }

  return 0;
}


