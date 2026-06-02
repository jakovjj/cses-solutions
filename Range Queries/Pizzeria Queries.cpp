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

int n, q, t, a, b, segtree[800003][3], res;

void build(int l, int r, int idx) {
	if (l == r) {
		cin >> segtree[idx][0];
		segtree[idx][1] = segtree[idx][0];
		segtree[idx][2] = segtree[idx][0];
		return;
	}
	
	int mid = (l+r)/2;
	build(l, mid, idx*2);
	build(mid+1, r, idx*2+1);
	
	int d = (r-l+1)/2;
	segtree[idx][0] = min(segtree[idx*2][2]+r-mid, segtree[idx*2+1][1]+mid-l+1);
	segtree[idx][1] = min(segtree[idx*2][1], segtree[idx][0]);
	segtree[idx][2] = min(segtree[idx*2+1][2], segtree[idx][0]);
	
	return;
}

void update(int l, int r, int idx, int qg, int v) {

	if (l > qg || r < qg) return;
	if (qg == l && qg == r) {
		segtree[idx][0] = v;
		segtree[idx][1] = segtree[idx][0];
		segtree[idx][2] = segtree[idx][0];
		return;
	}
	
	int mid = (l+r)/2;
	update(l, mid, idx*2, qg, v);
	update(mid+1, r, idx*2+1, qg, v);
	
	segtree[idx][0] = min(segtree[idx*2][2]+r-mid, segtree[idx*2+1][1]+mid-l+1);
	segtree[idx][1] = min(segtree[idx*2][1], segtree[idx][0]);
	segtree[idx][2] = min(segtree[idx*2+1][2], segtree[idx][0]);
	
	//cout << l << " " << r << " is " << segtree[idx][0] << " (" << segtree[idx][1] << "," << segtree[idx][2] << ")\n";
	
	return;
}

void query(int l, int r, int idx, int qg) {
	if (l > qg || r < qg) return;
	int mid = (l+r)/2;
	
	//cout << l << " " << r << " with " << qg << " -> " << segtree[idx][0] << "\n";
	
	if (qg <= mid) res = min(res, segtree[idx][0]-(qg-l));
	else res = min(res, segtree[idx][0]-(r-qg));
	
	res = min(res, segtree[idx][0]);
	
	if (l == r) return;	
	
	query(l, mid, idx*2, qg);
	query(mid+1, r, idx*2+1, qg);
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  build(1, n, 1);
  
  for (int i = 1; i <= q; i++) {
  	cin >> t;
  	if (t == 1) {
  		cin >> a >> b;
  		update(1, n, 1, a, b);
	  }
  	if (t == 2) {
  		cin >> a;
  		
  		res = inf;
  		query(1, n, 1, a);
  		cout << res << "\n";
	  }
  }

  return 0;
}


