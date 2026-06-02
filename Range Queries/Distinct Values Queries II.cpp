#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
 
int n, q, a[200003], seg[800003];
unordered_map<int, set<int>> m;
 
void upd(int l, int r, int idx, int qx, int qv) {
	if (l > qx || r < qx) return;
	if (l == qx && r == qx) {seg[idx] = qv; return;}
	
	int mid = (l+r)/2;
	upd(l, mid, idx*2, qx, qv); upd(mid+1, r, idx*2+1, qx, qv);
	seg[idx] = max(seg[idx*2], seg[idx*2+1]);
}
 
int que(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return seg[idx];	
	
	int mid = (l+r)/2;
	return max(que(l, mid, idx*2, ql, qr), que(mid+1, r, idx*2+1, ql, qr));
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> q;
  
  REP(i, n) {
  	cin >> a[i];
  	if (m[a[i]].empty()) m[a[i]].insert(0);
  	upd(1, n, 1, i, *m[a[i]].rbegin());
  	m[a[i]].insert(i);
  }
  
  REP(i, q) {
  	int t, l, r;
	  
	cin >> t >> l >> r;
	if (t == 1) {
		auto it = m[a[l]].upper_bound(l);
		if (it != m[a[l]].end()) upd(1, n, 1, *it, *(--m[a[l]].lower_bound(l)));
		
		m[a[l]].erase(l); a[l] = r;
		if (m[a[l]].empty()) m[a[l]].insert(0);
		m[a[l]].insert(l);
		
		auto it2 = m[a[l]].upper_bound(l); 
		if (it2 != m[a[l]].end()) upd(1, n, 1, *it2, l);
		
		upd(1, n, 1, l, *(--m[a[l]].lower_bound(l)));
	}
	else cout << ((l > que(1, n, 1, l, r)) ? "YES\n" : "NO\n");		
  }
 
  return 0;
}

