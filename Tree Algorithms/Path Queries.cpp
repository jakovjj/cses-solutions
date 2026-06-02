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

ll n, q, a, b, t, st[200003], en[200003], v[200003], segtree[800003], res;
vector<ll> adj[200003];

void update(ll ql, ll qr, ll l, ll r, ll index) {
	
	if (l >= ql && r <= qr) {
		segtree[index] += b;
		//cout << "updated node " << index << " " << l << " " << r << " to " << b << "\n";
		return;
	}
	if (r < ql || l > qr) return;
	
	ll mid = (l+r)/2;
	update(ql, qr, mid+1, r, index*2+1);
	update(ql, qr, l, mid, index*2);

	return;
}

void query(ll qm, ll l, ll r, ll index) {
	
	if (qm == l && l == r) {
		res += segtree[index];
		return;
	}
	res += segtree[index];
	
	ll mid = (l+r)/2;
	if (qm > mid) query(qm, mid+1, r, index*2+1);
	else query(qm, l, mid, index*2);
	
	return;
}

void dfs(ll node, ll parent, ll sum) {
	t++;
	st[node] = t;
	sum+=v[node];
	
	b = sum;
	update(st[node], st[node], 1, n, 1);
	
	for (auto i : adj[node]) {
		if (i == parent) continue;
		dfs(i, node, sum);
	}
	
	en[node] = t;
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i<=n; i++) {
  	cin >> v[i];
  }
  
  for (int i = 0; i < n-1; i++) {
  	cin >> a >> b;
  	adj[a].push_back(b);
  	adj[b].push_back(a);
  }
  
  t = 0;
  dfs(1, 0, 0);
  
  //for (int i = 1; i <= n; i++) {cout << st[i] << " ";} cout << "\n";
  //for (int i = 1; i <= n; i++) {cout << en[i] << " ";} cout << "\n";
  
  for (int i = 0; i < q; i++) {
  	cin >> a;
  	
  	if (a == 1) { //update
  		cin >> a >> b;
  		b -= v[a];
  		v[a] = b+v[a];
  		
  		//cout << "Updating range" << st[a] << " to " << en[a] << " with " << b << "\n";
  		update(st[a], en[a], 1, n, 1);
	  }
	else { //query
		cin >> a;
		res = 0;
		query(st[a], 1, n, 1);
		
		cout << res << "\n";
	}
  }

  return 0;
}


