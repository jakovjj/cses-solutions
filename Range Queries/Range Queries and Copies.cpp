#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll; typedef pair<double, double> pdd;
#define mpair make_pair
#define mtuple make_tuple
#define elif else if
#define MEMSET_MAX 0x7f
//(0x3f is larger than 1e9)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
//getline(cin >> ws, s)

//s.upper_bound(2); -> set upper_bound
//upper_bound(v.begin(), v.end(), 35); -> std upper_bound
template<class T> using pqmax = priority_queue< T, vector<T>, greater<T> >;
template<class T> using pqmin = priority_queue<T>;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
//ordered_set<int> o_set; o_set.insert(i); o_set.order_of_key(i); o_set.find_by_order(i); o_multiset.erase(o_multiset.find_by_order(o_multiset.order_of_key(i)))
const int mod = 1e9+7;
const int inf = 2147483647;
// !!!

struct node {
	ll v;
	node* l;
	node* r;
	node() {v=0; l = nullptr; r = nullptr;}
	node(node *p) {
		if (p==nullptr) {v = 0; l = nullptr; r = nullptr;}
		else {
			v = p->v;
			l = p->l;
			r = p->r;
		}
	}
	
};

ll getval(node *p) {
	if (p==nullptr) return 0;
	else return p->v;
}

node *build(node *p, ll l, ll r) {

	if (l == r && p != nullptr) {ll a; cin >> a; p -> v = a;}
	else {
		if (p->r == nullptr) p->r = new node();
		if (p->l == nullptr) p->l = new node();
		
		ll mid = (l+r)/2;
		build(p->l, l, mid);
		build(p->r, mid+1, r);
		
		p->v = getval(p->l)+getval(p->r);
	}	
	
	//cout << "there is val " << p->v << " at " << l << " " << r << endl;
	return p;
}

node *update(node *p, ll l, ll r, ll qm, ll num) {
	
	if (qm > r || qm < l) return p;
	node* pnew = new node(p);
	if (qm == l && qm == r) {pnew->v=num;
		//cout << "node " << l << " " << r << " " << pnew->v << endl;
		return pnew;}
	ll mid = (l+r)/2;
		
	pnew->l = update(p->l, l, mid, qm, num);
	pnew->r = update(p->r, mid+1, r, qm, num);
	pnew->v = getval(pnew->l)+getval(pnew->r);
	//cout << "node " << l << " " << r << " " << pnew->v << " " << p << " " << pnew << endl;
	
	return pnew;
}

ll query(node *p, ll l, ll r, ll ql, ll qr) {
	if (p==nullptr || l > qr || r < ql) return 0;
	
	//cout << "querying " << l << " " << r << " with " << ql << " " << qr << " " << p << endl;
	if (l >= ql && r <= qr) return p->v;
	
	ll mid = (l+r)/2;
	ll res = query(p->l, l, mid, ql, qr)+query(p->r, mid+1, r, ql, qr);
	
	return res;
}

node *root[200003];
ll n, q, a, k, c, x, t;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> q;
  
  root[0] = new node();
  build(root[0], 1, n);
  
  c = 0;
  for (int i = 0; i < q; i++) {
  	cin >> t;
  	if (t == 1) { //update
  		cin >> k >> a >> x;
  		root[k-1] = update(root[k-1], 1, n, a, x);
	}
	else if (t == 2) { //query
		cin >> k >> a >> x;
		cout << query(root[k-1], 1, n, a, x) << "\n";
	}
	else { //copy
		cin >> k;
		c++;
		root[c] = new node(root[k-1]);	
	}
  }

  return 0;
}

