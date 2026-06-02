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
 
template<class T> using pqmax = priority_queue< T, vector<T>, greater<T> >;
template<class T> using pqmin = priority_queue<T>;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!
 
int n, m, a, b, llv[100003], id[100003], k[100003], r, c;
vector<int> adj[100003];
bool onstack[100003], visited[100003];
stack<int> s;
 
void dfs(int node) {
	if (visited[node] == 1) return;
	
	visited[node] = 1;
	c++; id[node] = c;
	llv[id[node]] = id[node];
	onstack[id[node]] = 1;
	s.push(node);
	
	//cout << "searching through node " << node << " (id " << id[node] << ")\n";
	
	for (auto i : adj[node]) {
		dfs(i);
		if (onstack[id[i]] == 1) {
			llv[id[node]] = min(llv[id[node]], llv[id[i]]);
		}
	}
	
	if (llv[id[node]] == id[node]) {
		
		r++;
		while (s.top() != node) {
			onstack[id[s.top()]] = 0;
			k[s.top()] = r;
			s.pop();
		}
		k[s.top()] = r;
		onstack[id[s.top()]] = 0;
		s.pop();
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
  
  cout << r << "\n";
  for (int i = 1; i<= n; i++) cout << k[i] << " ";
 
  return 0;
}
