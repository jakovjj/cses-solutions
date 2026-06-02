#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 1e9;

int n, pre[100003], in[100003], loc[100003], locpre[100003], p, tree_rt, segtree[400003];
int lc[100003], rc[100003];

void update(int l, int r, int idx, int q, int v) {
	if (l > q || r < q) return;
	if (q == l && q == r) {segtree[idx] = v; return;}
	
	int mid = (l+r)/2;
	update(l, mid, idx*2, q, v);
	update(mid+1, r, idx*2+1, q, v);
	
	segtree[idx] = min(segtree[idx*2], segtree[idx*2+1]);
	return;
}

int query(int l, int r, int idx, int ql, int qr) {
	if (l > qr || r < ql) return n;
	if (l >= ql && r <= qr) return segtree[idx];
	
	int mid = (l+r)/2;
	return min(query(l, mid, idx*2, ql, qr), query(mid+1, r, idx*2+1, ql, qr));
}

void solve(int l, int r, int parent, bool is_lc) {
	if (l > r) return;
	int res = query(1, n, 1, l, r);

	if (!tree_rt) tree_rt = pre[res];
	is_lc ? lc[parent] = pre[res] : rc[parent] = pre[res];
	
	solve(l, loc[pre[res]]-1, pre[res], 1);
	solve(loc[pre[res]]+1, r, pre[res], 0);
	
	return;
}

void dfs(int x) {
	if (!x) return;	
	dfs(lc[x]); dfs(rc[x]);
	cout << x << " ";
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {cin >> pre[i]; locpre[pre[i]] = i;}
  for (int i = 1; i <= n; i++) {cin >> in[i]; loc[in[i]] = i;}
  
  for (int i = 1; i <= n; i++) update(1, n, 1, i, locpre[in[i]]);
  
  solve(1, n, 0, 0);
  dfs(tree_rt);
  return 0;
}


