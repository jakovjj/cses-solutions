#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)

int n, m, q, res, un[100003], tmr;
vector<pair<int, int>> seg[500003];
vector<pair<int,int>> rb;

int find(int x) {
	if (x == un[x]) return x;
	return find(un[x]);
}

void unite(int x, int y) {	
	x = find(x); y = find(y);
	if (un[x] == un[y]) return;
	if (x < y) swap(x, y);
		
	res--;
	rb.push_back({x, y});
	un[y] = un[x];
}

void upd(int l, int r, int idx, int ql, int qr, pair<int, int> x) {
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr) {seg[idx].push_back(x); return;}
	upd(l, (l+r)/2, idx*2, ql, qr, x); upd((l+r)/2+1, r, idx*2+1, ql, qr, x);
}

void walk(int l, int r, int idx) {
	if (l >= tmr) return;
	int sz = rb.size();
	for (auto i : seg[idx]) unite(i.first, i.second);
	
	if (l == r) cout << res << " ";
	else {
		walk(l, (l+r)/2, idx*2);
		walk((l+r)/2+1, r, idx*2+1);
	}
	
	while (rb.size() > sz) {
		int x = rb.back().first; int y = rb.back().second;
		rb.pop_back();
		res++;
		un[y] = y;
	}
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin >> n >> m >> q;
  REP(i, n) un[i] = i;
  res = n;
  map<pair<int, int>, int> p;
  tmr = 1;
  
  int a, b, t;
  REP(i, m) {cin >> a >> b; p[{a, b}] = 1;}
  REP(i, q) {
  	tmr++;
	cin >> t >> a >> b;
  	if (t == 1) {p[{a, b}] = tmr; p[{b, a}] = tmr;}
	if (t == 2) {
		upd(1, 2+q, 1, p[{a, b}], tmr-1, {a, b});
		p[{a, b}] = 0; p[{b, a}] = 0;
	}
  }
  
  tmr++;
  for (auto i : p) {
  	if (i.second) upd(1, 2+q, 1, i.second, tmr-1, i.first);
	p[{i.first}] = 0;
	p[{i.first.second, i.first.first}] = 0;	
  }
  
  walk(1, 2+q, 1);
  return 0;
}
