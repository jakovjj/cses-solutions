#include <bits/stdc++.h>
using namespace std;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;

int n, t, a, b, q;
ll segtree[800003][4], sum, res;
//0 -> sum
//1 -> prefmax

void build(int l, int r, int idx) {
	if (l == r) {cin >> segtree[idx][0]; segtree[idx][1] = max(segtree[idx][0], 0LL); return;}
	
	int mid = (l+r)/2;
	build(l, mid, idx*2);
	build(mid+1, r, idx*2+1);
	segtree[idx][0] = segtree[idx*2][0]+segtree[idx*2+1][0];
	segtree[idx][1] = max(segtree[idx*2][0]+segtree[idx*2+1][1], segtree[idx*2][1]);
	
	return;
}

void update(int l, int r, int idx, int qg, int v) {
	if (l > qg || r < qg) return;
	if (qg == l && qg == r) {
		segtree[idx][0] = v;
		segtree[idx][1] = max(segtree[idx][0], 0LL);
		return;
	}
	
	int mid = (l+r)/2;
	update(l, mid, idx*2, qg, v);
 	update(mid+1, r, idx*2+1, qg, v);
	segtree[idx][0] = segtree[idx*2][0]+segtree[idx*2+1][0];
	segtree[idx][1] = max(segtree[idx*2][0]+segtree[idx*2+1][1], segtree[idx*2][1]);
	
	return;
}

void query(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr) {
		res = max(res, sum+segtree[idx][1]);
		sum+=segtree[idx][0];
		return;
	}
	
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
  
  build(1, n, 1);
  for (int i = 0; i < q; i++) {
  	cin >> t >> a >> b;
  	if (t == 1) update(1, n, 1, a, b);
	if (t == 2) {
		res = 0;
		sum = 0;
		query(1, n, 1, a, b);
		
		cout << res << "\n";
	}
  }

  return 0;
}


