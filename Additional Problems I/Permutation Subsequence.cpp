#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
int n, m, seg[800003], p[800003], x[200003], res, resx, a[200003], b[200003], l[200003];
vector<int> ans;

void upd(int l, int r, int idx, int qx, int v) {
	if (l > qx || r < qx) return;
	if (l == qx && r == qx) {seg[idx] = v; p[idx] = l; return;}
	int mid = (l+r)/2;
	upd(l, mid, idx*2, qx, v); upd(mid+1, r, idx*2+1, qx, v);
	
	if (seg[idx*2] > seg[idx*2+1]) {seg[idx] = seg[idx*2]; p[idx] = p[idx*2];}
	else {seg[idx] = seg[idx*2+1]; p[idx] = p[idx*2+1];}
}

pair<int, int> que(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return {0, 0};
	if (l >= ql && r <= qr) return {seg[idx], p[idx]};
	int mid = (l+r)/2;
	pair<int, int> al = que(l, mid, idx*2, ql, qr);
	pair<int, int> ar = que(mid+1, r, idx*2+1, ql, qr);
	if (al.first > ar.first) return al;
	else return ar;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  REP(i, n) {cin >> a[i]; l[a[i]] = i;}
  REP(i, m) {
  	cin >> b[i];
  	if (b[i] <= n) {
  		pair<int, int> q = que(1, n, 1, 1, l[b[i]]-1);	
  		x[l[b[i]]] = q.second;
  		if (q.first+1 > res) {
  			res = q.first+1;
			resx = l[b[i]];	
		}
  		
		upd(1, n, 1, l[b[i]], q.first+1);	
	}
  }

  cout << res << "\n";
  while (resx) {
  	ans.push_back(a[resx]);
  	resx = x[resx];
  } reverse(ans.begin(), ans.end());
  for (auto i : ans) cout << i << " ";
  
  return 0;
}


