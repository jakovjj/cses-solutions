#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpair make_pair
#define mtuple make_tuple
#define elif else if
#define MEMSET_MAX 0x7f
//(0x3f is larger than 1e9)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7; const int inf = 2147483647;
// !!!

ll n, res, a, b, subtree[200003];
vector<ll> adj[200003];

ll subtree_solve(ll node, ll parent) {
	subtree[node] = 1;
	
	for (auto i : adj[node]) {
		if (parent == i) continue;
		subtree[node] += subtree_solve(i, node);
	}
	
	return subtree[node];
}

void centroid(ll node, ll parent) {
	
	bool iscentroid = 1;
	
	for (auto i : adj[node]) {
		if (parent == i) continue;
		if (subtree[i] > n/2) {
			iscentroid = 0;
			centroid(i, node);
		}
	}
	
	if (iscentroid == 1) res = node;
	
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 0; i < n-1; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  subtree_solve(1, 0);
  centroid(1, 0);
  
  cout << res;
  
  return 0;
}


