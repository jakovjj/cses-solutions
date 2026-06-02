#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const int inf = 2147483647;

int n, x, res, a[200003];

struct node{
	node* on;
	node* off;
	node() {on = nullptr; off = nullptr;}
};

node* root;

void update(node* p, int cnt, int v) {
	if (cnt < 0) return;
	
	if ((v&(1<<cnt)) != 0) {
		if (p->on == nullptr) p->on = new node();
		update(p->on, cnt-1, v);
	}
	else {
		if (p->off == nullptr) p->off = new node();
		update(p->off, cnt-1, v);
	}
	
	return;
}

void query(node *p, int v, int cnt, int r) {
	if (cnt == -1) {res = max(r, res); return;}
	
	if ((v&(1<<cnt)) != 0 && p->off != nullptr) query(p->off, v, cnt-1, r+(1<<cnt));
	else if ((v&(1<<cnt)) == 0 && p->on != nullptr) query(p->on, v, cnt-1, r+(1<<cnt));
	else {
		if (p->on != nullptr) query(p->on, v, cnt-1, r);
		else if (p->off != nullptr) query(p->off, v, cnt-1, r);
	}
	
	return;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
 
  cin >> n;
  
  root = new node();
  
  for (int i = 1; i <= n; i++) cin >> a[i];
  update(root, 30, 0);
  
  for (int i = 1; i <= n; i++) {
  	x^=a[i];
  	query(root, x, 30, 0);
  	update(root, 30, x);
  }
  
  cout << res;

  return 0;
}


