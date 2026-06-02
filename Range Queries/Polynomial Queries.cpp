#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, q, t, a, b, segtree[800003], lz[800003], lzoff[800003], x, temp;
ll polymath(ll l, ll r) {return (r-l+1)*(r-l+2)/2;}

void update(ll l, ll r, ll idx, ll pos, ll v) {
	if (l == pos && r == pos) {segtree[idx] = v; return;}
	if (l > pos || r < pos) return;
	ll mid = (l+r)/2;
	update(l, mid, idx*2, pos, v); update(mid+1, r, idx*2+1, pos, v);
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
}

void polyupdate(ll l, ll r, ll idx, ll ql, ll qr) {
	ll mid = (l+r)/2;
	if (lz[idx] && l != r) {
		lz[idx*2] += lz[idx]; lz[idx*2+1] += lz[idx];
		lzoff[idx*2] += lzoff[idx]; lzoff[idx*2+1] += lzoff[idx]+lz[idx]*(mid-l+1);
		
		segtree[idx*2] += lz[idx]*polymath(l, mid)+lzoff[idx]*(mid-l+1);
		segtree[idx*2+1] += lz[idx]*polymath(mid+1, r)+(lzoff[idx]+lz[idx]*(mid-l+1))*(r-(mid+1)+1);
		
		lz[idx] = 0; lzoff[idx] = 0;
		segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
	}
	
	if (l >= ql && r <= qr) {segtree[idx] += polymath(l, r)+(l-ql)*(r-l+1); lz[idx]++; lzoff[idx] += l-ql; return;}
	if (l > qr || r < ql) return;
	
	polyupdate(l, mid, idx*2, ql, qr); polyupdate(mid+1, r, idx*2+1, ql, qr);
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
}

ll query(ll l, ll r, ll idx, ll ql, ll qr) {
	ll mid = (l+r)/2;
	if (lz[idx] && l != r) {
		lz[idx*2] += lz[idx]; lz[idx*2+1] += lz[idx];
		lzoff[idx*2] += lzoff[idx]; lzoff[idx*2+1] += lzoff[idx]+lz[idx]*(mid-l+1);
		
		segtree[idx*2] += lz[idx]*polymath(l, mid)+lzoff[idx]*(mid-l+1);
		segtree[idx*2+1] += lz[idx]*polymath(mid+1, r)+(lzoff[idx]+lz[idx]*(mid-l+1))*(r-(mid+1)+1);
		
		lz[idx] = 0; lzoff[idx] = 0;
		segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
	}
	
	if (l > qr || r < ql) return 0LL;
	if (l >= ql && r <= qr) return segtree[idx];
	
	return query(l, mid, idx*2, ql, qr)+query(mid+1, r, idx*2+1, ql, qr);
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  for (ll i = 1; i <= n; i++) {cin >> x; update(1, n, 1, i, x);}
  
  for (int i = 1; i <= q; i++) {
    cin >> t >> a >> b;
  	if (t == 1) polyupdate(1, n, 1, a, b);
	if (t == 2) cout << query(1, n, 1, a, b) << "\n";
  }

  return 0;
}
