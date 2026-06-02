#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

ll n, x[200003];
pll fi, se;
set<pll> s;
vector<pll> res, temp;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {cin >> x[i]; if(x[i]) s.insert({x[i], i});}
  
  while (s.size()) {
  	fi = *s.rbegin(); s.erase(fi);
  	
  	while (fi.first && !s.empty()) {
  		fi.first--;
  		se = *s.rbegin(); s.erase(se); se.first--;
  		if (se.first) temp.push_back(se);
  		
  		res.push_back({fi.second, se.second});
	}
	
	if (fi.first) {cout << "IMPOSSIBLE\n"; return 0;}
	
	for (auto i : temp) s.insert(i);
	temp.clear();
  }
  
  cout << res.size() << "\n";
  for (auto i : res) cout << i.first << " " << i.second << "\n";

  return 0;
}


