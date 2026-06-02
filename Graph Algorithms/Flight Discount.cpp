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

ll n, m, a, b, c, r;
pqmax<pll> q;
bool visited[200003], t;
vector<pll> adj[200003], adj_inv[200003];

ll dist_st[200003], dist_en[200003];

void dijkstra (ll dist, ll node) {
	if(visited[node] == 1) return;
	visited[node] = 1;
	
	if(t==0) dist_st[node] = dist;
	else dist_en[node] = dist;
	
	if(t==0) for (auto i : adj[node]) q.push(mpair(i.second+dist, i.first));
	else for (auto i : adj_inv[node]) q.push(mpair(i.second+dist, i.first));
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 0; i < m; i++) {
  	cin	>> a >> b >> c;
  	adj[a].push_back(mpair(b, c));
  	adj_inv[b].push_back(mpair(a, c));
  }
  
  memset(dist_st, -1, sizeof(dist_st));
  memset(dist_en, -1, sizeof(dist_en));
  
  t = 0;
  q.push(mpair(0, 1));
  while (!q.empty()) {
  	dijkstra(q.top().first, q.top().second);
  	q.pop();
  }
  
  
  t = 1;
  for (int i = 1; i <= n; i++) visited[i] = 0;
  
  q.push(mpair(0, n));
  while (!q.empty()) {
  	dijkstra(q.top().first, q.top().second);
  	q.pop();
  }
  
  //for (int i = 1; i <= n; i++) cout << dist_st[i] << " ";
  //cout << "\n"; for (int i = 1; i <= n; i++) cout << dist_en[i] << " ";
  
  r = 1e15;
  for (int i = 1; i <= n; i++) {
  	for (auto k : adj[i]) {
  		if(dist_st[i] == -1 || dist_en[k.first] == -1) continue;
  		r = min(r, dist_st[i]+k.second/2+dist_en[k.first]);
	}
  }

  cout << r;
  
  return 0;
}


