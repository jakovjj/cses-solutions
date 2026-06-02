#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

ll n, a[200003], res, segtree[800003], q;
vector<pll> v;

bool cmp(pll x, pll y) {
	
	if (x.first > y.first) return 0;
	else if (x.first < y.first) return 1;
	else return (x.second > y.second);
	
}

void update (ll l, ll r, ll idx, ll qg, ll qv) {
	if (l > qg || r < qg) return;
	if (qg == l && qg == r) {segtree[idx] = qv; return;}
	
	ll mid = (l+r)/2;
	update(l, mid, idx*2, qg, qv);
	update(mid+1, r, idx*2+1, qg, qv);
	
	segtree[idx]=segtree[idx*2]+segtree[idx*2+1];
	
	return;
}

void query(ll l, ll r, ll idx, ll qr) {
	if (l > qr) return;
	if (r <= qr) {
		q=q+segtree[idx]%mod;
		return;
	}
	
	ll mid = (l+r)/2;
	query(l, mid, idx*2, qr);
	query(mid+1, r, idx*2+1, qr);
	
	return;
} 

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {cin >> a[i]; v.push_back({a[i], i});}
  
  sort(v.begin(), v.end(), cmp);
  
  for (auto i : v) {
  	q = 1;
  	query(1, n, 1, i.second-1);
  	q%=mod;
  	
  	res = (res+q)%mod;
  	update(1, n, 1, i.second, q);
  }
  
  cout << res;
	
  return 0;
}


