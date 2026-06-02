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

ll n, m, a, b, c, paths[200003], dist[200003], maxf[200003], minf[200003], visited[200003];

vector<pll> adj[200003];
pqmax< tuple<ll, ll, ll> > q; //distance, flights, node

void dijkstra(ll d, ll flights, ll node) {
	
	if (visited[node] == 1 || node == n) return;
	visited[node] = 1;
	
	for (auto i : adj[node]) {
		
		if (d+i.second <= dist[i.first]) {
			
			//cout << node << "->" << i.first << "  " << maxf[node]+1 << "\n";
			
			if (d+i.second < dist[i.first]) {
				paths[i.first] = paths[node]; dist[i.first] = d+i.second; maxf[i.first] = maxf[node]+1; minf[i.first] = minf[node]+1;
			}
			else {
				paths[i.first] += paths[node];
				if (paths[i.first] >= mod) paths[i.first] -= mod;
				
				dist[i.first] = d+i.second;
				maxf[i.first] = max(maxf[i.first], maxf[node]+1);
				minf[i.first] = min(minf[i.first], minf[node]+1);	
			}
		}
		
		q.push(make_tuple(i.second+d, flights+1, i.first));
	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> m;
  
  memset(dist, 0x7f, sizeof(dist));
  memset(minf, 0x7f, sizeof(minf));
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b >> c;
  	adj[a].push_back(mpair(b, c));
  }
  
  q.push(make_tuple(0, 0, 1));
  paths[1] = 1;
  dist[1] = 0;
  minf[1] = 0;
  maxf[1] = 0;

  while (!q.empty()) {
  	dijkstra( get<0>(q.top()), get<1>(q.top()), get<2>(q.top()) );
  	q.pop();
  }
  
  cout << dist[n] << " " << paths[n] << " " << minf[n] << " " << maxf[n];

  return 0;
}


