#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;
 
ll n, xo, yo, xt, yt, res;
vector<pair<int, pii>> s;
 
struct node {
	node* l;
	node* r;
	int v;
	node () {l = nullptr; r = nullptr; v = 0;}
};
 
node* root;
 
void update(node* p, int l, int r, int idx, int qn, int upd) {	
	if (l > qn || r < qn) return;
	if (qn == l && qn == r) {p->v += upd; return;}
	
	if (p->l == nullptr) p->l = new node();
	if (p->r == nullptr) p->r = new node();
	
	int mid = (l+r)/2;
	update(p->l, l, mid, idx*2, qn, upd);
	update(p->r, mid+1, r, idx*2+1, qn, upd);
	p->v = p->l->v + p->r->v;
	
	return;
}
 
void query(node* p, int l, int r, int idx, int ql, int qr) {
	if (l >= ql && r <= qr) {res+=p->v; return;}
	if (l > qr || r < ql) return;
	
	if (p->l == nullptr) p->l = new node();
	if (p->r == nullptr) p->r = new node();
	
	int mid = (l+r)/2;
	query(p->l, l, mid, idx*2, ql, qr);
	query(p->r, mid+1, r, idx*2+1, ql, qr);
	
	return;
}
 
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  root = new node();
  
  for (int i = 1; i <= n; i++) {
  	cin >> xo >> yo >> xt >> yt;
  	xo+=1000000; yo+=1000000; xt+=1000000; yt+=1000000;
  	
  	if (xo == xt) { //vertical
  		s.push_back({max(yo, yt), {xo, -1000000000}});
  		s.push_back({min(yo, yt), {xo, 1000000000}});
	  }
	else s.push_back({yo, {xo, xt}});
  }
  
  sort(s.begin(), s.end());
  for (auto i : s) {  	
  	if (i.second.second == -1000000000 || i.second.second == 1000000000) update(root, 0, 2000000, 1, i.second.first, i.second.second/1000000000);
	else query(root, 0, 2000000, 1, min(i.second.first, i.second.second), max(i.second.first, i.second.second));
  }
  
  cout << res;
 
  return 0;
}

