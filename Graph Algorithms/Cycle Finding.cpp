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

ll n, m, a, b, c, dist[2503], parent[2503], path[2503];
stack<ll> res;
vector<pll> adj[2503];

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  memset(dist, 0x7f, sizeof(dist));
  for (int i = 0; i < m; i++) {cin >> a >> b >> c; adj[a].push_back(mpair(b, c));}
  dist[1] = 0;
  
  for (int k = 0; k < n+1; k++) {
  	for (int i = 1; i <= n; i++) {
  		for (auto j : adj[i]) {
  			if (dist[i]+j.second < dist[j.first]) {
			parent[j.first] = i;
	  		dist[j.first] = min(dist[j.first], dist[i]+j.second);
	  		}
		}
	  }
	  
	//for (int i = 1; i <= n; i++) {cout << dist[i] << " ";} cout << endl;
	//for (int i = 1; i <= n; i++) {cout << parent[i] << " ";} cout << endl;
  }
  
  for (int i = 1; i <= n; i++) {
  		for (auto j : adj[i]) {
  			
			if (dist[i]+j.second < dist[j.first]) {
				//cout << i << " and " << j.first << " are a part of a negative cycle!" << endl;
	  			parent[j.first] = i;
	  			
				res.push(j.first);
				a = j.first;  		
	  			while(path[a] == 0) {
	  				path[a] = 1;
	  				res.push(a);
					a = parent[a];}
				res.push(a);
			  	
			  	break;}
		}
		if (!res.empty()) break;
   }
   
  if (res.empty()) cout << "NO";
  else {
  	cout << "YES\n";
  	while (path[res.top()] == 1) {
  		cout << res.top() << " ";
  		path[res.top()] = 0;
  		res.pop();
	  }
	cout << res.top();
  }

  return 0;
}


