#include <bits/stdc++.h>
using namespace std;
 
int n, q, xa, ya, xb, yb, t, segtree[2103][2103], idxy, idxl, idxr, prefsum[1003][1003]; //for each row, up to each column
char c;
bool mat[1003][1003];
 
void update_x(int idx, int l, int r) {
	if (xa > r || xa < l) return;
	segtree[idxy][idx] += mat[xa][ya]*2-1;
	if (l == r) return;
	
	int mid = (l+r)/2;
	update_x(idx*2, l, mid);
	update_x(idx*2+1, mid+1, r);
	return;
}
 
void update(int idx, int l, int r) {
	if (ya > r || ya < l) return;
	idxy = idx; update_x(1, 1, n);
	if (l == r) return;
	
	int mid = (l+r)/2;
	update(idx*2, l, mid);
	update(idx*2+1, mid+1, r);
	return;
}
 
int query_x(int idx, int l, int r) {
	if (l > xb || r < xa) return 0;
	if (l >= xa && r <= xb) {return segtree[idxy][idx];}
	
	int mid = (l+r)/2;
	return query_x(idx*2, l, mid)+query_x(idx*2+1, mid+1, r);
}

int query(int idx, int l, int r) {
	if (l > yb || r < ya) return 0;
	if (l >= ya && r <= yb) {idxy = idx; return query_x(1, 1, n);}
	
	int mid = (l+r)/2;
	return query(idx*2, l, mid)+query(idx*2+1, mid+1, r);
}

void build_x(int idx, int l, int r) {
	if (l == r) {segtree[idxy][idx] = prefsum[l][idxr]-prefsum[l][idxl-1]; return;}
	int mid = (l+r)/2;
	build_x(idx*2, l, mid);
	build_x(idx*2+1, mid+1, r);
	segtree[idxy][idx] = segtree[idxy][idx*2]+segtree[idxy][idx*2+1];
	return;
}

void build(int idx, int l, int r) {
	idxy = idx; idxl = l; idxr = r; build_x(1, 1, n);
	if (l == r) return;
	int mid = (l+r)/2;
	build(idx*2, l, mid);
	build(idx*2+1, mid+1, r);
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n >> q;
  for (xa = 1; xa <= n; xa++) for (ya = 1; ya <= n; ya++) {cin >> c; if (c == '*') {mat[xa][ya] = 1; prefsum[xa][ya]++;}}
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) prefsum[i][j] += prefsum[i][j-1];
  
  build(1, 1, n);
  
  for (int i = 1; i <= q; i++) {
  	cin >> t >> xa >> ya;
  	if (t == 1) {mat[xa][ya] = !mat[xa][ya]; update(1, 1, n);}
  	else {cin >> xb >> yb; cout << query(1, 1, n) << "\n";}
  }
 
  return 0;
}

