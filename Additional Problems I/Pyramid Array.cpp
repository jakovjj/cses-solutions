#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7; const int inf = 2147483647;
 
ll n, a[200003], x, segtree[800003], res;
vector<pll> sweep;
 
void update(ll l, ll r, ll idx, ll qg) {
	if (qg == l && qg == r) {segtree[idx] = 1; return;}
	if (l > qg || r < qg) return;
	
	ll mid = (l+r)/2;
	update(l, mid, idx*2, qg);
	update(mid+1, r, idx*2+1, qg);
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
}
 
ll query (ll l, ll r, ll idx, ll ql, ll qr) {
	if (l >= ql && r <= qr) return segtree[idx];
	if (l > qr || r < ql) return 0;
	
	ll mid = (l+r)/2;
	return query(l, mid, idx*2, ql, qr)+query(mid+1, r, idx*2+1, ql, qr);
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  for (int i = 1; i <= n; i++) {cin >> a[i]; sweep.push_back({a[i], i});}
  sort(sweep.begin(), sweep.end());
  
  update(1, n, 1, sweep[sweep.size()-1].second);
  for (int i = sweep.size()-2; i >= 0; i--) {
  	res += min(query(1, n, 1, 1, sweep[i].second-1), query(1, n, 1, sweep[i].second+1, n));  	
  	update(1, n, 1, sweep[i].second);
  }
  
  cout << res;
 
  return 0;
}

