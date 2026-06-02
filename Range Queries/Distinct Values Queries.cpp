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

int n, q, a, b, segtree[800003], res, ans[200003], arr[200003];
map<int, queue<int>> v;
set< pair<pii, int> > s;

void update(int l, int r, int idx, int qg, int v) {
	if (l > qg || r < qg) return;
	if (qg == l && qg == r) {
		segtree[idx] = v;
		return;
	}
	
	int mid = (l+r)/2;
	update(l, mid, idx*2, qg, v);
	update(mid+1, r, idx*2+1, qg, v);
	
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
	
	return;
}

void query(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr) {res += segtree[idx]; return;}
	
	int mid = (l+r)/2;
	query(l, mid, idx*2, ql, qr);
	query(mid+1, r, idx*2+1, ql, qr);
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
  	cin >> a;
  	arr[i] = a;
	if (v[a].empty()) update(1, n, 1, i, 1);  
	v[a].push(i);
  }
  
  for (int i = 1; i <= q; i++) {cin >> a >> b; s.insert({{a, b}, i});}
  
  for (int i = 1; i <= n; i++) {
  	if (s.empty()) break;
  	while ((*s.begin()).first.first == i) {
  		res = 0;
  		query(1, n, 1, (*s.begin()).first.first, (*s.begin()).first.second);
  		ans[(*s.begin()).second] = res;
  		
  		s.erase(*s.begin());
	  }
	
	v[arr[i]].pop();
	if (!v[arr[i]].empty()) {
		update(1, n, 1, v[arr[i]].front(), 1);
	}
  }
  
  for (int i = 1; i <= q; i++) cout << ans[i] << "\n";

  return 0;
}


