#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// !!!

int n, q, segtree[800008], a, b, res;

void query(int ql, int qr, int l, int r, int index) {
	
	if (r < ql || l > qr) return;
	
	if (l >= ql && r <= qr) {
		if (res == -1) {res = segtree[index]; return;}
		res ^= segtree[index]; return;
	}
	
	int mid = l + (r-l)/2;
	query(ql, qr, l, mid, index*2);
	query(ql, qr, mid+1, r, index*2+1);
	
}

void build(int l, int r, int index) {
	
	if (l==r) {cin >> segtree[index]; return;}
	
	int mid = l + (r-l)/2;
	build(l, mid, index*2);
	build(mid+1, r, index*2+1);
	
	segtree[index] = segtree[index*2]^segtree[index*2+1];
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  
  build(1, n, 1);
  
  for (int i = 0; i < q; i++) {
  	cin >> a >> b;
  	res = -1;
  	query(a, b, 1, n, 1);
  	
  	cout << res << endl;
  }
  
  return 0;
}

//JJ

