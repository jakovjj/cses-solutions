#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[200003], t[200003], segtree[800003], segtreemx[800003], ans, x;
unordered_map<ll, ll> m;

void update(int l, int r, int idx, int pos) {
	if (pos == l && pos == r) {segtree[idx] = 1; return;}
	if (l > pos || r < pos) return;
	
	int mid = (l+r)/2;
	update(l, mid, idx*2, pos);
	update(mid+1, r, idx*2+1, pos);
	segtree[idx] = segtree[idx*2]+segtree[idx*2+1];
}

void query(int l, int r, int idx, int ql, int qr) {
	if (l >= ql && r <= qr) {ans += segtree[idx]; return;}
	if (l > qr || r < ql) return;
	
	int mid = (l+r)/2;
	query(l, mid, idx*2, ql, qr);
	query(mid+1, r, idx*2+1, ql, qr);
}

void updatemx(int l, int r, int idx, int pos) {
	if (pos == l && pos == r) {segtreemx[idx] = x; return;}
	if (l > pos || r < pos) return;
	
	int mid = (l+r)/2;
	updatemx(l, mid, idx*2, pos);
	updatemx(mid+1, r, idx*2+1, pos);
	segtreemx[idx] = max(segtreemx[idx*2], segtreemx[idx*2+1]);
}
 
void querymx(int l, int r, int idx, int ql, int qr) {
	if (l >= ql && r <= qr) {x = max(x, segtreemx[idx]); return;}
	if (l > qr || r < ql) return;
	
	int mid = (l+r)/2;
	querymx(l, mid, idx*2, ql, qr);
	querymx(mid+1, r, idx*2+1, ql, qr);
}


int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  // 1
  ans = 0; x = 0;
  for (int i = 1; i <= n; i++) m[a[i]] = i;
  for (int i = n; i >= 1; i--) {
  	query(1, n, 1, 1, m[i]-1);
  	update(1, n, 1, m[i]);
  }
  cout << ans << " ";
  
  // 2
  for (int i = 1; i <= n; i++) {t[i] = a[i]; m[a[i]] = i;}
  ans = 0;
  for (int i = 1; i <= n; i++) {
  	if (t[i] != i) {
  		t[m[i]] = t[i];
  		m[t[i]] = m[i];
		t[i] = i; m[i] = i;
		ans++;	
	}
  } 
  cout << ans << " ";
  
  // 3
  x = 0; ans = 0;
  for (int i = 1; i <= n; i++) m[a[i]] = i;
  for (int i = n; i >= 1; i--) {
  	x = 0; querymx(1, n, 1, m[i], n); x++;
  	ans = max(ans, x);
	updatemx(1, n, 1, m[i]);	
  }
  cout << n-ans << " ";

  
  // 4
  ans = 0;
  x = n;
  for (int i = n; i >= 1; i--) {
  	if (a[i] == x) {ans++; x--;}
  }
  
  cout << n-ans;

  return 0;
}

