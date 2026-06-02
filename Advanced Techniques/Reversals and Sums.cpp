#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, m;
struct node{
	node *l, *r;
	ll v, w, sum, s;
	bool rev;
	node(int x) {s = 1; v = x; sum = v; w = rng(); rev = 0; l = nullptr; r = nullptr;}
};

ll cs(node *p) {return p ? p->s : 0;}
ll csum(node *p) {return p ? p->sum : 0;}

void pushrev(node *p) {
	if (!p->rev) return;
	p->rev = 0; swap(p->l, p->r);
	if (p->l) p->l->rev = !p->l->rev;
	if (p->r) p->r->rev = !p->r->rev;
}

void merge(node *&root, node *l, node *r) {
	if (!l) {root = r; return;}
	if (!r) {root = l; return;}
	
	pushrev(l); pushrev(r);
	if (l->w <= r->w) {merge(l->r, l->r, r); root = l;}
	else {merge(r->l, l, r->l); root = r;}
	
	root->s = 1+cs(root->l)+cs(root->r);
	root->sum = root->v+csum(root->l)+csum(root->r);
}

void split(node *root, node *&l, node *&r, int idx) {
	if (!root) {l = nullptr; r = nullptr; return;}
	
	pushrev(root);
	if (cs(root->l) < idx) {split(root->r, root->r, r, idx-1-cs(root->l)); l = root;}
	else {split(root->l, l, root->l, idx); r = root;}
	
	root->s = 1+cs(root->l)+cs(root->r);
	root->sum = root->v+csum(root->l)+csum(root->r);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  node* root = nullptr; int x;
  REP(i, n) {cin >> x; merge(root, root, new node(x));}
  
  REP(i, m) {
  	int t, l, r;
  	cin >> t >> l >> r;
  	
  	node *a, *b, *c, *d;
  	split(root, a, b, l-1);
  	split(b, c, d, r-l+1);
  		
  	if (t == 1) {
  		c->rev = !c->rev;
  		merge(b, c, d);
  		merge(root, a, b);
	}
	if (t == 2) {
		cout << c->sum << "\n";
		merge(b, c, d);
		merge(root, a, b);
	}
  }

  return 0;
}
