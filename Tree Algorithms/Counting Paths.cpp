#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define mpair make_pair
#define elif else if
#define MEMSET_MAX 0x7f
//(0x3f is larger than 1e9)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
//getline(cin >> ws, s)

//s.upper_bound(2); -> set upper_bound
//upper_bound(v.begin(), v.end(), 35); -> std upper_bound
template<class T> using pqmax = priority_queue< T, vector<T>, greater<T> >;
template<class T> using pqmin = priority_queue<T>;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!

int n, m, a, b, up[200003][18], v[200003], d[200003];
vector<int> adj[200003], dep_n[200003];

void dfs(int node, int parent, int depth) {
	up[node][0] = parent;
	dep_n[depth].push_back(node);
	d[node] = depth;
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		dfs(i, node, depth+1); 
	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n-1; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  dfs(1, 0, 1);
  
  for (int j = 1; j <= 17; j++) {
  	for (int i = 1; i <= n; i++) {
  		up[i][j] = up[up[i][j-1]][j-1];}
  }
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	int o_b = b;
  	int o_a = a;
  	
  	//cout << "same depth value of " << a << " and " << b << " is\n";
  	if (d[a] > d[b]) {
  		swap(a, b);
  		swap(o_a, o_b);
	  }
  	int depdif = d[b]-d[a];
  	//bring up b to depth of a
  	
  	for (int k = 17; k >= 0; k--) {
  		if ((1LL<<k) <= depdif) {
		  	b=up[b][k];
		  	depdif-=(1LL<<k);
		  }
	}
		
	//cout << a << " and " << b << "\n";
	if (a == b) {
		//cout << "for " << o_b << "," << o_a << " -> " << o_b << "is getting increased by 1, " << up[o_a][0] << "is getting decreased by 1\n";
		v[o_b]++;
		v[up[o_a][0]]--;
	}
	else {
		//find lca
		
		for (int k = 17; k >= 0; k--) {
			if (up[a][k] != up[b][k]) {
				a = up[a][k];
				b = up[b][k];
			}
		}
		
		int lca = up[a][0];
		//cout << "their lca is " << lca << "\n";
		v[up[lca][0]]--;
		v[lca]--;
		v[o_b]++;
		v[o_a]++;
	}
  }
  
  //for (int i = 1; i<=n; i++) {cout << v[i] << " ";} cout << "\n";

  for (int i = n; i>=1; i--) {
  	for (auto j : dep_n[i]) {
  		v[up[j][0]] += v[j];
  		//cout << "processed " << j << " with " << v[j] << "\n";
	  }
  }
  
  for (int i = 1; i<=n; i++) {cout << v[i] << " ";}
  return 0;
}


