#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m; char c;

struct node{
	node *l, *r;
	bool rev; char v;
	int w, s;
	node(char x) {
		l = nullptr; r = nullptr; 
		rev = 0; v = x; w = rng(); s = 1;
	}
};

int cs(node *p) {return p ? p->s : 0;}
void pushrev(node *p) {
	if (!p->rev) return;
	
	p->rev = 0;
	swap(p->l, p->r);
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
}

void split(node *root, node *&l, node *&r, int idx) {
	if (!root) {l = nullptr; r = nullptr; return;}
	
	pushrev(root);
	if (cs(root->l) < idx) {split(root->r, root->r, r, idx-1-cs(root->l)); l = root;}
	else {split(root->l, l, root->l, idx); r = root;}
	
	root->s = 1+cs(root->l)+cs(root->r);
}

void dfs(node *p, bool x) {
	if (!p) return;
	pushrev(p);
	dfs(p->l, x);
	if (x) cout << p->v;
	dfs(p->r, x);
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  
  node* root = nullptr;
  REP(i, n) {cin >> c; merge(root, root, new node(c));}
  
  REP(i, m) {
  	int l, r;
  	cin >> l >> r;
  	
	node *a, *b, *c, *d;
	split(root, a, b, l-1);
	split(b, c, d, r-l+1);
	
	c->rev = !(c->rev);
	merge(b, c, d);
	merge(root, a, b);
  }
  
  dfs(root, 1);
  return 0;
}

