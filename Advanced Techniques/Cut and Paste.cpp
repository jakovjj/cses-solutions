#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 1; i <= (n); i++)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
char c;

struct node{
	node *l, *r;
	int w, s; char v;
	node(char x) {l = nullptr; r = nullptr; w = rng(); v = x; s = 1;}
};

int cs(node *p) {return p ? p->s : 0;}

void merge(node *&root, node *l, node *r) {
	if (l == nullptr) {root = r; return;}
	if (r == nullptr) {root = l; return;}
	
	if (l->w <= r->w) {merge(l->r, l->r, r); root = l;}
	else {merge(r->l, l, r->l); root = r;}
	
	root->s = cs(root->l)+cs(root->r)+1;
}

void split(node *root, node *&l, node *&r, int idx) {
	if (!root) {l = nullptr; r = nullptr; return;}
	
	if (cs(root->l) < idx) {split(root->r, root->r, r, idx-1-cs(root->l)); l = root;}
	else {split(root->l, l, root->l, idx); r = root;}
	
	root->s = cs(root->l)+cs(root->r)+1;
}

void dfs(node *p) {
	if (!p) return;
	dfs(p->l); cout << p->v; dfs(p->r);
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
  	
  	merge(b, d, c);
  	merge(root, a, b);
  }
  
  dfs(root);
  return 0;
}
