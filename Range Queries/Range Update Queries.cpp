#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define mpair make_pair
#define MEMSET_MAX 0x7f
 
// !!!
 
ll n, q, t, segtree[800008], a, b, u;
 
void build(ll l, ll r, ll index) {
	if (l==r) {cin >> segtree[index]; return;}
	
	ll mid = (r+l)/2;
	build(l, mid, index*2);
	build(mid+1, r, index*2+1);
	
	return;
}
 
void query(ll qm, ll sum, ll l, ll r, ll index) {
 
	sum += segtree[index];
	if (l == r && l == qm) {cout << sum << "\n"; return;}
	
	ll mid = (r+l)/2;
	if(qm <= mid) {query(qm, sum, l, mid, index*2);}
	else {query(qm, sum, mid+1, r, index*2+1);}
	
	return;
}
 
void update (ll ql, ll qr, ll l, ll r, ll index) {
	
	if (l >= ql && r <= qr) {segtree[index]+=u; return;}
	if (r < ql || l > qr) {return;}
	
	int mid = (r+l)/2;
	update(ql, qr, l, mid, index*2);
	update(ql, qr, mid+1, r, index*2+1);
	
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  build(1, n, 1);
  
  for (int i = 0; i < q; i++) {
  	cin >> t;
  	if (t == 2) { //query
  		cin >> a;
  		query(a, 0, 1, n, 1);
	  }
	else { //update
		cin >> a >> b >> u;
		update(a, b, 1, n, 1);
	}
  }
  
  return 0;
}
 


