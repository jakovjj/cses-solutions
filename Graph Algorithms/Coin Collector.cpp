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

ll n, m, a, b, v[200003], llv[200003], id[200003], t, vscc[200003], dp[200003], r;
vector<ll> adj[200003];
set<ll> compadj[200003];
map<ll, ll> idsets;
stack<ll> st;

bool instack[200003], visited[200003];

void scc(ll node) {
	if (visited[node] == 1) return;
	
	visited[node] = 1;
	
	id[node] = t++;
	llv[id[node]] = id[node];
	instack[node] = 1;
	st.push(node);	
	
	for (auto i : adj[node]) {
		scc(i);	
		if (instack[i]) llv[id[node]] = min(llv[id[node]], llv[id[i]]);
	}
	
	if (llv[id[node]] == id[node]) {
		while (st.top() != node) {
			llv[id[st.top()]] = llv[id[node]];
			instack[st.top()] = 0;
			st.pop();
		}
		llv[id[st.top()]] = llv[id[node]];
			instack[st.top()] = 0;
			st.pop();
	}
	
}

ll dfs(ll node) {
	if(visited[node]) return dp[node];
	visited[node] = 1;
	dp[node] = vscc[node];
	
	for (auto i : compadj[node]) dp[node] = max(dp[node], dfs(i)+vscc[node]);	
	
	//cout << "max dp value for " << node << " is " << dp[node] << "\n";
	
	r = max(r, dp[node]);
	return dp[node];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  for (int i = 1; i <= n; i++) cin >> v[i];
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  }
  
  t = 1;
  for (int i = 1; i <= n; i++) scc(i);
  
  //for (int i = 1; i<=n; i++) cout << llv[id[i]] << " ";
  //cout << "\n";
  
  t = 1;
  for (int i = 1; i<=n; i++) {
  	if (idsets[llv[id[i]]] == 0) idsets[llv[id[i]]] = t++;
	
	vscc[idsets[llv[id[i]]]] += v[i];
	llv[id[i]] = idsets[llv[id[i]]];
  }
  
  //for (int i = 1; i<=n; i++) cout << llv[id[i]] << " ";
  //cout << "\n"; for (int i = 1; i<t; i++) cout << "SCC " << i << " v: " << vscc[i] << "\n";
  
  for (int i = 1; i<=n; i++) {
  	for (auto k : adj[i]) {
			if(llv[id[i]] != llv[id[k]]) {
  			compadj[llv[id[i]]].insert(llv[id[k]]);
			//cout << "connected SCCs" << llv[id[i]] << " and " << llv[id[k]] << "\n";	
			}
		}
	}

  //directed acyclic graph dp
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i < t; i++) dfs(i);
  
  //for (int i = 1; i < t; i++) cout << dp[i] << " ";

  cout << r;

  return 0;
}


