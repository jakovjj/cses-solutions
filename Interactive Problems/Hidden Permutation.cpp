#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<ll, ll> pll;
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
  
int n, res[1003];
string qans;
vector<int> merge(vector<int> v) {
	if (v.size() < 2) return v;
		
	vector<int> ans;
	vector<int> l, r;
	int mid = v.size()/2;
	for (int i = 0; i < v.size(); i++) {
		if (i < mid) l.push_back(v[i]);
		else r.push_back(v[i]);
	}
	
	l = merge(l);
	r = merge(r);
	int p = 0;
	
	for (int i = 0; i < l.size(); i++) {
		while (p < r.size()) {
			cout << "? " << l[i] << " " << r[p] << endl;
			cin >> qans;
			if (qans == "NO") ans.push_back(r[p++]);
			else break;
		}
		
		ans.push_back(l[i]);	
	}
	while (p < r.size()) ans.push_back(r[p++]);
	
	return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  vector<int> v;
  REP(i, n) v.push_back(i);
  v = merge(v);
  
  for (int i = 0; i < v.size(); i++) res[v[i]] = i+1;
  cout << "! "; REP(i, n) cout << res[i] << " ";
  return 0;
}
