#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int inc = 1000001;
const int m = 2000002;
 
ll n, res, sum, xa, xb, ya, yb, updv, l;
struct line {int x; int ylo; int yhi; int v;} temp;
 
struct node {
	node* l;
	node* r;
	ll v, cnt, lzadd;
	node () {l = nullptr; r = nullptr; v = 0; cnt = 1; lzadd = 0;}
};
 
node* root;
vector<line> sweep;
bool sortline(line x, line y) {return (y.x > x.x);}

void build(node *p, ll l, ll r) {
	if (l == r) return;
	
	ll mid = (l+r)/2;
	if (p->l == nullptr) p->l = new node();
	if (p->r == nullptr) p->r = new node();
	
	build(p->l, l, mid);
	build(p->r, mid+1, r);
	
	p->cnt = p->l->cnt+p->r->cnt;
}

void update(node *p, ll l, ll r, ll ql, ll qr) {
	if (l > qr || r < ql) return;	
	if (l >= ql && r <= qr) {
		p->lzadd += updv;
		p->v += updv;
		//cout << "updating " << l << "-" << r << " to " << p->v << "\n";		
		return;
	}
	
	if (p->l == nullptr && l != r) p->l = new node();
	if (p->r == nullptr && l != r) p->r = new node();
	if (p->lzadd && l != r) {
		p->l->lzadd += p->lzadd;
		p->r->lzadd += p->lzadd;
		p->l->v += p->lzadd;
		p->r->v += p->lzadd;
		p->lzadd = 0;
	}
	
	ll mid = (l+r)/2;
	update(p->l, l, mid, ql, qr);
	update(p->r, mid+1, r, ql, qr);
	
	if (p->l->v < p->r->v) {p->v = p->l->v; p->cnt = p->l->cnt;}
	else if (p->r->v < p->l->v) {p->v=p->r->v; p->cnt = p->r->cnt;}
	else {p->v = p->l->v; p->cnt = p->l->cnt+p->r->cnt;}
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  root = new node();
  
  for (int i = 1; i <= n; i++) {
   cin >> xa >> ya >> xb >> yb;
   xa += inc; xb += inc; ya += inc; yb += inc;
   temp.ylo = min(ya, yb);
   temp.yhi = max(ya, yb);
   temp.x = xa; temp.v = 1; sweep.push_back(temp);
   temp.x = xb; temp.v = -1; sweep.push_back(temp);
  }
   
  sort(sweep.begin(), sweep.end(), sortline);
  l = sweep[0].x;
  
  build(root, 1, m);
  
  for (int i = 0; i < n*2; i++) {
  	while (i != n*2-1 && sweep[i+1].x == sweep[i].x) {updv = sweep[i].v; update(root, 1, m, sweep[i].ylo, sweep[i].yhi-1); i++;}
	updv = sweep[i].v; update(root, 1, m, sweep[i].ylo, sweep[i].yhi-1);
  	
  	//cout << "update value was " << updv << "\n";
  	
  	res += sum*(sweep[i].x-l);
  	sum = m-root->cnt;
	l = sweep[i].x;
	//cout << "res so far is " << res << "\n";
	//cout << "sum is " << sum << ", root is " << root->cnt << " " << root->v << "\n";
  }
 
  cout << res;
  return 0;
}

