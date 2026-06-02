#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//o_set.order_of_key(i); o_set.find_by_order(i);
const int mod = 1e9+7; const int inf = 2147483647;

ll n, m, segtree[800003][4], a, b;
//segtree[idx][0] -> res
//segtree[idx][1] -> includes l
//segtree[idx][2] -> includes r
//segtree[idx][3] -> totalsum

void build(ll l, ll r, ll idx) {
	
	if (l == r) {
		cin >> segtree[idx][3];
		segtree[idx][0] = segtree[idx][3];
		segtree[idx][1] = segtree[idx][3];
		segtree[idx][2] = segtree[idx][3]; 
		
		segtree[idx][1] = max(segtree[idx][1], 0LL);
		segtree[idx][2] = max(segtree[idx][2], 0LL);
		return;
	}
	
	ll mid = (l+r)/2;
	build(l, mid, idx*2);
	build(mid+1, r, idx*2+1);
	
	segtree[idx][0] = max(max(segtree[idx*2][0], segtree[idx*2+1][0]), segtree[idx*2][2]+segtree[idx*2+1][1]);
	
	segtree[idx][1] = max(segtree[idx*2][1], segtree[idx*2][3]+segtree[idx*2+1][1]);
	segtree[idx][2] = max(segtree[idx*2+1][2], segtree[idx*2+1][3]+segtree[idx*2][2]);
	
	segtree[idx][3] = segtree[idx*2][3]+segtree[idx*2+1][3];
	
	segtree[idx][1] = max(segtree[idx][1], 0LL);
	segtree[idx][2] = max(segtree[idx][2], 0LL);
	
	return;
}

void update(ll l, ll r, ll idx, ll q) {
	
	if (l > q || r < q) return;
	
	if (l == r) {
		segtree[idx][0] = b;
		segtree[idx][1] = b;
		segtree[idx][2] = b;
		segtree[idx][3] = b;
		
		segtree[idx][1] = max(segtree[idx][1], 0LL);
		segtree[idx][2] = max(segtree[idx][2], 0LL);
		
		return;
	}
	
	ll mid = (l+r)/2;
	update(l, mid, idx*2, q);
	update(mid+1, r, idx*2+1, q);
	
	segtree[idx][0] = max(max(segtree[idx*2][0], segtree[idx*2+1][0]), segtree[idx*2][2]+segtree[idx*2+1][1]);
	
	segtree[idx][1] = max(segtree[idx*2][1], segtree[idx*2][3]+segtree[idx*2+1][1]);
	segtree[idx][2] = max(segtree[idx*2+1][2], segtree[idx*2+1][3]+segtree[idx*2][2]);
	
	segtree[idx][3] = segtree[idx*2][3]+segtree[idx*2+1][3];
	
	segtree[idx][1] = max(segtree[idx][1], 0LL);
	segtree[idx][2] = max(segtree[idx][2], 0LL);
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  build(1, n, 1);
  
  for (int i = 0; i < m; i++) {
  	cin >> a >> b;
  	update(1, n, 1, a);
  	
  	cout << max(0LL, segtree[1][0]) << "\n";
  }

  return 0;
}


