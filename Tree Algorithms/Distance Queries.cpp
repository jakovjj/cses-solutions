#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//reference -> o_set.insert(x), *(o_set.find_by_order(i)), o_set.order_of_key(i), ordered_set<int> o_set

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mpair make_pair
#define elif else if
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7;
const int inf = 2147483647;

int n, q, a, b, up[200003][20], dep[200003], depdif, r;
vector<int> adj[200003];

void dfs(int node, int parent, int depth) {
	up[node][0] = parent;
	dep[node] = depth;
	
	for (auto i: adj[node]) {
		if (i == parent) continue;
		dfs(i, node, depth+1);
	}
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 0; i < n-1; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  dfs(1, 0, 0);
  
  for (int i = 1; (1<<i) <= n; i++) {
  	for (int j = 2; j <= n; j++) {
  		up[j][i] = up[up[j][i-1]][i-1];
	  }
  }
  
  for (int i = 0; i < q; i++) {
  	cin >> a >> b;
  	
  	//cout << "for query " << a << " " << b << "\n";
	  	
  	if (dep[b] > dep[a]) {swap(a, b);}
  	depdif = dep[a]-dep[b];
  	r = dep[a]+dep[b];
  	
  	for (int i = 0; (1<<i) <= n; i++) {
  		if ((depdif&(1<<i)) != 0) {
  			a = up[a][i];
		  }
	}
	
	if (a == b) {cout << r-2*dep[a] << "\n"; continue;}
	
	for (int j = 17; j >= 0; j--) {
		if(up[a][j] != up[b][j]) {
			a = up[a][j];
			b = up[b][j];
		}
	}
	
	//cout << a << " " << b << "\n";
	
	cout << r-2*dep[up[a][0]] << "\n";
  }

  return 0;
}

//JJ

