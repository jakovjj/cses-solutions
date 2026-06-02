#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define REP(i, n) for(int i = 1; i <= (n); i++)
const int inf = 1e9;
int n, q, x[200003], ans[200003], a, b, c[200003], d[200003], seg[600003], t;
vector<pii> v[200003];
vector<int> comp;
unordered_map<int, int> m;
 
void upd(int l, int r, int idx, int qx) {
	if (l > qx || r < qx) return;
	if (l == qx && r == qx) {seg[idx]++; return;}
	int mid = (l+r)/2;
	upd(l, mid, idx*2, qx); upd(mid+1, r, idx*2+1, qx);
	seg[idx] = seg[idx*2]+seg[idx*2+1];
}
int que(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return 0;
	if (l >= ql && r <= qr) return seg[idx];
	int mid = (l+r)/2;
	return que(l, mid, idx*2, ql, qr)+que(mid+1, r, idx*2+1, ql, qr);
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> q;
  REP(i, n) {cin >> x[i]; comp.push_back(x[i]);}
  comp.push_back(inf); sort(comp.begin(), comp.end());
  for (auto i : comp) m[i] = ++t; 
  
  REP(i, q) {
  	cin >> a >> b >> c[i] >> d[i];
  	v[a-1].push_back({i, -1});
  	v[b].push_back({i, 1});
  }
 
  for (int i = 0; i <= n; i++) {
  	if (i > 0) upd(1, n, 1, m[x[i]]);
  	for (auto k : v[i]) {
	  	int idx = k.first;
        c[idx] = *lower_bound(comp.begin(), comp.end(), c[idx]);
        d[idx] = *--upper_bound(comp.begin(), comp.end(), d[idx]);
		ans[idx] += k.second*que(1, n, 1, m[c[idx]], m[d[idx]]);
  	}	
  }
  
  REP(i, q) cout << ans[i] << "\n";
  return 0;
}
