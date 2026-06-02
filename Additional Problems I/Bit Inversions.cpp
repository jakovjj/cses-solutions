#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//reference -> o_set.insert(x), *(o_set.find_by_order(i)), o_set.order_of_key(i), ordered_set<int> o_set

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mpair make_pair
#define elif else if
#define MEMSET_MAX 0x7f
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7;
const int inf = 2147483647;

struct node {
	bool lbit, rbit;
	node* l;
	node* r;
	int lseq, rseq;
	int res, sum;
};

string s;
int a[200003], n, q, x;
node* root;

void update(node* p, int l, int r, int idx, int qg, int v) {
	if (l > qg || r < qg) return;
	
	if (qg == l && qg == r) {
		
		(v == 2) ? p->lbit = !p->lbit : p->lbit = v;
		(v == 2) ? p->rbit = !p->rbit : p->rbit = v;
		p->res = 1;
		p->lseq = 1;
		p->rseq = 1;
		p->sum = 1;
		
		//cout << "updating node " << l << "-" << r << " to " << p->lbit << "\n";
		
		return;
	}
	
	if (p->l == nullptr) p->l = new node();
	if (p->r == nullptr) p->r = new node();
	
	int mid = (l+r)/2;
	update(p->l, l, mid, idx*2, qg, v);
	update(p->r, mid+1, r, idx*2+1, qg, v);
	
	p->lbit = p->l->lbit;
	p->rbit = p->r->rbit;
	p->sum = p->l->sum+p->r->sum;
	
	p->lseq = p->l->lseq;
	if (p->l->lseq == p->l->sum && p->l->rbit == p->r->lbit) p->lseq = p->l->sum+p->r->lseq;
	
	p->rseq = p->r->rseq;
	if (p->r->rseq == p->r->sum && p->l->rbit == p->r->lbit) p->rseq = p->r->sum+p->l->rseq;
	
	p->res = max(p->l->res, p->r->res);
	if (p->r->lbit == p->l->rbit) p->res = max(p->res, p->l->rseq+p->r->lseq);
	
	//cout << "node " << l << " " << r << " has res " << p->res << " ; stats " << p->l->rseq << " " << p->r->lseq << ", bits at center are " << p->l->rbit << " " << p->r->lbit << "\n"; 
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> s;
  n = s.size();
  for (int i = 0; i <= n; i++) a[i+1] = s[i]-'0';
  
  root = new node();
  
  for (int i = 1; i <= n; i++) update(root, 1, n, 1, i, a[i]);
  
  cin >> q;
  for (int i = 1; i <= q; i++) {
  	cin >> x;
  	update(root, 1, n, 1, x, 2); // 2 -> invert
  	cout << root->res << " ";
  }

  return 0;
}

