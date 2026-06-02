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

ll n, segtree[800003], lzadd[800003], lzset[800003], t, a, b, x, res, q;

void build(ll l, ll r, ll idx) {
	if (l == r) {cin >> segtree[idx]; return;}
	
	ll mid = (l+r)/2;
	build(l, mid, idx*2);
	build(mid+1, r, idx*2+1);
	
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
	return;
}

void update(ll l, ll r, ll idx, ll ql, ll qr) {
	if (lzset[idx] != 0) {
		if (l != r) {lzset[idx*2] = lzset[idx]; lzset[idx*2+1] = lzset[idx]; lzadd[idx*2] = 0; lzadd[idx*2+1] = 0;}
		segtree[idx] = lzset[idx]*(r-l+1);
		lzset[idx] = 0;
	}
	
	if (lzadd[idx] != 0) {
		if (l != r) {lzadd[idx*2] += lzadd[idx]; lzadd[idx*2+1] += lzadd[idx];}
		segtree[idx] += lzadd[idx]*(r-l+1);
		lzadd[idx] = 0;
	}
	
	if (l > qr || r < ql) return;
	
	if (l >= ql && r <= qr) {
		if (t == 1) {segtree[idx] += x*(r-l+1); if (l != r) {lzadd[idx*2] += x; lzadd[idx*2+1] += x;}}
		if (t == 2) {segtree[idx] = x*(r-l+1); if (l != r) {lzset[idx*2] = x; lzset[idx*2+1] = x; lzadd[idx*2] = 0; lzadd[idx*2+1] = 0;}}
		if (t == 3) {res += segtree[idx];}
		return;
	}
		
	
	ll mid = (l+r)/2;
	update(l, mid, idx*2, ql, qr);
	update(mid+1, r, idx*2+1, ql, qr);
	
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
	
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
  		cin >> a >> b >> x;
  		update(1, n, 1, a, b);
	  }
	if (t == 2) {
		cin >> a >> b >> x;
		update(1, n, 1, a, b);
	}
	if (t == 3) {
		cin >> a >> b;
		res = 0;
		update(1, n, 1, a, b);
		cout << res << "\n";
	}
  }

  return 0;
}


