#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef pair<int, int> pii; typedef pair<ll, ll> pll;
#define testcases \
  int test_amount;        \
  cin >> test_amount;       \
  while (test_amount--)
const int mod = 1e9+7; const ll inf = 1e18;

int n, m, a, b, res[100003], cnt, x;
set<int> indeg[100003], outdeg[100003], s;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= m; i++) {cin >> a >> b; indeg[b].insert(a); outdeg[a].insert(b);}
  
  for (int i = 1; i <= n; i++) if (outdeg[i].empty()) s.insert(i);
  
  cnt = n;
  while (!s.empty()) {
  	x = *s.rbegin();
  	res[cnt--] = x;
  	
  	for (auto k : indeg[x]) {
  		outdeg[k].erase(x);
		if (outdeg[k].empty()) s.insert(k);	
	}
	
  	s.erase(x);
  }
  
  for (int i = 1; i <= n; i++) cout << res[i] << " ";

  return 0;
}


