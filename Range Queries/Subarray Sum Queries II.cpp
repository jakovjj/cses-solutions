#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
struct node {ll pref, suff, sum, res; node *l, *r;};
ll n, q, a[200003];
node *x, *root;

void push(node *p) {p->l = new node(); p->r = new node();}
node *merge(node *l, node *r) {
	node *w = new node();
	w->sum = l->sum+r->sum; w->l = l; w->r = r;
	w->res = max({l->res, r->res, l->suff+r->pref, 0ll});
	w->pref = max({l->pref, l->sum+r->pref, 0ll});
	w->suff = max({r->suff, r->sum+l->suff, 0ll});
	return w;
}
node *build(node *p, int l, int r) {
	if (l == r) {
		p->sum = a[l];
		p->pref = max(0ll, a[l]); p->suff = max(0ll, a[l]);
		p->res = max(0ll, a[l]);
		return p;
	}
		
	int mid = (l+r)/2; push(p);
	p->l = build(p->l, l, mid); p->r = build(p->r, mid+1, r);
	p = merge(p->l, p->r);
	return p;
}
void que(node *p, int l, int r, int ql, int qr) {
	if (l > qr || r < ql) return;
	if (l >= ql && r <= qr) {x = merge(x, p); return;}
	
	int mid = (l+r)/2;
	que(p->l, l, mid, ql, qr); que(p->r, mid+1, r, ql, qr);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  
  root = new node();
  REP(i, n) cin >> a[i];
  root = build(root, 1, n);

  REP(i, q) {
  	int l, r; cin >> l >> r;
	x = new node(); que(root, 1, n, l, r);
  	cout << x->res << "\n";
  }
  
  return 0;
}
