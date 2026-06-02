#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1e9+7;
const int inf = 2147483647;
 
int n, q, a, b, type;
int segment_tree[800003]; //segment tree 
 
void update(int loc, int nv, int l, int r, int index) {
	
	if (l==r) {segment_tree[index] = nv; return;}
	
	int mid = (l+r)/2;
	
	if(loc <= mid) {update(loc, nv, l, mid, index*2);}
	else {update(loc, nv, mid+1, r, index*2+1);}
	
	segment_tree[index] = min(segment_tree[index*2], segment_tree[index*2+1]);
	
	return;
}
 
int query(int ql, int qr, int l, int r, int index) {
	
	//cout << "Debug: " << ql << " " << qr << " " << l << " " << r << " " << index  << " " << segment_tree[index] << endl;
	if (l >= ql && r <= qr) {
		//cout << "Return with index" << endl;
		return segment_tree[index];
	}
	if (l > qr || r < ql) {return inf; }
	
	int res = inf;
	int mid = l + (r-l)/2;
	
	res = min(res, query(ql, qr, l, mid, 2*index));
	res = min(res, query(ql, qr, mid+1, r, 2*index+1));
	
	return res;
}

void build(int index, int l, int r) {
	if (l == r) {cin >> segment_tree[index]; return;}
	
	int mid = (r+l)/2;
	build(2*index, l, mid);
	build(2*index+1, mid+1, r);
	
	segment_tree[index] = min(segment_tree[index*2], segment_tree[index*2+1]);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  
  cin >> n >> q;
  build(1, 1, n);
  
  for (int i = 0; i < q; i++) {
  	cin >> type >> a >> b;
  	
  	if (type == 1) update(a, b, 1, n, 1);
  	else if (type == 2) cout << query(a, b, 1, n, 1) << endl;}
  
  return 0;
}
 

 



